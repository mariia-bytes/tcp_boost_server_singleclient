# Basic TCP Server-Client Architecture with Boost ASIO

This project is a minimal implementation of a TCP server-client architecture using [Boost ASIO](https://www.boost.org/doc/libs/release/libs/asio/). The server supports only **one client** connection at a time and was created solely for educational purposes to understand the workings of Boost ASIO. 

## Features
- **Simple TCP Server and Client:** Establishes a connection between a server and a client using Boost ASIO.
- **Single Client Support:** Designed to handle one client connection at a time.
- **Localhost Communication:** Ideal for local testing using `127.0.0.1` and an available port.

⚠ **Note:** This project will not be improved further. Instead, a future project will expand upon this concept to support multiple client connections.

---

## Getting Started

### Prerequisites
- C++ compiler with C++17 or later support
- Boost libraries installed (specifically, Boost ASIO)
- CMake (minimum version 3.10)

### Cloning the Repository
Clone this repository to your local machine:
```bash
git clone https://github.com/mariia-bytes/tcp_boost_server_singleclient.git
cd tcp_boost_server_singleclient
```
### Building the Project
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
### Running the Project
After building, you can run the server and client executables:

- Start the server:
```bash
./boost_server
```
- Start the client in a separate terminal:
```bash
./boost_client
```
When prompted, use the following details to establish a connection:
- IP Address: 127.0.0.1 (for localhost)
- Port Number: Any available port (e.g., 55000)

### Usage Example
1. Start the server:
```bash
./boost_server
```
2. Enter the IP address and port (e.g., 127.0.0.1 and 55000).
3. Start the client:
```bash
./boost_client
```
4. Enter the same IP address and port in the client as used for the server.

***Once the connection is established, the server and client exchange a "hello" message before the program terminates.***
