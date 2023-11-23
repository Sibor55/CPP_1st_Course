// Дано натуральное число N (N<10^9). Найти наибольшую цифру числа N.
#include <iostream>


int main() {
    int N = 19435235;
    int a;
    int maxnum = -1;
    while (N>0) {
        a = N % 10;
        if (a > maxnum) {
            maxnum = a;
        }
        N = N/10;
        // std::cout << a << std::endl;
    }
    std::cout << maxnum << std::endl;
    return 0;
}