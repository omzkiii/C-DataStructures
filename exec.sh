#!/bin/bash
clang $1 -o out -Werror -Wextra -Wall && ./out;

# clang $1 -o out && ./out;
