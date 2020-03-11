#!/bin/sh
if [ "$1" = "-all" ];
then
    echo "\x1B[32m\x1b[1mCompiling All Tests ...\x1B[0m"
    make re > /dev/null
    gcc -o ./tests/test0 ./tests/test0.c
    gcc -o ./tests/test1 ./tests/test1.c
    gcc -o ./tests/test2 ./tests/test2.c
    gcc -o ./tests/test3 ./tests/test3.c
    gcc -o ./tests/test4 ./tests/test4.c
    gcc -o ./tests/test5 ./tests/test5.c
    gcc -w -o ./tests/test6 ./tests/test6.c -L. -lft_malloc
    gcc -o tests/test_calloc tests/test_calloc.c -L. -lft_malloc
    gcc -o ./tests/test_thread tests/test_thread.c -L. -lft_malloc
    gcc -o tests/test_show_alloc_mem_hex tests/test_show_alloc_mem_hex.c -L. -lft_malloc
elif [ "$1" = "-basic" ];
then
    echo "\x1B[32m\x1b[1mCompiling Basic Tests ...\x1B[0m"
    make re > /dev/null
    gcc -o ./tests/test0 ./tests/test0.c
    gcc -o ./tests/test1 ./tests/test1.c
    gcc -o ./tests/test2 ./tests/test2.c
    gcc -o ./tests/test3 ./tests/test3.c
    gcc -o ./tests/test4 ./tests/test4.c
    gcc -o ./tests/test5 ./tests/test5.c
    gcc -w -o ./tests/test6 ./tests/test6.c -L. -lft_malloc
elif [ "$1" = "-calloc" ];
then
    echo "\x1B[32m\x1b[1mCompiling Calloc Test ...\x1B[0m"
    make re > /dev/null
    gcc -o tests/test_calloc tests/test_calloc.c -L. -lft_malloc
elif [ "$1" = "-thread" ];
then
    echo "\x1B[32m\x1b[1mCompiling Thread-safe Test ...\x1B[0m"
    make re > /dev/null
    gcc -o ./tests/test_thread tests/test_thread.c -L. -lft_malloc
elif [ "$1" = "-mem_hex" ];
then
    echo "\x1B[32m\x1b[1mCompiling Mem Dump Hex Test ...\x1B[0m"
    make re > /dev/null
    gcc -o tests/test_show_alloc_mem_hex tests/test_show_alloc_mem_hex.c -L. -lft_malloc
elif [ "$1" = "-clean" ];
then
    echo "\x1B[31m\x1b[1mCleaning Files ...\x1B[0m"
    make fclean > /dev/null
    rm -f ./tests/test0 ./tests/test1 ./tests/test2 ./tests/test3 ./tests/test4 ./tests/test5 ./tests/test6 ./tests/test_thread ./tests/test_calloc ./tests/test_show_alloc_mem_hex
else
    echo "\x1b[1mProgram used to compile the tests of malloc."
    echo "Usage: ./tests_compiler -all/-basic/-calloc/-thread/-mem_hex to compile then -clean [Mandatory]\x1B[0m"
    echo "  -all:     Compile all tests."
    echo "  -basics:  Tests of the subject. On this tests malloc, free, realloc are used."
    echo "  -calloc:  BONUS Test for the calloc function."
    echo "  -thread:  BONUS Test for the thread-safe."
    echo "  -mem_hex: BONUS Test for the mem dump hex function."
    echo "  ---------------------------------------------------"
    echo "  -clean:   Clean all files generated."
fi
