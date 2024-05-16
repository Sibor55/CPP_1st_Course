// Вариант 7.
// Написать программу, которая рассчитает главную диагональ прямоугольного параллелепипеда. Входные данные – стороны A,B,C (целые числа, 0 < A,B,C < 3*10^4)
#include <iostream>
#include <cmath>

int main() {
    short int A;
    short int B;
    short int C;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    std::cout << "D = " << sqrt(A*A+B*B+C*C) << std::endl;

    return 0;
}