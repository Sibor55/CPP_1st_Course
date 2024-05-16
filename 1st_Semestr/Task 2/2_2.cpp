
// Вариант 2.
// Установить i-ый бит числа х (0<x<10^9) в 0.

#include <iostream>
#include <bitset>

int main() {
    std::bitset<16> set;
    unsigned int x;
    unsigned int tmp;
    unsigned char i;

    scanf("%hhu", &i);
    std::cin >> x;
    tmp = 1;
    tmp = tmp << i;
    x = x & ~tmp;
    set = x;
    std::cout << set << std::endl;

    return 0;
}
