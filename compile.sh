#!/bin/bash
gcc -Wall -Wextra -Werror ./libft/*.c ./stack/*.c ./sources/*.c -o push_swap

echo -e
./push_swap 1 2 3 4 5

echo -e
./push_swap 5 4 3 3 1

echo -e
./push_swap one 1 2 3 4

echo -e
./push_swap 2 2 3 0 5

echo -e
./push_swap 2 1 3 6 5 8

rm push_swap