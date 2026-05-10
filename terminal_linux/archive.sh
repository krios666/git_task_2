#!/bin/sh

find "$1" -type f | grep -vFf <(sed 's|^|/|; s|/$||' "$1/.gitignore") | xargs zip "$(basename "$1").zip" -@
