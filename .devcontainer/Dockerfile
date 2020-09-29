FROM mcr.microsoft.com/vscode/devcontainers/cpp:debian-10

# Install additional system packages.
RUN apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get -y install --no-install-recommends python3-pip python3-setuptools

# Install conan (C/C++ package manager).
RUN pip3 install conan --no-cache-dir

# Add conan remote repository where the ZenGitHub package is stored.
RUN conan remote add conan-jonico https://api.bintray.com/conan/conan-jonico/libzengithub

# Pre-install all project dependencies using conan.
COPY . /tmp/repo
RUN cd /tmp/repo && conan install ./src --build missing -s build_type=Debug
