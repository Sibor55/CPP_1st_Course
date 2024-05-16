// Ввести натуральное число N, обозначающее номер месяца в году.
// Используя оператор switch вывести названия всех месяцев года.
// Предусмотреть обработку ошибочного ввода N.

#include <iostream>

int main() {
    int N;

    std::cin >> N;
    
    // if (!(N>0&&N<13)) {
    //     std::cout << "ERROR, ENTER THE RIGHT NUMBER";
    // }
    // else {

    // }
    switch (N)
    {
    case 1:
        std::cout << "Январь";
        break;
    case 2:
        std::cout << "Февраль";
        break;
    case 3:
        std::cout << "Март";
        break;
    case 4:
        std::cout << "Апрель";
        break;
    case 5:
        std::cout << "Май";
        break;
    case 6:
        std::cout << "Июнь";
        break;
    case 7:
        std::cout << "Июль";
        break;
    case 8:
        std::cout << "Август";
        break;
    case 9:
        std::cout << "Сентябрь";
        break;
    case 10:
        std::cout << "Октябрь";
        break;
    case 11:
        std::cout << "Ноябрь";
        break;
    case 12:
        std::cout << "Декабрь";
        break;
                                                
    default:
        std::cout << "ERROR, ENTER THE RIGHT NUMBER" << std::endl;
        break;
    }
    return 0;
}