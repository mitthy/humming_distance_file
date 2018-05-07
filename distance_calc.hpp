#ifndef DIST_CALC_HPP
#define DIST_CALC_HPP
#include <iterator>

template<typename NumericType>
unsigned int count_set_bits(NumericType n) {
    unsigned int count = 0;
    while(n) {
        n &= (n - 1);
        ++count;
    }
    return count;
}

template<typename NumericType>
struct humming_distance {
    unsigned long operator()(NumericType first, NumericType second) {
        first ^= second;
        return count_set_bits(first);
    }
};

template<typename NumericType, typename Function = humming_distance<NumericType>>
unsigned long calculate_distance(NumericType first, NumericType second, Function f = Function()) {
    return f(first, second);
}

template<typename Iterator, typename Function = humming_distance<typename std::iterator_traits<Iterator>::value_type>>
unsigned long calculate_distance(Iterator f_begin, Iterator f_end, Iterator s_begin, Iterator s_end, Function f = Function()) {
    unsigned long sum = 0;
    while(f_begin != f_end && s_begin != s_end) {
        sum += f(*f_begin++, *s_begin++);
    }
    return sum;
}

#endif
