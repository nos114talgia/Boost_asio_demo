#include <iostream>
#include <string>
#include <cstring>
#include <boost/asio.hpp>

using namespace boost::asio;
int main(){
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8080);
    ip::tcp::socket socket(service);
    socket.connect(ep);

    // read meg from server
    boost::asio::streambuf buf;
    read_until(socket, buf, "\n");

    std::istream in(&buf);
    std::string msg;
    std::getline(in, msg);
    if(!msg.empty() && msg.back() == '\r'){
        msg.pop_back();
    }   
    std::cout << "Received: " << msg << std::endl;

}