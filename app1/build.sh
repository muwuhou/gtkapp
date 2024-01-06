#!/bin/sh

gcc `pkg-config --cflags --libs gtk4` main.c -o main
