#include <iostream>
#include <boost/asio.hpp>
#include "common.h"

using namespace boost::asio;
using ip::tcp;

int main(int argc, char* argv[]) {
    // determine the port from command-line argument or use default
    if (argc > 1) {
        try {
            common::port = static_cast<unsigned short>(std::stoi(argv[1]));
        } catch (const std::exception& e) {
            std:: cerr << "Invalid port provided.Using default port " << common::port << std::endl;
        }
    } 
    
    
    try {
        // initialise Boost ASIO
        boost::asio::io_context io_context;

        // create endpoint from user input
        tcp::endpoint endpoint(boost::asio::ip::address::from_string(common::ip_address), common::port);
        
        // creating a socket
        tcp::socket connection_socket(io_context);

        // Connecting to the server
        connection_socket.connect(endpoint);

        std::cout << "\nConnection to " << common::ip_address 
                  << ":" << common::port << " established" << std::endl;

        common::send_message(connection_socket, "Hello from Client!");
        std::cout << "\nClient sent: Hello from Client!" << std::endl;

        std::string response_message = common::read_message(connection_socket);
        std::cout << "Server> " << response_message << std::endl;

        // notify about shutdown
        std::cout << "\nShutting down the client..." << std::endl;

        // Closing the socket
        connection_socket.close();

    } catch (std::exception& excep) {
        std::cerr << "Exception: " << excep.what() << std::endl;
    }

    return 0;
} 