// Вариант 5.
// Написать программу, которая получает на вход стороны прямоугольного параллелепипеда – целые числа A,B,C (0<A,B,C<10^4). И рассчитывает его объем.
#include <iostream>
int main() {
    short int A;
    short int B;
    short int C;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    std::cout << "V = " << (A*B*C) << std::endl;

    return 0;
}