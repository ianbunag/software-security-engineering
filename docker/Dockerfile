# xenial-20200706 is the final snapshot for Ubuntu 16.04.6 LTS before 16.04.7.
FROM --platform=linux/386 i386/ubuntu:xenial-20200706

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
       build-essential \
       gcc \
       gcc-5 \
       gdb \
       tar \
       flawfinder \
       valgrind

WORKDIR /activities

CMD ["/bin/bash"]
