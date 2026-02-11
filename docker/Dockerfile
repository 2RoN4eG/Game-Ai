# build command: docker build -t build-ubuntu-20.04 .

# run command: docker run -it --rm build-ubuntu-20.04
# docker run -v ../:/work -it --rm build-ubuntu-20.04

FROM ubuntu:22.04

ENV TZ=UTC

# Set timezone before any package installation
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Update package list and install basic utilities
RUN apt update && \
    apt install -y \
        build-essential cmake qtbase5-dev git catch2 \
    && rm -rf /var/lib/apt/lists/*

# Install Catch2 with C++17 standard
# RUN git clone https://github.com/catchorg/Catch2.git && \
#     cd Catch2 && \
#     cmake -Bbuild -H. \
#         -DBUILD_TESTING=OFF \
#         -DCMAKE_CXX_STANDARD=17 \
#         -DCMAKE_CXX_STANDARD_REQUIRED=ON && \
#     cmake --build build/ --target install && \
#     cd .. && \
#     rm -rf Catch2

WORKDIR work

CMD ["/bin/bash"]
