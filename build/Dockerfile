FROM ubuntu:19.04

RUN apt-get update && apt-get install -y build-essential \
  autoconf \
  wget \
  libsubunit-dev \
  pkg-config

WORKDIR /opt

RUN wget https://github.com/libcheck/check/releases/download/0.12.0/check-0.12.0.tar.gz
RUN tar -zxvf check-0.12.0.tar.gz
WORKDIR /opt/check-0.12.0
RUN ./configure --prefix=/usr
RUN make
RUN make install

RUN mkdir /workdir
WORKDIR /workdir

COPY m4 /workdir/m4
COPY src /workdir/src
COPY tests /workdir/tests
COPY AUTHORS /workdir/AUTHORS
COPY ChangeLog /workdir/ChangeLog
COPY configure.ac /workdir/configure.ac
COPY COPYING /workdir/COPYING
COPY INSTALL /workdir/INSTALL
COPY LICENSE /workdir/LICENSE
COPY Makefile.am /workdir/Makefile.am
COPY NEWS /workdir/NEWS
COPY README /workdir/README
COPY README.md /workdir/README.md

RUN autoreconf -vi
RUN ./configure --prefix=/usr
RUN make
