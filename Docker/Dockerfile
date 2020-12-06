FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
    gcc-9 \
    g++-9 \
    valgrind \
    cppcheck \
    make \
    cmake \ 
    libgtest-dev \
    doxygen \
    graphviz \
&& rm -rf /var/lib/apt/lists/*