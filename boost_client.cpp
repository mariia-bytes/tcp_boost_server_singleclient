#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using ip::tcp;

int main() {
    // prompt user for IP and port
    std::string ip_address;
    unsigned short port;

    std::cout << "\nEnter IP address (e.g., 127.0.0.1): ";
    std::cin >> ip_address;

    std::cout << "Enter port number (e.g., 55000): ";
    std::cin >> port;
    
    try {
        // initialise Boost ASIO
        boost::asio::io_service io_service;

        // create endpoint from user input
        tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip_address), port);
        
        // creating a socket
        tcp::socket connection_socket(io_service);

        // Connecting to the server
        connection_socket.connect(endpoint);

        // Sending a message to the server
        const std::string message = "Hello from Client!\n";
        boost::system::error_code error;
        boost::asio::write(connection_socket, boost::asio::buffer(message), error);

        if (!error) {
            std::cout << "\nClient sent hello to the Server" << std::endl;
        } else {
            std::cerr << "Send failed: " << error.message() << std::endl;
            return 1;
        }

        // Receiving response from the server
        boost::asio::streambuf receive_buffer;
        boost::asio::read_until(connection_socket, receive_buffer, "\n", error);

        if (error && error != boost::asio::error::eof) {
            std::cerr << "Receive failed: " << error.message() << std::endl;
        } else {
            std::istream response_stream(&receive_buffer);
            std::string response_message;
            std::getline(response_stream, response_message);

            std::cout << "\nServer> " << response_message << std::endl;
        }

        // Closing the socket
        connection_socket.close();

    } catch (std::exception& excep) {
        std::cerr << "Error: " << excep.what() << std::endl;
    }

    return 0;
}