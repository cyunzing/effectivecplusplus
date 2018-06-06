#ifndef TEMPLATESANDGENERICPROGRAMMING_H
#define TEMPLATESANDGENERICPROGRAMMING_H


//46
template<typename T>
class Rational {
public:
    friend const Rational operator* (const Rational &lhs, const Rational &rhs)
    {
        return Rational(lhs.numerator() * rhs.numerator(),
                        lhs.denominator() * rhs.denominator());
    }

    Rational(const T &numerator = 0, const T &denominator = 1)
    {
        n = numerator;
        d = denominator;
    }

    const T numerator() const
    {
        return n;
    }
    const T denominator() const
    {
        return d;
    }

private:
    T n;
    T d;
};

/*error!!!无法隐式转换
 *
template<typename T>
const Rational<T> operator* (const Rational<T> &lhs, const Rational<T> &rhs)
{
    return Rational<T>(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
*/

#endif // TEMPLATESANDGENERICPROGRAMMING_H
