#!/bin/sh

ls main.cpp | entr -r g++ main.cpp -o main
