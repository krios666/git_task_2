#!/bin/sh

find . -type f -name "*.cpp" -exec zip -j "cpp_files_$1.zip" {} \;
