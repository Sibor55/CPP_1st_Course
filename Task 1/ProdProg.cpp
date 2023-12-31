#include <iostream>
#include <cmath>
#include <cstddef> // Для проверки памяти (std::size_t)
#include <typeinfo> 
#include <iomanip> // Для выведения больше двух цифр после запятой


// Вариант 1.
// Написать программу, которая на вход получает 3 целых числа A, B, C – стороны треугольника. Рассчитать площадь треугольника по формуле Герона. Пусть (S = корень p ( p − a ) ( p − b ) ( p − c ))
// int main() {
//     int A;
//     int B;
//     int C;
//     int S;
//     int p;

//     std::cin >> A;
//     std::cin >> B;
//     std::cin >> C;

//     p = (A+B+C)/2;
//     S = std::sqrt(p*(p-A)*(p-B)*(p-C));
//     std::cout << "S = " << S << std::endl;

//     return 0;
// }

// Вариант 2.
// Написать программу, которая получает на вход 2 целых числа h и a (0 < h,a < 10^8) – высоту и основание треугольника. Рассчитать площадь треугольника. 
// int main() {
//     int h;
//     int a;
//     int S;
    
//     std::cin >> h;
//     std::cin >> a;

//     S = (a*h)/2;
//     std::cout << "S = " << S << std::endl;

//     return 0;
// }

// Вариант 3.
// Написать программу, которая, используя минимальное количество оперативной памяти рассчитает, периметр прямоугольника со сторонами A и B (0 < A,B < 20). A и B считать с клавиатуры.
// todo: придумать как вводить числа при этом не используя инт
// int main() {
//     unsigned char A;
//     unsigned char B;
//     scanf("%hhu%hhu", &A, &B); //Я не понял как это работает, но нашел на форуме (https://www.cyberforum.ru/cpp-beginners/thread2615607.html)
    
//     std::cout << (2*A+B) << std::endl;

//     return 0;
// }

// Вариант 4.
// Написать программу, которая получает на вход вещественное число R (0 < R < 100) – радиус круга. И рассчитывает площадь круга с точностью до 10^-9.
// int main() {
//     const double PI = 3.141592653;
//     float R;

//     std::cin >> R;
//     std::cout << std::fixed << std::setprecision(9)<< (PI*R*R)<< std::endl; 

//     return 0;
// }

// Вариант 5.
// Написать программу, которая получает на вход стороны прямоугольного параллелепипеда – целые числа A,B,C (0<A,B,C<10^4). И рассчитывает его объем.
// int main() {
//     short int A;
//     short int B;
//     short int C;

//     std::cin >> A;
//     std::cin >> B;
//     std::cin >> C;

//     std::cout << "V = " << (A*B*C) << std::endl;

//     return 0;
// }

// Вариант 6.
// Написать программу, которая по полученным площади основания S (целое, 0<S<100) и высоте h (целое, 0<h<100), вычисляет объем пирамиды.
// int main() {
//     short int S;
//     short int h;

//     std::cin >> S;
//     std::cin >> h;
//     std::cout << std::endl << "V = " << ((S*h)/6) << std::endl;

//     return 0;
// }

// Вариант 7.
// Написать программу, которая рассчитает главную диагональ прямоугольного параллелепипеда. Входные данные – стороны A,B,C (целые числа, 0 < A,B,C < 3*10^4)
// int main() {
//     short int A;
//     short int B;
//     short int C;

//     std::cin >> A;
//     std::cin >> B;
//     std::cin >> C;

//     std::cout << "D = " << sqrt(A*A+B*B+C*C) << std::endl;

//     return 0;
// }

 
// Вариант 8.
// Написать программу, которая, используя минимальное количество оперативное памяти, найдет объем куба по известной стороне A (целое, 0<A<40).
// int main() {
//     unsigned char A;
//     scanf("%hhu", &A); 
    
//     std::cout << (A*A*A) << std::endl;

//     return 0;
// }

// Вариант 9.
// Написать программу, которая рассчитает площадь треугольника по известному углу a, сторонам A и B. Считается, что треугольник существует.
// int main() {
//     int A;
//     int B;
//     int a;

//     std::cin >> A;
//     std::cin >> B;
//     std::cin >> a;

//     std::cout << "S = " << (A*B*sin(a)/2);

//     return 0;
// }
 
// Вариант 10.
// Написать программу для вычисления корня N (вещественное, 0<N<100) степени из числа X (вещественное, 0<X<100).
// int main() {
//     float N;
//     float X;
    
//     std::cin >> X;
//     std::cin >> N;

//     std::cout << std::pow(X, 1.0 / N) << std::endl;

//     return 0;
// }
// Не работает, не знаю почему