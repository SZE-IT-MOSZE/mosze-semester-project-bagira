FROM ubuntu:20.04
RUN apt update \
&& DEBIAN_FRONTEND=nointeractive apt install -y \
    g++ \
    doxygen \
    libgtest-dev \        
    cmake \
  && rm -rf /var/lib/apt/lists/*

RUN ln -st /usr/lib/ /usr/src/gtest/libgtest.a 
RUN ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a