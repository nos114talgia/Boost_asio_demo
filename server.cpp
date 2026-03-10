#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <cstring>

using namespace boost::asio;

int main(){
    // IO service
    io_service service;
    // create, open, bind and listen
    ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 8080));
    std::cout << "Server started. Listening on port 8080..." << std::endl;
    // accept connection
    while(true){
        ip::tcp::socket socket(service);
        acceptor.accept(socket);
        std::cout << "Connection accepted." << std::endl;
        ip::tcp::endpoint remote_ep = socket.remote_endpoint();
        std::cout << "Remote endpoint: " << remote_ep.address().to_string() << ":" << remote_ep.port() << std::endl;

        std::string msg = "Hello from server!\n";
        boost::system::error_code ec;
        write(socket, buffer(msg), ec);

        if(ec){
            std::cout << "Error: " << ec.message() << std::endl;
        }else{
            std::cout << "Message sent." << std::endl;
        }

    }

    return 0;

}
