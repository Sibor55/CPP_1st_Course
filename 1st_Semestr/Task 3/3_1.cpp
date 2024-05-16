// Ввести натуральные числа A, B и C. Если A кратно B и B больше C, то вывести A/B+C,
//  если A кратно B и B меньше C, то вывести A/B-C, в остальных случаях вывести (A+B)*C.


#include <iostream>

int main() {
    int A, B, C;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    if ((A%B)==0 && B>C)
    {
        std::cout <<"(A/B+C) "<< (A/B+C) << std::endl;
    }
    else {
    if ((A%B)==0 && B<C)
    {
        std::cout << "(A/B-C) "<< (A/B-C) << std::endl;
    }
    else {
        std::cout << "((A+B)*C) "<< ((A+B)*C) << std::endl;
    } 
    }

    return 0;
}