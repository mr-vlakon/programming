#include <iostream>
#include <boost/asio.hpp>

#include "Common.hpp"
#include "json.hpp"

using boost::asio::ip::tcp;

// Отправка сообщения на сервер по шаблону.
void SendMessage(
    tcp::socket& aSocket,
    const std::string& aId,
    const std::string& aRequestType,
    const std::string& aMessage)
{
    nlohmann::json req;
    req["UserId"] = aId;
    req["ReqType"] = aRequestType;
    req["Message"] = aMessage;
    std::string request = req.dump();
    boost::asio::write(aSocket, boost::asio::buffer(request, request.size()));
}

// Возвращает строку с ответом сервера на последний запрос.
std::string ReadMessage(tcp::socket& aSocket)
{
    boost::asio::streambuf b;
    boost::asio::read_until(aSocket, b, "\0");
    std::istream is(&b);
    std::string line(std::istreambuf_iterator<char>(is), {});
    return line;
}

// "Создаём" пользователя, получаем его ID.
std::string ProcessRegistration(tcp::socket& aSocket)
{
    std::string name;
    std::cout << "Hello! Enter your name: ";
    std::cin >> name;

    // Для регистрации Id не нужен, заполним его нулём
    SendMessage(aSocket, "0", Requests::Registration, name);
    return ReadMessage(aSocket);
}

int main()
{
    try
    {
        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        s.connect(*iterator);

        // Мы предполагаем, что для идентификации пользователя будет использоваться ID.
        // Тут мы "регистрируем" пользователя - отправляем на сервер имя, а сервер возвращает нам ID.
        // Этот ID далее используется при отправке запросов.
        std::string my_id = ProcessRegistration(s);
	
	std::cout << "my_id = " << my_id << std::endl;

        while (true)
        {
            // Тут реализовано "бесконечное" меню.
            std::cout << "Menu:\n"
                         "1) Hello Request\n"
			 "2) Sale request\n"
			 "3) Purchase request\n"
			 "4) View all your active trade orders\n"
			 "5) View all your completed transactions\n"
			 "6) Show balance\n"
                         "7) Exit\n"
                         << std::endl;

            short menu_option_num;
            std::cin >> menu_option_num;
            switch (menu_option_num)
            {
                case 1:
                {
                    // Для примера того, как может выглядить взаимодействие с сервером
                    // реализован один единственный метод - Hello.
                    // Этот метод получает от сервера приветствие с именем клиента,
                    // отправляя серверу id, полученный при регистрации.
                    	SendMessage(s, my_id, Requests::Hello, "");
                    	std::cout << ReadMessage(s);
                    	break;
                }
		case 2:
		{

			unsigned dollarsAmount = 0;
			double price = 0.0; 
			std::cout << "How many dollars do you want to sell? " << std::endl;
			std::cout << "Enter the amount of dollars: ";
			std::cin >> dollarsAmount;
			std::cout << "At what price per dollar do you want to sell?" << std::endl;
			std::cout << "Enter price: ";
			std::cin >> price;
			std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
			SendMessage(s, my_id, Requests::Sale, message);
			std::cout << ReadMessage(s);
			break;
		}
		case 3: 
		{

			unsigned dollarsAmount = 0;
			double price = 0.0; 
			std::cout << "How many dollars do you want to buy? " << std::endl;
			std::cout << "Enter the amount of dollars: ";
			std::cin >> dollarsAmount;
			std::cout << "At what price per dollar do you want to buy?" << std::endl;
			std::cout << "Enter price: ";
			std::cin >> price;
			std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
			SendMessage(s, my_id, Requests::Purchase, message);
			std::cout << ReadMessage(s);
			break;
		}
		case 4: 
		{
			SendMessage(s, my_id, Requests::ViewActive, "");
			std::istringstream is(ReadMessage(s));
			std::string tmp;
			while (is >> tmp) {
				std::cout << tmp << std::endl;
			}
			//std::cout << ReadMessage(s);
			break;
		}
		case 5:
		{
			SendMessage(s, my_id, Requests::ViewCompleted, "");
			std::istringstream is(ReadMessage(s));
			std::string tmp;
			while (is >> tmp) {
				std::cout << tmp << std::endl;
			}
			//std::cout << ReadMessage(s);
			break;
		}
		case 6:
		{
			SendMessage(s, my_id, Requests::Balance, "");
			std::cout << ReadMessage(s);
			break;
		}
                case 7:
                {
                	exit(0);
                    	break;
                }
                default:
                {
                    	std::cout << "Unknown menu option\n" << std::endl;
                }
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
