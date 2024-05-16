// Вариант 8.
// Написать программу, которая, используя минимальное количество оперативное памяти, найдет объем куба по известной стороне A (целое, 0<A<40).
#include <iostream>
#include <cmath>
int main() {
    unsigned char A;
    scanf("%hhu", &A); 
    
    std::cout << (A*A*A) << std::endl;

    return 0;
}
