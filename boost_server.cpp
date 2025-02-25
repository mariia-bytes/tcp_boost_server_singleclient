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
            std::cerr << "Invalid port provided. Using default port " << common::port << std::endl;
        }
    }

    try {
        // initialise Boost ASIO
        boost::asio::io_context io_context;

        // create endpoint from user input
        tcp::endpoint endpoint(boost::asio::ip::address::from_string(common::ip_address), common::port);
        
        // setup acceptor and bind to the endpoint
        tcp::acceptor server_acceptor(io_context, endpoint);
        
        // create a socket for the client connection
        tcp::socket client_socket(io_context);

        std::cout << "\nWaiting for a client to connect on " << common::ip_address << ":" << common::port << "..." << std::endl;
        
        // wait for connection
        server_acceptor.accept(client_socket);

        // notify the server that the client's connectes
        std::cout << "Client connected on " << client_socket.remote_endpoint().address().to_string()
                  << ":" << client_socket.remote_endpoint().port() << std::endl;

        // read client's message
        std::string message = common::read_message(client_socket);
        std::cout << "\nClient> " << message << std::endl;

        // send a response message to the client
        common::send_message(client_socket, "Hello from Server!");
        std::cout << "Server sent: " << message << std::endl;

        // notify about shutdown
        std::cout << "\nShutting down the server..." << std::endl;

        // closing the socket
        client_socket.close();
    
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    
    return 0;
}