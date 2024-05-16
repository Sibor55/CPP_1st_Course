// Вариант 6.
// Написать программу, которая по полученным площади основания S (целое, 0<S<100) и высоте h (целое, 0<h<100), вычисляет объем пирамиды.
#include <iostream>

int main() {
    short int S;
    short int h;

    std::cin >> S;
    std::cin >> h;
    std::cout << std::endl << "V = " << ((S*h)/6) << std::endl;

    return 0;
}