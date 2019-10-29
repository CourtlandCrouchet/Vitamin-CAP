#!/bin/bash

g++ -o main main.cpp  \
            user.cpp \
            cap_gen.cpp \
            client.cpp

./main
