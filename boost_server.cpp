#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using ip::tcp;

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
        
        // setup acceptor and bind to the endpoint
        tcp::acceptor server_acceptor(io_service, endpoint);
        
        // create a socket for the client connection
        tcp::socket client_socket(io_service);

        std::cout << "\nWaiting for a client to connect on " << ip_address << ":" << port << "..." << std::endl;
        
        // wait for connection
        server_acceptor.accept(client_socket);

        // read client's message
        std::string message = read_message(client_socket);
        std::cout << "\nClient> " << message << std::endl;

        // send a response message to the client
        send_message(client_socket, "Hello from Server!");
        std::cout << "\nServer sent hello to the Client" << std::endl;

        // closing the socket
        client_socket.close();
    
    } catch (std::exception& excep) {
        std::cerr << "error: " << excep.what() << std::endl;
    }
    
    return 0;
}