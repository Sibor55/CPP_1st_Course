// Вариант 9.
// Написать программу, которая рассчитает площадь треугольника по известному углу a, сторонам A и B. Считается, что треугольник существует.
#include <iostream>
#include <cmath>

int main() {
    int A;
    int B;
    int a;

    std::cin >> A;
    std::cin >> B;
    std::cin >> a;

    std::cout << "S = " << (A*B*sin(a)/2);

    return 0;
}