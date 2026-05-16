#!/bin/sh

find "/etc/os-release" -exec grep "^PRETTY_NAME=" {} \; | sed "s/^PRETTY_NAME=//"
