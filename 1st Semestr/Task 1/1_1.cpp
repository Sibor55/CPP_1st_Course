// Вариант 1.
// Написать программу, которая на вход получает 3 целых числа A, B, C – стороны треугольника. Рассчитать площадь треугольника по формуле Герона. Пусть (S = корень p ( p − a ) ( p − b ) ( p − c ))
#include <iostream>
#include <cmath>
int main() {
    int A;
    int B;
    int C;
    float S;
    float p;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    p = (A+B+C)/2.0;
    S = std::sqrt(p*(p-A)*(p-B)*(p-C));
    std::cout << "S = " << S << std::endl;

    return 0;
}
