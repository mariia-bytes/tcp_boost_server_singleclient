FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libboost-all-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY boost_server.cpp boost_client.cpp common.h common.cpp CMakeLists.txt ./

RUN mkdir build && cd build && \
    cmake .. && \
    make

EXPOSE 55000

# use this line to run both server and client from one container
# CMD ["bash", "-c", "./build/boost_server & ./build/boost_client"]