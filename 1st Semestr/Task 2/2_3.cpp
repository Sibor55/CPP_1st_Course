
// Вариант 3.
// Вывести значение i-го бита числа x (0<x<10^9).

#include <iostream>
#include <bitset>

int main() {
    std::bitset<16> set;
    unsigned int x;
    unsigned char i;
    unsigned int tmp;

    scanf("%hhu", &i);
    std::cin >> x;
    tmp = 1;
    tmp = tmp << i;
    x = x & tmp;
    set = x;    

    std::cout << set << (bool(x));


    // std::cout << set.to_string()[i] << " " << set << std::endl;

    return 0;
}
