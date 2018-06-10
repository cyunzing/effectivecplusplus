#include <iostream>

#include "templatesandgenericprogramming.h"

int main(int argc, char *argv[])
{
    Rational<int> half(1, 2);

    Rational<int> r = half * 2;

    std::cout << Factorial<5>::value << std::endl;

    return 0;
}
