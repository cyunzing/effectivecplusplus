#ifndef TEMPLATESANDGENERICPROGRAMMING_H
#define TEMPLATESANDGENERICPROGRAMMING_H

#include <algorithm>

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

//47
template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, std::random_access_iterator_tag)
{
    iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, std::bidirectional_iterator_tag)
{
    if (d >= 0) {
        while (d--)
            ++iter;
    } else {
        while (d++)
            --iter;
    }
}

template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, std::input_iterator_tag)
{
    if (d < 0)
        throw std::out_of_range("Negative distance");

    while (d--)
        ++iter;
}

template<typename IterT, typename DistT>
void advance(IterT &iter, DistT d)
{
    doAdvance(iter, d, std::iterator_traits<IterT>::iterator_category());
}

#endif // TEMPLATESANDGENERICPROGRAMMING_H
