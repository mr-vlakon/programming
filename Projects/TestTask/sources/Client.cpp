#include <iostream>
#include <boost/asio.hpp>
#include <cassert>

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

// Test method findLogin
void TestMethodFindLoginIfSuchLoginNotExist() {
	std::cout << "START TestMethodFindLoginIfSuchLoginNotExist()" << std::endl;
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "ABC";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");
	
	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodFindLoginIfSuchLoginNotExist() with success" << std::endl;
}

// Test method findLogin
void TestMethodFindLoginIfSuchLoginExist() {
	std::cout << "START TestMethodFindLoginIfSuchLoginExist()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string password = "1234";
	std::string name = "Petr";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);


	login = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	answer = ReadMessage(s);
	assert(answer != "Succes, such login doesn't exist yet");
	assert(answer == "Exist");


	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodFindLoginIfSuchLoginExist() with success" << std::endl;
}

// Test method GetUserName
void TestMethodGetUserNameWithOnePerson() {

	std::cout << "START TestMethodGetUserNameWithOnePerson()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string loginFirst = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginFirst);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordFirst = "1234";
	std::string nameFirst = "Arkadii";
       	SendMessage(s, loginFirst, Requests::CreateAnAccount, passwordFirst + " " + nameFirst);
	answer = ReadMessage(s);
	assert(answer == loginFirst);



        SendMessage(s, loginFirst, Requests::Hello, "");
       	assert(ReadMessage(s) == ("Hello, " + nameFirst + "!\n") );

	
	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodGetUserNameWithOnePerson() with success" << std::endl;

}

// Test method GetUserName
void TestMethodGetUserNameWithTwoPersons() {

	std::cout << "START TestMethodGetUserNameWithTwoPersons()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string loginFirst = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginFirst);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordFirst = "1234";
	std::string nameFirst = "Vladimir";
       	SendMessage(s, loginFirst, Requests::CreateAnAccount, passwordFirst + " " + nameFirst);
	answer = ReadMessage(s);
	assert(answer == loginFirst);



        SendMessage(s, loginFirst, Requests::Hello, "");
       	assert(ReadMessage(s) == ("Hello, " + nameFirst + "!\n") );


	std::string loginSecond = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginSecond);
	answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordSecond = "123";
	std::string nameSecond = "Vasiliy";
       	SendMessage(s, loginSecond, Requests::CreateAnAccount, passwordSecond + " " + nameSecond);
	answer = ReadMessage(s);
	assert(answer == loginSecond);

        SendMessage(s, loginSecond, Requests::Hello, "");
       	assert(ReadMessage(s) == ("Hello, " + nameSecond + "!\n")) ;
	
	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodGetUserNameWithTwoPersons() with success" << std::endl;

}


void TestMethodRegisterNewUserOneUser() {

	std::cout << "START TestMethodRegisterNewUserOneUser()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "C";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string password = "123456";
	std::string name = "Tanya";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodRegisterNewUserOneUser() with success" << std::endl;

}

void TestMethodRegisterNewUserTwoUsersWithTheSameLogin() {

	std::cout << "START TestMethodRegisterNewUserTwoUsersWithTheSameLogin()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string loginFirst = "R";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginFirst);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordFirst = "123";
	std::string nameFirst = "Igor";
       	SendMessage(s, loginFirst, Requests::CreateAnAccount, passwordFirst + " " + nameFirst);
	answer = ReadMessage(s);
	assert(answer == loginFirst);


	//For EXAMPLE IF SUCH LOGIN EXIST
	std::string loginSecond = "R";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginSecond);
	answer = ReadMessage(s);
	assert(answer == "Exist");

	// Дальше не регистрируем второго пользователя с тем же логином, т.к он не прошел проверку CheckIfLoginExist


	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodRegisterNewUserTwoUsersWithTheSameLogin() with success" << std::endl;

}


