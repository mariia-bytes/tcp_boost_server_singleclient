#!/bin/zsh

# Name of the Docker Compose project
PROJECT_NAME="tcp-boost-network"

# Build the Docker Compose project
sudo docker compose -p $PROJECT_NAME build

# Start the Docker Compose project
sudo docker compose -p $PROJECT_NAME up