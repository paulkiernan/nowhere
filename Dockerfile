FROM ubuntu:bionic
ENV DEBIAN_FRONTEND noninteractive

RUN useradd -ms /bin/bash nowhere
ENV HOME /home/nowhere
WORKDIR /home/nowhere

# Install base packages
RUN apt-get update && apt-get -y dist-upgrade
RUN apt-get update && apt-get -y install \
        bsdmainutils \
        build-essential \
        curl \
        git \
        openjdk-11-jre \
        python-serial \
        teensy-loader-cli \
        udev \
        xvfb

# Install Arduino base
# NOTE: Teensyduino doesn't support the arduino version packaged in apt
ENV ARDUINO_IDE_VERSION 1.8.9
RUN curl -L https://downloads.arduino.cc/arduino-${ARDUINO_IDE_VERSION}-linux64.tar.xz | \
    tar xJC /usr/share && \
    ln -s /usr/share/arduino-${ARDUINO_IDE_VERSION} \
          /usr/share/arduino && \
    ln -s /usr/share/arduino-${ARDUINO_IDE_VERSION}/arduino \
          /usr/bin/arduino

# Install Teensyduino on top of Arduino
WORKDIR /scratch
RUN curl -L -O https://www.pjrc.com/teensy/td_146/TeensyduinoInstall.linux64 && \
    chmod +x TeensyduinoInstall.linux64 && \
    ./TeensyduinoInstall.linux64 --dir=/usr/share/arduino && \
    rm -rf /scratch

# Install Teensyduino udev rules
RUN curl -L https://www.pjrc.com/teensy/49-teensy.rules > /etc/udev/rules.d/49-teensy.rules

USER nowhere
WORKDIR /nowhere