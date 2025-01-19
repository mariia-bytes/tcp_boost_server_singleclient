# Basic TCP Server-Client Architecture with Boost ASIO

This project is a minimal implementation of a TCP server-client architecture using [Boost ASIO](https://www.boost.org/doc/libs/release/libs/asio/). The server supports only **one client** connection at a time and was created solely for educational purposes to understand the workings of Boost ASIO. 

## Features
- **Simple TCP Server and Client:** Establishes a connection between a server and a client using Boost ASIO.
- **Single Client Support:** Designed to handle one client connection at a time.
- **Localhost Communication:** Establishes connction on localhost (`127.0.0.1`) and an available port (default port 55000 or customizable).
- **Message exchange:** Server and client exchange messages and terminate the connection.

⚠ **Note:** This project will not be improved further. Instead, a future project will expand upon this concept to support multiple client connections.

---

## Getting Started

### Prerequisites
The project can be build and run either with Docker *or* manually.
#### To build and run with Docker
- Docker installed for containerized builds and execution
#### To build and run manually
- C++ compiler with C++17 or later support
- Boost libraries installed (specifically, Boost ASIO)
- CMake (minimum version 3.10)

### Cloning the Repository
Clone this repository to your local machine:
```bash
git clone https://github.com/mariia-bytes/tcp_boost_server_singleclient.git
cd tcp_boost_server_singleclient
```
### Building and running the Project with Docker
1. Build a Docker image:
```bash
docker build -t boost-server-app .
```
*Note: you might need to use sudo to execute Docker commands*
2. Run the Docker container
```bash
docker run boost-server-app
```


### Building and running the project manually
1. Create a build directory:
```bash
mkdir build && cd build
```
2. Run CMake to configure the project:
```bash
cmake ..
```
3. Build the executables:
```bash
make
```
4. Start the server:
```bash
./boost_server
```
5. Start the client in a separate terminal:
```bash
./boost_client
```

#### Usage Example
1. Start the server:
```bash
./boost_server
```
*or*
```bash
./boost-_server <port_number>
```
3. Start the client:
```bash
./boost_client
```
*or*
```bash
./boost_client <same_port_number>
```

***Once the connection is established, the server and client exchange a "hello" message before the program terminates.***

---

*This project began on January 6th, 2024*
