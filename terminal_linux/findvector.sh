#!/bin/sh

find . -type f -name "*.cpp" -exec grep  -l "include <vector>" {} \;
