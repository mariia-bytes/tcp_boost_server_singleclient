#ifndef COMMON_H
#define COMMON_H

#include <boost/asio.hpp>
#include <string>

namespace common {
    extern const std::string ip_address;
    extern unsigned short port;

    // read the message from the socket
    std::string read_message(boost::asio::ip::tcp::socket& socket);

    // send a message through the socket
    void send_message(boost::asio::ip::tcp::socket& socket, const std::string message);
}

#endif // COMMON_H