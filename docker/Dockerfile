# build command: docker build -t build-ubuntu-22.04 .

# run command: docker run -it --rm build-ubuntu-22.04
# docker run -v ../:/work -it --rm build-ubuntu-22.04

FROM ubuntu:22.04

ENV TZ=UTC

# Set timezone before any package installation
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Update package list and install basic utilities
RUN apt update \
    && apt install -y \
        build-essential cmake qtbase5-dev catch2 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR work

CMD ["/bin/bash"]
