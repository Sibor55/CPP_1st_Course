// Вариант 4.
// Написать программу, которая получает на вход вещественное число R (0 < R < 100) – радиус круга. И рассчитывает площадь круга с точностью до 10^-9.
#include <iostream>
#include <iomanip>

int main() {
    const double PI = 3.141592653;
    float R;

    std::cin >> R;
    std::cout << std::fixed << std::setprecision(9)<< (PI*R*R)<< std::endl; 

    return 0;
}
