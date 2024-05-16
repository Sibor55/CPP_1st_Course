// Вариант 3.
// Написать программу, которая, используя минимальное количество оперативной памяти рассчитает, периметр прямоугольника со сторонами A и B (0 < A,B < 20). A и B считать с клавиатуры.
// todo: придумать как вводить числа при этом не используя инт
#include <iostream>
int main() {
    unsigned char A;
    unsigned char B;
    scanf("%hhu%hhu", &A, &B); //Я не понял как это работает, но нашел на форуме (https://www.cyberforum.ru/cpp-beginners/thread2615607.html)
    
    std::cout << (2*A+B) << std::endl;

    return 0;
}