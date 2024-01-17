// Вариант 2.
// Написать программу, которая получает на вход 2 целых числа h и a (0 < h,a < 10^8) – высоту и основание треугольника. Рассчитать площадь треугольника. 
#include <iostream>
int main() {
    int h;
    int a;
    int S;
    
    std::cin >> h;
    std::cin >> a;

    S = (a*h)/2;
    std::cout << "S = " << S << std::endl;

    return 0;
}