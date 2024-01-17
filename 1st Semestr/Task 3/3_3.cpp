// Переменная x может принимать 2 значения: -1 и 1. Если -1, 
// то вывести в консоль “Negative number”, если положительное - “Positive number”. 
// Предложить вариант программы и объяснить свой выбор.

#include <iostream>
int main() {
    int x;
    std::cin >> x;

    switch (x)
    {
    case -1:
        std::cout << "Negative number";
        break;
    case 1:
        std::cout << "Positive number";
    default:
    
        break;
    }
    return 0;
}