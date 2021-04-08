FROM fedora:31

WORKDIR /root

RUN dnf -y upgrade --setopt=install_weak_deps=False && \
    dnf -y install --setopt=install_weak_deps=False bash git make gcc-c++

CMD /bin/bash


