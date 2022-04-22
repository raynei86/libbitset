#!/usr/bin/sh

# This is for pre commit git hook
# ln -s pre-commit.sh .git/hooks/pre-commit

clang-format -i ./*.c
clang-format -i ./*.h