void TestMethodRegisterNewUserTwoUsersWithTheDifferentLogin() {

	std::cout << "START TestMethodRegisterNewUserTwoUsersWithTheDifferentLogin()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string loginFirst = "R";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginFirst);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordFirst = "123";
	std::string nameFirst = "Igor";
       	SendMessage(s, loginFirst, Requests::CreateAnAccount, passwordFirst + " " + nameFirst);
	answer = ReadMessage(s);
	assert(answer == loginFirst);


	std::string loginSecond = "E";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginSecond);
	answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordSecond = "12345";

	std::string nameSecond = "Maks";
       	SendMessage(s, loginSecond, Requests::CreateAnAccount, passwordSecond + " " + nameSecond);
	answer = ReadMessage(s);
	assert(answer == loginSecond);



	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodRegisterNewUserTwoUsersWithTheDifferentLogin() with success" << std::endl;

}


void TestMethodRegisterNewUserThreeUsers() {

	std::cout << "START TestMethodRegisterNewUserThreeUsers()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string loginFirst = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginFirst);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordFirst = "1234";
	std::string nameFirst = "Helen";
       	SendMessage(s, loginFirst, Requests::CreateAnAccount, passwordFirst + " " + nameFirst);
	answer = ReadMessage(s);
	assert(answer == loginFirst);


	std::string loginSecond = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginSecond);
	answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordSecond = "abc";

	std::string nameSecond = "Vladimir";
       	SendMessage(s, loginSecond, Requests::CreateAnAccount, passwordSecond + " " + nameSecond);
	answer = ReadMessage(s);
	assert(answer == loginSecond);


	std::string loginThird = "C";
       	SendMessage(s, "", Requests::CheckIfLoginExist, loginThird);
	answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string passwordThird = "abcdef";

	std::string nameThird = "Petr";
       	SendMessage(s, loginThird, Requests::CreateAnAccount, passwordThird + " " + nameThird);
	answer = ReadMessage(s);
	assert(answer == loginThird);

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodRegisterNewUserThreeUsers() with success" << std::endl;

}

// Test Method CheckIfLoginPasswordCorrect

void TestMethodCheckIfLoginPasswordCorrectIfCorrectWithOneUser() {

	std::cout << "START TestMethodCheckIfLoginPasswordCorrectIfCorrectWithOneUser()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string password = "123456";
	std::string name = "Karl";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);


        SendMessage(s, login, Requests::EnterToAccount, password);
	answer = ReadMessage(s);
	assert(answer == login);

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodCheckIfLoginPasswordCorrectIfCorrectWithOneUser() with success" << std::endl;

}


void TestMethodCheckIfLoginPasswordCorrectIfNotCorrectWithOneUser() {

	std::cout << "START TestMethodCheckIfLoginPasswordCorrectIfNotCorrectWithOneUser()" << std::endl;
	
	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string password = "abcd";
	std::string name = "John";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);


	std::string incorrectPassword = "123";
        SendMessage(s, login, Requests::EnterToAccount, incorrectPassword);
	answer = ReadMessage(s);
	assert(answer == "Permission denied!");

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodCheckIfLoginPasswordCorrectIfNotCorrectWithOneUser() with success" << std::endl;

}


// Test Method putOrder
void TestMethodPutOrderSaleForOneUser() {
	std::cout << "START TestMethodPutOrderSaleForOneUser()" << std::endl;

	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");

	std::string password = "abcd";
	std::string name = "Mike";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);

	unsigned dollarsAmount = 100;
	double price = 60.5;
	std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
	SendMessage(s, login, Requests::Sale, message);
	answer = ReadMessage(s);
	assert(answer == "Your Sale Order has accepted!\n");


	//Test GetBalance
	SendMessage(s, login, Requests::Balance, "");
	answer = ReadMessage(s);
	double balance = 0.0;
	assert(answer == ("Your balance is " + std::to_string(balance) + "!\n"));

	
	//Test GetAcitveOrders
	SendMessage(s, login, Requests::ViewActive, "");
	answer = ReadMessage(s);
	assert(answer == (std::to_string(dollarsAmount) + "-" + std::to_string(price) + "-" + 
				std::string("Sale ") + std::string("!\n")));

	//Test GetCompletedOrders
	SendMessage(s, login, Requests::ViewCompleted, "");
	answer = ReadMessage(s);
	assert(answer == std::string("!\n"));

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodPutOrderSaleForOneUser() with success" << std::endl;
}


