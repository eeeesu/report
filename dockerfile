FROM gcc

RUN apt -y update && apt -y install git
RUN apt -y install gdb cppcheck clang

WORKDIR /mnt
