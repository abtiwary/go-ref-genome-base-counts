FROM golang:1.18

RUN apt update && apt upgrade -y
RUN apt install -y build-essential clang libclang-dev cmake

