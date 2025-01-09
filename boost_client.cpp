#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using ip::tcp;

static const std::string ip_address = "127.0.0.1"; // default IP_address
static unsigned short port = 55000; // default port

int main(int argc, char* argv[]) {
    // determine the port from command-line argument or use default
    if (argc > 1) {
        try {
            port = static_cast<unsigned short>(std::stoi(argv[1]));
        } catch (const std::exception& e) {
            std:: cerr << "Invalid port provided.Using default port " << port << std::endl;
        }
    } 
    
    
    try {
        // initialise Boost ASIO
        boost::asio::io_context io_context;

        // create endpoint from user input
        tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip_address), port);
        
        // creating a socket
        tcp::socket connection_socket(io_context);

        // Connecting to the server
        connection_socket.connect(endpoint);

        std::cout << "\nConnection on " << ip_address 
                  << ":" << port << " established" << std::endl;

        // Sending a message to the server
        const std::string message = "Hello from Client!\n";
        boost::system::error_code error;
        boost::asio::write(connection_socket, boost::asio::buffer(message), error);

        if (!error) {
            std::cout << "\nClient sent: " << message;
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

        // notify about shutdown
        std::cout << "Shutting down connection..." << std::endl;

        // Closing the socket
        connection_socket.close();

    } catch (std::exception& excep) {
        std::cerr << "Exception: " << excep.what() << std::endl;
    }

    return 0;
} 