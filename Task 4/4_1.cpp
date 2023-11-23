// Дана последовательность натуральных чисел {Aj}.
// Найти произведение чисел, оканчивающихся цифрой 2 или 4,
// наименьшее из таких чисел и номер этого числа в последовательности.
#include <iostream>
#include <string>

 

int main() {
    int minx = 99999;
    int minindx;
    int ArrSz = 5;
    std::string tmpstr;

    int Aj[ArrSz] = {6,145,124,27,3};
    for (int i = 0; i < ArrSz; i++) {
        for (int j = i+1; j < ArrSz; j++) {
            // if ((Aj[i]*Aj[j])  || (Aj[i]*Aj[j]) % 4 == 0 ) {
            //     if ()
            // }
            std::string tmpstr = std::to_string(Aj[i]*Aj[j]);
            if (tmpstr.back()=='4' || tmpstr.back()=='2') {
                if (minx>Aj[i]) {
                    minx = Aj[i];
                    minindx = i;
                }
                if (minx>Aj[j]) {
                    minx = Aj[j];
                    minindx = j;
                }
            }
        }
    }
    std::cout << minx << std::endl << minindx;
    // int a = 5;
    // int b = 6;
    // std::cout << std::min(a,b);
    return 0;
    }