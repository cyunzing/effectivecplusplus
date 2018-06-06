#include "templatesandgenericprogramming.h"

int main(int argc, char *argv[])
{
    Rational<int> half(1, 2);

    Rational<int> r = half * 2;

    return 0;
}
