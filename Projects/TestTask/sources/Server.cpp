#include <cstdlib>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include "json.hpp"
#include "Common.hpp"
#include <queue>

using boost::asio::ip::tcp;

static size_t idOrder = 0;
static const double epsilon = 0.000001;

struct TradeOrder {
	size_t idOfOrder = 0;
	std::string side;
	std::string idOfUser;

	
	unsigned long amount = 0UL;
	double price = 0.0;
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
    std::string RegisterNewUser(const std::string& aUserName, const std::string &login, const std::string &password) {
	loginName[login] = aUserName;
	balances[login] = 0;
	loginPassword[login] = password;
	return login;
    }

    double& getBalance(const std::string &id) {
	return balances[id];
    }

    void putOrder(const std::string &ord, const std::string &type, const std::string &id) {	
	std::istringstream is(ord);
	std::string am;
	is >> am;
	TradeOrder to;
	to.amount = std::stoul(am); 
	std::string pr;
	is >> pr;
	to.price = std::stod(pr);
	to.side = type;
	to.idOfOrder = idOrder++;

	to.initialOrder = am + "-" + pr + "-" + type;
	to.idOfUser = id;
	if (to.side == "Sale") {
		pqOrderSell.push(to);
	} else {
		pqOrderBuy.push(to);
	}

	usersActiveOrders[id][to.idOfOrder] = to;
	serve();
    }

    void changeActiveOrder(const std::string &idUser, const size_t &idOfOrder, unsigned long &amount) {
	usersActiveOrders[idUser][idOfOrder].amount = amount;
    }


    void serve() {
	if (pqOrderSell.empty()) return;
	if (pqOrderBuy.empty()) return;

	auto topSell = pqOrderSell.top();
	auto topBuy = pqOrderBuy.top();
	if (topSell.price > topBuy.price)
		return;

	while ((topSell.price - epsilon) <= (topBuy.price + epsilon)) {
		auto idSellerUser = topSell.idOfUser;
		auto idBuyerUser = topBuy.idOfUser;
		if (topSell.amount >= topBuy.amount) {
			pqOrderBuy.pop();
			pqOrderSell.pop();
			topSell.amount -= topBuy.amount;
			auto tmpBal = topBuy.amount * topBuy.price;
			topBuy.amount = 0;
			getBalance(idSellerUser) += tmpBal;
			getBalance(idBuyerUser) -= tmpBal;
			
			usersCompletedOrders[idBuyerUser].push_back(topBuy);

			changeActiveOrder(idSellerUser, topSell.idOfOrder, topSell.amount);
			
			
			cancelActiveOrder(topBuy.idOfOrder, topBuy.idOfUser); 
			
			if (topSell.amount != 0) {
				pqOrderSell.push(topSell);
			} else {
				
				cancelActiveOrder(topSell.idOfOrder, topSell.idOfUser); 
				usersCompletedOrders[idSellerUser].push_back(topSell);
			}

		} else {
			pqOrderSell.pop();
			pqOrderBuy.pop();
			auto tmpBal = topSell.amount * topBuy.price;
			topBuy.amount -= topSell.amount;
			topSell.amount = 0;		
			getBalance(idSellerUser) += tmpBal;
			getBalance(idBuyerUser) -= tmpBal;
			
			usersCompletedOrders[idSellerUser].push_back(topSell);
			
			changeActiveOrder(idBuyerUser, topBuy.idOfOrder, topBuy.amount);
			
			cancelActiveOrder(topSell.idOfOrder, topSell.idOfUser); 

			if (topBuy.amount != 0) {
				pqOrderBuy.push(topBuy);
			}
		}
		if (pqOrderBuy.empty()) return;
		if (pqOrderSell.empty()) return;
		topSell = pqOrderSell.top();
		topBuy = pqOrderBuy.top();
	}
    }

    void cancelActiveOrder(const size_t &idOfOrder, const std::string &idOfUser) {
	usersActiveOrders[idOfUser].erase(idOfOrder);
    }

    void getActiveOrders(const std::string &id, std::vector<std::string> &v) {
	for (const auto &e: usersActiveOrders[id]) {
		std::string tmp = std::to_string(e.second.amount) + "-" + std::to_string(e.second.price) + "-" 
			+ e.second.side;
		v.push_back(tmp);
	}
    }

