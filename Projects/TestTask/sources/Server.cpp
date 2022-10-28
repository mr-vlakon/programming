#include <cstdlib>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include "json.hpp"
#include "Common.hpp"
#include <queue>

using boost::asio::ip::tcp;

static size_t idOrder = 0;

struct TradeOrder {
	size_t idOfOrder = 0;
	std::string side;
	size_t idOfUser = 0;
	long long amount = 0LL;
	double price = 0.0;
	bool status = true;
	std::string initialOrder;
};


class CompareSell { 
public:
	bool operator() (const TradeOrder &lhs, const TradeOrder &rhs) {
		return (lhs.price > rhs.price) ? true : (lhs.price < rhs.price) ? 
			false : (lhs.idOfOrder > rhs.idOfOrder) ? true : false;

	}
};

class CompareBuy { 
public:
	bool operator() (const TradeOrder &lhs, const TradeOrder &rhs) {
		return (lhs.price < rhs.price) ? true : (lhs.price > rhs.price) ? 
			false : (lhs.idOfOrder > rhs.idOfOrder) ? true : false;
	}
};

class Core
{
public:
    std::string RegisterNewUser(const std::string& aUserName) {
        size_t newUserId = mUsers.size();
        mUsers[newUserId] = aUserName;
	balances[newUserId] = 0;
        return std::to_string(newUserId);
    }

    double& getBalance(const std::string &id) {
	return balances[std::stoll(id)];
    }

    void putOrder(const std::string &ord, const std::string &type, const std::string &id) {	
	std::istringstream is(ord);
	std::string am;
	is >> am;
	TradeOrder to;
	to.amount = std::stoll(am); 
	std::string pr;
	is >> pr;
	to.price = std::stod(pr);
	to.side = type;
	to.idOfOrder = idOrder++;
	to.status = true;

	to.initialOrder = am + "-" + pr + "-" + type;
	to.idOfUser = std::stoi(id);
	if (to.side == "Sale") {
		pqOrderSell.push(to);
	} else {
		pqOrderBuy.push(to);
	}
	usersActiveOrder[stoi(id)].push_back(to);
	serve(to);

    }

    void changeActiveOrder(const size_t &id, const size_t &idOfOrder, long long &amount) {
	auto beg = usersActiveOrder[id].begin();
	while (beg != usersActiveOrder[id].cend()) {
		if ( beg->idOfOrder == idOfOrder) {
			beg->amount = amount;
			break;
		}
		++beg;
	}
    }


    void serve(const TradeOrder & to) {
	if (pqOrderSell.empty()) return;
	if (pqOrderBuy.empty()) return;

	auto topSell = pqOrderSell.top();
	auto topBuy = pqOrderBuy.top();
	if (topSell.price > topBuy.price)
		return;
	//pqOrderSell.pop();
	//pqOrderBuy.pop();

	while (topSell.price <= topBuy.price) {
		auto idSellerUser = topSell.idOfUser;
		auto idBuyerUser = topBuy.idOfUser;
		if (topSell.amount >= topBuy.amount) {
			pqOrderBuy.pop();
			pqOrderSell.pop();
			topSell.amount -= topBuy.amount;
			auto tmpBal = topBuy.amount * topBuy.price;
			topBuy.amount = 0;
			getBalance(std::to_string(idSellerUser)) += tmpBal;
			getBalance(std::to_string(idBuyerUser)) -= tmpBal;
			
			usersCompletedOrder[idBuyerUser].push_back(topBuy);

			changeActiveOrder(idSellerUser, topSell.idOfOrder, topSell.amount);
			
			cancelActiveOrder(topBuy.initialOrder, std::to_string(topBuy.idOfUser));
			
			if (topSell.amount != 0) {
				//pqOrderSell.pop();
				pqOrderSell.push(topSell);
			} else {
				cancelActiveOrder(topSell.initialOrder, std::to_string(topSell.idOfUser));
				usersCompletedOrder[idSellerUser].push_back(topSell);
			}

		} else {
			pqOrderSell.pop();
			pqOrderBuy.pop();
			auto tmpBal = topSell.amount * topBuy.price;
			topBuy.amount -= topSell.amount;
			topSell.amount = 0;		
			getBalance(std::to_string(idSellerUser)) += tmpBal;
			getBalance(std::to_string(idBuyerUser)) -= tmpBal;
			
			usersCompletedOrder[idSellerUser].push_back(topSell);
			
			changeActiveOrder(idBuyerUser, topBuy.idOfOrder, topBuy.amount);
			
			cancelActiveOrder(topSell.initialOrder, std::to_string(topSell.idOfUser));
			
			if (topBuy.amount != 0) {
				pqOrderBuy.push(topBuy);
			}
		}
		if (pqOrderBuy.empty()) return;
		if (pqOrderSell.empty()) return;
		topSell = pqOrderSell.top();
		topBuy = pqOrderBuy.top();
		//pqOrderBuy.pop();
		//pqOrderSell.pop();
	}
    }

