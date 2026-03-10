# Boost.Asio TCP Client-Server Demo

This is a simple TCP client-server demonstration using **Boost.Asio** in C++. The server listens for incoming connections on port `8080` and sends a greeting message to each connected client. The client connects to the server and prints the received message.

## Project Structure

boost_asio_demo/
│
├── CMakeLists.txt        # CMake build configuration
├── server.cpp            # TCP server implementation
└── client.cpp            # TCP client implementation

## Requirements

- C++17 compatible compiler
- Boost library (system component)
- CMake 3.10 or newer
- pthread library (on Linux/macOS)

## Build Instructions

1. Clone the repository
 
2. Create a build directory and run CMake:

```bash
mkdir build
cd build
cmake ..
make
```

3. After building, you should have two executables:

- `server`
- `client`

## Running the Server

Start the server first:
```bash
./server
```

## Running the Client

In a separate terminal, run the client:
```bash
./client
```

## Code Overview

### Server (`server.cpp`)

- Uses `boost::asio::ip::tcp::acceptor` to listen on port 8080.
- Accepts incoming connections in a loop.
- Sends a greeting message `"Hello from server!\n"` to each client.

### Client (`client.cpp`)

- Connects to the server at `127.0.0.1:8080`.
- Reads the greeting message using `boost::asio::read_until`.
- Prints the message to standard output.


## Notes

- Make sure the server is running before starting the client.
- - The client trims any `\r` character at the end of the message to handle different line endings.

























