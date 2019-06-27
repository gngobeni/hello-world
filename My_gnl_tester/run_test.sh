#!/bin/bash

GNLDIR=../gnl_vogs 

echo "Compiling test_gnl.exe..."
make -C $GNLDIR/libft fclean && make -C $GNLDIR/libft
clang -Wall -Wextra -Werror -I $GNLDIR/libft/includes -o get_next_line.o -c $GNLDIR/get_next_line.c
clang -Wall -Wextra -Werror -I $GNLDIR/libft/includes -I $GNLDIR -o test0.o -c tests/test0.c
clang -o test_gnl get_next_line.o test0.o -I $GNLDIR/libft/includes -L $GNLDIR/libft/ -lft
echo "testing..."
echo -e "Output:"
./test_gnl tests/input/*.txt > result.txt
cat tests/input/*.txt > compare.txt 
cat result.txt
echo ""
echo $'>>>>>>>>>>>>>>>>>>>>>>>>>>>Test complete :)\n'
diff result.txt compare.txt
rm -f *.txt *.o test_gnl
