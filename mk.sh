#!/bin/bash

g++ -o main \
      main.cpp  \
      user.cpp \
      cap_gen.cpp \
      client.cpp \
      server.cpp \
      cap_parse.cpp \
      db_functions.cpp \
      -lsqlite3 \
      -pthread
