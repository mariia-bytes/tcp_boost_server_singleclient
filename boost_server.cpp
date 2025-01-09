#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using ip::tcp;

static const std::string ip_address = "127.0.0.1"; // default ip_address
static unsigned short port = 55000; // default port

std::string read_message(tcp::socket& socket) {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\n");

    std::istream stream(&buffer);
    std::string message;
    std::getline(stream, message);
    
    return message;
}

void send_message(tcp::socket& socket, const std::string& message) {
    const std::string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(msg));
}


int main(int argc, char* argv[]) {
    // determine the port from command-line argument or use default
    if (argc > 1) {
        try {
            port = static_cast<unsigned short>(std::stoi(argv[1]));
        } catch (const std::exception& e) {
            std::cerr << "Invalid port provided. Using default port " << port << std::endl;
        }
    }

    try {
        // initialise Boost ASIO
        boost::asio::io_context io_context;

        // create endpoint from user input
        tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip_address), port);
        
        // setup acceptor and bind to the endpoint
        tcp::acceptor server_acceptor(io_context, endpoint);
        
        // create a socket for the client connection
        tcp::socket client_socket(io_context);

        std::cout << "\nWaiting for a client to connect on " << ip_address << ":" << port << "..." << std::endl;
        
        // wait for connection
        server_acceptor.accept(client_socket);

        // read client's message
        std::string message = read_message(client_socket);
        std::cout << "\nClient> " << message << std::endl;

        // send a response message to the client
        send_message(client_socket, "Hello from Server!");
        std::cout << "\nServer sent: " << message << std::endl;

        // notify about shutdown
        std::cout << "\nShutting down the server..." << std::endl;
        
        // closing the socket
        client_socket.close();
    
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    
    return 0;
}