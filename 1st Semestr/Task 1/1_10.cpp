// Вариант 10.
// Написать программу для вычисления корня N (вещественное, 0<N<100) степени из числа X (вещественное, 0<X<100).
#include <iostream>
#include <cmath>
int main() {
    float N;
    float X;
    
    std::cin >> X;
    std::cin >> N;

    std::cout << std::pow(X, 1.0 / N) << std::endl;

    return 0;
}
