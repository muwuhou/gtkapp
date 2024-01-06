#!/bin/sh

gcc `pkg-config --cflags --libs gtk4` hello.c -o hello
