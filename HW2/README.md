# Structure of the directory

.
|
|___ README.md                          This file, explain the structure and how to compile and run
|___ large_integer_arithmetic.h         Header files of large integer arithmetic
|___ large_integer_arithmetic.cpp       Implementation of add, subtract, multiply, divide and mod of large integers
|___ test_large_int_arithmetic.cpp      First part of homework, test the implementation of large integers
|___ DH.cpp                             Second part of homework, using first part to implement DH algorithm
|___executables
        |
        |___ test_large_int_arithmetic.exe      Execute to run the first part
        |___ DH.exe                             Execute to run the second part

# How to compile and run

Test_large_int_arithmetic.exe:

**g++ -o test_large_int_arithmetic.exe test_large_int_arithmetic.cpp large_integer_arithmetic.cpp**

DH.exe:

**g++ -o DH.exe DH.cpp large_integer_arithmetic.cpp**