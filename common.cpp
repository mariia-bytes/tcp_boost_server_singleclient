#include "common.h"
#include <iostream>

namespace common {
    const std::string ip_address = "0.0.0.0"; // default IP_address
    unsigned short port = 55000; // default port

    std::string read_message(boost::asio::ip::tcp::socket& socket) {
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\n");

        std::istream stream(&buffer);
        std::string message;
        std::getline(stream, message);

        return message;
    }

    void send_message(boost::asio::ip::tcp::socket& socket, const std::string message) {
        const std::string msg = message + "\n";
        boost::asio::write(socket, boost::asio::buffer(msg));
    }
}