#include <iostream>
#include "asttimer.hpp"

unsigned long long factorial_recursive(unsigned char num) {
    if (num < 2) return num;
    return num * factorial_recursive(num - 1);
}

unsigned long long factorial_loop(unsigned char num) {
    long long ret {num};
    while (num > 1) ret *= --num;
    return ret;
}

int main(int argc, char** argv) {

    ast::timer<long long, std::nano> t;

    t.start();
    auto res1 = factorial_recursive(15);
    t.stop();

    t.start();
    auto res2 = factorial_loop(15);
    t.stop();

    t.start();
    auto shouldBeCloseToZero = t.stop();

    std::cout << "res1 = " << res1 << " res2 = " << res2 << std::endl;

    std::cout << "dur1 = " << t[0] << "   dur2 = " << t[1] << "    time delta = " << shouldBeCloseToZero << std::endl;

    return 0;
}