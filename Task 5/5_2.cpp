/*
Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
Упорядочить последовательность по неубыванию первой цифры числа,
числа с одинаковыми первыми цифрами дополнительно упорядочить по
неубыванию суммы цифр числа, числа с одинаковыми первыми цифрами
и одинаковыми суммами цифр дополнительно упорядочить по неубыванию
самого числа.
*/
#include <iostream>
#include <string>
int digitsum(int num) {
    int sum = 0;
    int temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;

    }
    return sum;
}
bool is_inverted(int num0, int num1) {
    // Проверка каждого критерия
    std::string strNum0 = std::to_string(num0);
    std::string strNum1 = std::to_string(num1);
    return strNum0[0] < strNum1[0] || (digitsum(num0) < digitsum(num1) && strNum0[0] == strNum1[0]) || (num0 < num1 && digitsum(num0) == digitsum(num1) && strNum0[0] == strNum1[0]);

}

template<size_t N> 

int* func(int (&arr)[N]) {
    for (size_t j = 1; j < N; j++) // Начало сортировки
    {
        int key = arr[j];
        int a = j-1;
        while (a >= 0 && is_inverted(key,arr[a]))
        {
            arr[a+1] = arr[a];
            a = a - 1;
        }
        arr[a+1] = key;
        

    }
    
    for (size_t i = 0; i < N; i++) 
    { 
        std::cout << arr[i] << ' '; 
    } 
    return arr; 
} 
 
int main() 
{ 
int a[] = { 42, 17, 89, 5, 63, 28, 91, 10, 55, 76 }; 
func(a); 

return 0;
}