    void cancelActiveOrder(const std::string &order, const std::string &id) {
	auto beg = usersActiveOrder[std::stoi(id)].begin();
	while (beg != usersActiveOrder[std::stoi(id)].cend()) {
		if ( beg->initialOrder == order) {
			break;
		}
		++beg;
	}
	if (beg != usersActiveOrder[std::stoi(id)].cend())
		usersActiveOrder[std::stoi(id)].erase(beg);
    }

    void getActiveOrder(const std::string &id, std::vector<std::string> &v) {
	for (const auto &e: usersActiveOrder[std::stoi(id)]) {
		std::string tmp = std::to_string(e.amount) + "-" + std::to_string(e.price) + "-" + e.side;
		v.push_back(tmp);
	}
    }

    void getCompletedOrder(const std::string &id, std::vector<std::string> &v) {
	for (const auto &e: usersCompletedOrder[std::stoi(id)]) {
		v.push_back(e.initialOrder);
	}
    }

    // Запрос имени клиента по ID
    std::string GetUserName(const std::string& aUserId)
    {
        const auto userIt = mUsers.find(std::stoi(aUserId));
        if (userIt == mUsers.cend()) {
            return "Error! Unknown User";
        } else {
            return userIt->second;
        }
    }

private:
    // <UserId, UserName>

    std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareSell> pqOrderSell;
    std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareBuy> pqOrderBuy;

    std::unordered_map<size_t, std::vector<TradeOrder> > usersCompletedOrder;
    std::unordered_map<size_t, std::vector<TradeOrder> > usersActiveOrder;

    std::unordered_map<size_t, std::string> mUsers;
    std::unordered_map<size_t, double> balances;

};

Core& GetCore();

Core& GetCore()
{
    static Core core;
    return core;
}

class session
{
public:
    session(boost::asio::io_service& io_service)
        : socket_(io_service)
    {
    }

    tcp::socket& socket()
    {
        return socket_;
    }

    void start()
    {
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
            boost::bind(&session::handle_read, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
    }

    // Обработка полученного сообщения.
    void handle_read(const boost::system::error_code& error,
        size_t bytes_transferred)
    {
        if (!error)
        {
            data_[bytes_transferred] = '\0';

            // Парсим json, который пришёл нам в сообщении.
            auto j = nlohmann::json::parse(data_);
	    auto reqType = j["ReqType"];

            std::string reply = "Error! Unknown request type";

            if (reqType == Requests::Registration)
            {
                // Это реквест на регистрацию пользователя.
                // Добавляем нового пользователя и возвращаем его ID.
                reply = GetCore().RegisterNewUser(j["Message"]);
            }
            else if (reqType == Requests::Hello)
            {
                // Это реквест на приветствие.
                // Находим имя пользователя по ID и приветствуем его по имени.
                reply = "Hello, " + GetCore().GetUserName(j["UserId"]) + "!\n";
            } else if (reqType == Requests::Sale) {

		GetCore().putOrder(j["Message"], std::string("Sale"), j["UserId"]);
		reply = "Your Sale Order has accepted!\n";

	    } else if (reqType == Requests::Purchase) {

		GetCore().putOrder(j["Message"], std::string("Purchase"), j["UserId"]);
		reply = "Your Purchase Order has accepted!\n";

	    } else if (reqType == Requests::ViewActive) {
		std::vector<std::string> v;
		reply = "";
		GetCore().getActiveOrder(j["UserId"], v);
		for (const auto &e: v) {
			reply += e + " ";
		}
		reply += "!\n";

	    } else if (reqType == Requests::ViewCompleted) {
		std::vector<std::string> v;
		reply = "";
		GetCore().getCompletedOrder(j["UserId"], v);
		for (const auto &e: v) {
			reply += e + " ";
		}
		reply += "!\n";
	    } else if (reqType == Requests::Balance) {
		reply = "Your balance is " + std::to_string(GetCore().getBalance(j["UserId"])) + "!\n";
	    }

            boost::asio::async_write(socket_,
                boost::asio::buffer(reply, reply.size()),
                boost::bind(&session::handle_write, this,
                    boost::asio::placeholders::error));
        }
        else
        {
            delete this;
        }
    }

    void handle_write(const boost::system::error_code& error)
    {
        if (!error)
        {
            socket_.async_read_some(boost::asio::buffer(data_, max_length),
                boost::bind(&session::handle_read, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
        }
        else
        {
            delete this;
        }
    }

private:
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};

class server
{
public:
    server(boost::asio::io_service& io_service)
        : io_service_(io_service),
        acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
    {
        std::cout << "Server started! Listen " << port << " port" << std::endl;

        session* new_session = new session(io_service_);
        acceptor_.async_accept(new_session->socket(),
            boost::bind(&server::handle_accept, this, new_session,
                boost::asio::placeholders::error));
    }

    void handle_accept(session* new_session,
        const boost::system::error_code& error)
    {
        if (!error)
        {
            new_session->start();
            new_session = new session(io_service_);
            acceptor_.async_accept(new_session->socket(),
                boost::bind(&server::handle_accept, this, new_session,
                    boost::asio::placeholders::error));
        }
        else
        {
            delete new_session;
        }
    }

private:
    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
};

int main()
{
    try
    {
        boost::asio::io_service io_service;
        static Core core;

        server s(io_service);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