void TestMethodPutOrderBuyForOneUser() {
	std::cout << "START TestMethodPutOrderBuyForOneUser()" << std::endl;

	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");

	std::string password = "abcdef";
	std::string name = "Michel";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);

	unsigned dollarsAmount = 200;
	double price = 61.5;
	std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
	SendMessage(s, login, Requests::Purchase, message);
	answer = ReadMessage(s);
	assert(answer == "Your Purchase Order has accepted!\n");

	//Test GetBalance
	SendMessage(s, login, Requests::Balance, "");
	answer = ReadMessage(s);
	double balance = 0.0;
	assert(answer == ("Your balance is " + std::to_string(balance) + "!\n"));

	//Test GetAcitveOrders
	SendMessage(s, login, Requests::ViewActive, "");
	answer = ReadMessage(s);
	assert(answer == (std::to_string(dollarsAmount) + "-" + std::to_string(price) + "-" + 
				std::string("Purchase ") + std::string("!\n")));


	//Test GetCompletedOrders
	SendMessage(s, login, Requests::ViewCompleted, "");
	answer = ReadMessage(s);
	assert(answer == std::string("!\n"));



	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodPutOrderBuyForOneUser() with success" << std::endl;
}


void TestMethodGetBalanceSellOrderForOneUser() {
	std::cout << "START TestMethodPutOrderBuyForOneUser()" << std::endl;

	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "B";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");

	std::string password = "abcdef";
	std::string name = "Michel";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);

	unsigned dollarsAmount = 200;
	double price = 61.5;
	std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
	SendMessage(s, login, Requests::Purchase, message);
	answer = ReadMessage(s);
	assert(answer == "Your Purchase Order has accepted!\n");

	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestMethodPutOrderBuyForOneUser() with success" << std::endl;
}


