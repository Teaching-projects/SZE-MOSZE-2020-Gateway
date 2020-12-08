FROM ubuntu:20.04

ENV CC="/usr/bin/gcc-9"
ENV CXX="/usr/bin/g++-9"

ENV TZ="Europe/Budapest"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install --no-install-recommends -y \
  gcc-9 \
  g++-9 \
  make \
  cmake \
  cppcheck \
  valgrind \
  doxygen \
  graphviz \
  libgtest-dev \
  git \
  ca-certificates \
  && rm -rf /var/lib/apt/lists/*