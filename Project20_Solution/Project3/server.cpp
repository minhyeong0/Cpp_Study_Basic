#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;


int main()
{
	try
	{
		boost::asio::io_service io_service;
		
		tcp::endpoint endpoint(tcp::v4(), 13);
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server start" << std::endl;

		for (;;)
		{
			const std::string message_to_send = "Hello From Server";
			
			boost::asio::ip::tcp::iostream stream;

			std::cout << "check 1" << std::endl;

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec); //클라이언트가 접속하면 read 버퍼 읽음

			std::cout << "check 2" << std::endl;

			if (!ec) //클라이언트가 접속에 성공했다면
			{
				//receive message from client
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;

				//send message to client
				stream << message_to_send;
				stream << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}