// In this test we check all functions
void TestFromDescription() {
	std::cout << "START TestFromDescription()" << std::endl;

	boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        tcp::socket s(io_service);
        s.connect(*iterator);

	std::string login = "A";
       	SendMessage(s, "", Requests::CheckIfLoginExist, login);
	std::string answer = ReadMessage(s);
	assert(answer == "Succes, such login doesn't exist yet");


	std::string password = "abc";
	std::string name = "Vladimir";
       	SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
	answer = ReadMessage(s);
	assert(answer == login);

	
	unsigned dollarsAmount = 10;
	double price = 62;
	std::string message = std::to_string(dollarsAmount) + " " + std::to_string(price);
	SendMessage(s, login, Requests::Purchase, message);
	answer = ReadMessage(s);
	assert(answer == "Your Purchase Order has accepted!\n");



	//Test GetBalance
	SendMessage(s, login, Requests::Balance, "");
	answer = ReadMessage(s);
	double balance = 0.0;
	assert(answer == ("Your balance is " + std::to_string(balance) + "!\n"));



	//Test GetAcitveOrders
	SendMessage(s, login, Requests::ViewActive, "");
	answer = ReadMessage(s);
	assert(answer == (std::to_string(dollarsAmount) + "-" + std::to_string(price) + "-" + 
				std::string("Purchase ") + std::string("!\n")));


	
	//Test GetCompletedOrders
	SendMessage(s, login, Requests::ViewCompleted, "");
	answer = ReadMessage(s);
	assert(answer == std::string("!\n"));



	boost::asio::io_service io_service1;
        tcp::resolver resolver1(io_service1);
        tcp::resolver::query query1(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator1 = resolver1.resolve(query1);
        tcp::socket s1(io_service1);
        s1.connect(*iterator1);

	std::string login1 = "B";
       	SendMessage(s1, "", Requests::CheckIfLoginExist, login1);
	std::string answer1 = ReadMessage(s1);
	assert(answer1 == "Succes, such login doesn't exist yet");

	std::string password1 = "abcdef";
	std::string name1 = "Petya";
       	SendMessage(s1, login1, Requests::CreateAnAccount, password1 + " " + name1);
	answer1 = ReadMessage(s1);
	assert(answer1 == login1);

	unsigned dollarsAmount1 = 20;
	double price1 = 63;
	std::string message1 = std::to_string(dollarsAmount1) + " " + std::to_string(price1);
	SendMessage(s1, login1, Requests::Purchase, message1);
	answer1 = ReadMessage(s1);
	assert(answer1 == "Your Purchase Order has accepted!\n");

	//Test GetBalance
	SendMessage(s1, login1, Requests::Balance, "");
	answer1 = ReadMessage(s1);
	double balance1 = 0.0;
	assert(answer1 == ("Your balance is " + std::to_string(balance1) + "!\n"));

	//Test GetAcitveOrders
	SendMessage(s1, login1, Requests::ViewActive, "");
	answer1 = ReadMessage(s1);
	assert(answer1 == (std::to_string(dollarsAmount1) + "-" + std::to_string(price1) + "-" + 
				std::string("Purchase ") + std::string("!\n")));


	//Test GetCompletedOrders
	SendMessage(s1, login1, Requests::ViewCompleted, "");
	answer1 = ReadMessage(s1);
	assert(answer1 == std::string("!\n"));


	boost::asio::io_service io_service2;
        tcp::resolver resolver2(io_service2);
        tcp::resolver::query query2(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator2 = resolver2.resolve(query2);
        tcp::socket s2(io_service2);
        s2.connect(*iterator2);

	std::string login2 = "C";
       	SendMessage(s2, "", Requests::CheckIfLoginExist, login2);
	std::string answer2 = ReadMessage(s2);
	assert(answer2 == "Succes, such login doesn't exist yet");

	std::string password2 = "abcdefg";
	std::string name2 = "Karl";
       	SendMessage(s2, login2, Requests::CreateAnAccount, password2 + " " + name2);
	answer2 = ReadMessage(s2);
	assert(answer2 == login2);

	unsigned dollarsAmount2 = 50;
	double price2 = 61;
	std::string message2 = std::to_string(dollarsAmount2) + " " + std::to_string(price2);
	SendMessage(s2, login2, Requests::Sale, message2);
	answer2 = ReadMessage(s2);
	assert(answer2 == "Your Sale Order has accepted!\n");

	//Test GetBalance
	SendMessage(s2, login2, Requests::Balance, "");
	answer2 = ReadMessage(s2);
	double balance2 = 1880.0;
	assert(answer2 == ("Your balance is " + std::to_string(balance2) + "!\n"));

	//Test GetAcitveOrders
	SendMessage(s2, login2, Requests::ViewActive, "");
	answer2 = ReadMessage(s2);
	assert(answer2 == (std::to_string(dollarsAmount2 - 30) + "-" + std::to_string(price2) + "-" + 
				std::string("Sale ") + std::string("!\n")));


	//Test GetCompletedOrders
	SendMessage(s2, login2, Requests::ViewCompleted, "");
	answer2 = ReadMessage(s2);
	assert(answer2 == std::string("!\n"));



	// TEST GETBALANCE For FIRST USER
	

	SendMessage(s, login, Requests::Balance, "");
	answer = ReadMessage(s);
	balance = -620;
	assert(answer == ("Your balance is " + std::to_string(balance) + "!\n"));



	// TEST GETACTIVE For FIRST USER


	SendMessage(s, login, Requests::ViewActive, "");
	answer = ReadMessage(s);
	assert(answer == std::string("!\n"));

	// TEST GETCOMPLETED For FIRST USER


	SendMessage(s, login, Requests::ViewCompleted, "");
	answer = ReadMessage(s);
	assert(answer == (std::to_string(dollarsAmount) + "-" + std::to_string(price) + "-" + 
				std::string("Purchase ") + std::string("!\n")));



	// TEST GETBALANCE For Second USER
	

	SendMessage(s1, login1, Requests::Balance, "");
	answer1 = ReadMessage(s1);
	balance1 = -1260;
	assert(answer1 == ("Your balance is " + std::to_string(balance1) + "!\n"));


	// TEST GETACTIVE For Second USER


	SendMessage(s1, login1, Requests::ViewActive, "");
	answer1 = ReadMessage(s1);
	assert(answer1 == std::string("!\n"));


	// TEST GETCOMPLETED For Second USER


	SendMessage(s1, login1, Requests::ViewCompleted, "");
	answer1 = ReadMessage(s1);
	assert(answer1 == (std::to_string(dollarsAmount1) + "-" + std::to_string(price1) + "-" + 
				std::string("Purchase ") + std::string("!\n")));

	//
	SendMessage(s, "", Requests::Reset, "");

	std::cout << "END TestFromDescription() with success!" << std::endl;

}

int main()
{
    try
    {
	

        boost::asio::io_service io_service1;

        tcp::resolver resolver1(io_service1);
        tcp::resolver::query query1(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator1 = resolver1.resolve(query1);

        tcp::socket s1(io_service1);
        s1.connect(*iterator1);
	
       	
       	SendMessage(s1, "", Requests::getValueOfFlag, "");
	int flag = std::stoi(ReadMessage(s1));

	std::cout << "flag = " << flag << std::endl;

	if (flag == 0) {
		// Test Method FindLogin
		TestMethodFindLoginIfSuchLoginNotExist();
		TestMethodFindLoginIfSuchLoginExist();
		
		//Test Method GetUserName
		TestMethodGetUserNameWithOnePerson();
		TestMethodGetUserNameWithTwoPersons();


		//Test Method RegisterNewUser()
		TestMethodRegisterNewUserOneUser();
		TestMethodRegisterNewUserTwoUsersWithTheSameLogin();
		TestMethodRegisterNewUserTwoUsersWithTheDifferentLogin();
		TestMethodRegisterNewUserThreeUsers();


		//Test Method CheckIfLoginPasswordCorrect()
		TestMethodCheckIfLoginPasswordCorrectIfCorrectWithOneUser();
		TestMethodCheckIfLoginPasswordCorrectIfNotCorrectWithOneUser();


		//Test Method putOrder, and after test getBalance Method, getActiveOrder Method, getCompletedOrder
		TestMethodPutOrderSaleForOneUser();
		TestMethodPutOrderBuyForOneUser();



		// Test Functionality of Application
		TestFromDescription();



		//Change value of Flag and Test method chagneFlag
	
		std::cout << "Start TestChangeFlag !" << std::endl;
		
		SendMessage(s1, "", Requests::ChangeFlag, "");
		ReadMessage(s1);
       		SendMessage(s1, "", Requests::getValueOfFlag, "");
		int newValueOfFlag = std::stoi(ReadMessage(s1));
		assert(newValueOfFlag == 1);

		std::cout << "END TestChangeFlag with success!" << std::endl;


		std::cout << "TESTS PASSED WITH SUCCESS" << std::endl;
	}

        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), "127.0.0.1", std::to_string(port));
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        s.connect(*iterator);
	
       	

	std::string my_id;
	while (true) {
		bool status = false;
		std::cout << "Do you have an account? " << std::endl;
		std::cout << "1) Yes\n"
		  	  << "2) No\n"
		  	  << std::endl;
		short option = 0;
		std::cin >> option;
		switch (option) {
			case 1:
			{
				std::string answer;
				while (true) {
					std::cout << "Enter your login: ";
					std::string login;
					std::cin >> login;
					std::cout << "Enter your password: ";
					std::string password;
					std::cin >> password;
                    			SendMessage(s, login, Requests::EnterToAccount, password);
					answer = ReadMessage(s);
					if (answer != "Permission denied!") {
						break;
					} else {
						std::cout << answer << std::endl;
					}
				}
				my_id = answer;
				status = true;
				break;
			}
			case 2:
			{
				std::string login;

				while (true) {
					std::cout << "Create a login: ";
					std::cin >> login;
                    			SendMessage(s, "", Requests::CheckIfLoginExist, login);
					std::string ans;
					ans = ReadMessage(s);
					if (ans == "Exist") {
						std::cout << "The login - " 
						  	<< login << " -, already exist, please come up with a new."
						  	<< std::endl;
					} else {
						break;
					}
				}

				std::string password;
				while (true) {
					std::cout << "Create a password: ";
					std::cin >> password;
	
					std::cout << "Repeat a password: ";
					std::string passwordRepeat;
					std::cin >> passwordRepeat;

					if (passwordRepeat == password) {
						break;
					} else {
						std::cout << "Passwords don't match" << std::endl;
					}		
				}
				std::cout << "Enter your name: ";
				std::string name;
				std::cin >> name;
                    		SendMessage(s, login, Requests::CreateAnAccount, password + " " + name);
				my_id = ReadMessage(s);
				status = true;
				break;
			}

                	default:
                	{
                    		std::cout << "Unknown menu option\n" << std::endl;
                	}

		}

		if (status == true) {
			break;
		}
	}
	
	
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
