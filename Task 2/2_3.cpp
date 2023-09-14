
// Вариант 3.
// Вывести значение i-го бита числа x (0<x<10^9).

#include <iostream>
#include <bitset>

int main() {
    std::bitset<16> set;
    unsigned int x;
    unsigned char i;

    scanf("%hhu", &i);
    std::cin >> x;
    set = x;
    std::cout << set.to_string()[i] << " " << set << std::endl;

    return 0;
}