    void getCompletedOrders(const std::string &id, std::vector<std::string> &v) {
	for (const auto &e: usersCompletedOrders[id]) {
		v.push_back(e.initialOrder);
	}
    }

    // Запрос имени клиента по ID
    std::string GetUserName(const std::string& aUserId)
    {
        const auto userIt = loginName.find(aUserId);
        if (userIt == loginName.cend()) 
	{
            return "Error! Unknown User";
        } 
	else 
	{
            return userIt->second;
        }
    }

    std::string findLogin(const std::string &s) {
	auto it = loginPassword.find(s);
	if (it == loginPassword.cend()) {
		return "Succes, such login doesn't exist yet";
	} else {
		return "Exist";
	}
    }

    std::string CheckIfLoginPasswordCorrect(const std::string &l, const std::string &p) {
	auto it = loginPassword.find(l);
	if (it == loginPassword.cend()) {
		return "Permission denied!";
	}
	if (it->second != p) {
		return "Permission denied!";
	}

	return l;
    }

    void changeFlag() {
    	flg = 1;
    }

    std::string getFlag() {
	return std::to_string(flg);
    }

    void reset() {
	pqOrderSell = std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareSell>();
	pqOrderBuy = std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareBuy>();
	
	usersCompletedOrders.clear();
	usersActiveOrders.clear();

	loginName.clear();

	balances.clear();

	loginPassword.clear();
    }

private:

    int flg = 0;
    std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareSell> pqOrderSell;
    std::priority_queue<TradeOrder, std::deque<TradeOrder>, CompareBuy> pqOrderBuy;


    std::unordered_map<std::string, std::vector<TradeOrder> > usersCompletedOrders;

    std::unordered_map<std::string, std::map<size_t, TradeOrder> > usersActiveOrders;
    std::unordered_map<std::string, std::string> loginName;

    std::unordered_map<std::string, double> balances;

    std::unordered_map<std::string, std::string> loginPassword;

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
 
	    if (reqType == Requests::EnterToAccount) 
	    {

		std::string s(j["Message"]);
		std::istringstream is(s);
		std::string login = j["UserId"];
		std::string password;
		is >> password;
		reply = GetCore().CheckIfLoginPasswordCorrect(login, password);

	    }
	    else if(reqType == Requests::CheckIfLoginExist) 
	    {

		std::string s(j["Message"]);
		std::istringstream is(s);
		std::string login;
		is >> login;
		reply = GetCore().findLogin(login);

	    } 
	    else if (reqType == Requests::CreateAnAccount) 
	    {

		std::string s(j["Message"]);
		std::istringstream is(s);
		std::string login = j["UserId"];
		std::string password;
		is >> password;

		std::string name;
		is >> name;

		reply = GetCore().RegisterNewUser(name, login, password);

	    }
            else if (reqType == Requests::Hello)
            {

                reply = "Hello, " + GetCore().GetUserName(j["UserId"]) + "!\n";

            } 
	    else if (reqType == Requests::Sale) 
	    {

		GetCore().putOrder(j["Message"], std::string("Sale"), j["UserId"]);
		reply = "Your Sale Order has accepted!\n";

	    } 
	    else if (reqType == Requests::Purchase) 
	    {

		GetCore().putOrder(j["Message"], std::string("Purchase"), j["UserId"]);
		reply = "Your Purchase Order has accepted!\n";

	    } 
	    else if (reqType == Requests::ViewActive) 
	    {

		std::vector<std::string> v;
		reply = "";
		GetCore().getActiveOrders(j["UserId"], v);
		for (const auto &e: v) {
			reply += e + " ";
		}
		reply += "!\n";

	    } 
	    else if (reqType == Requests::ViewCompleted) 
	    {

		std::vector<std::string> v;
		reply = "";
		GetCore().getCompletedOrders(j["UserId"], v);
		for (const auto &e: v) {
			reply += e + " ";
		}
		reply += "!\n";

	    } 
	    else if (reqType == Requests::Balance) 
	    {

		reply = "Your balance is " + std::to_string(GetCore().getBalance(j["UserId"])) + "!\n";
	    
	    }
	    else if (reqType == Requests::ChangeFlag) 
	    {
		GetCore().changeFlag();		
	    }
	    else if (reqType == Requests::getValueOfFlag) 
	    {
		reply = GetCore().getFlag();
	    }
	    else if (reqType == Requests::Reset) 
	    {
	    	GetCore().reset();
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
