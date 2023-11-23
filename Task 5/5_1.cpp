/*
Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
Если в последовательности есть хотя бы одно число, начинающееся цифрой 1,
упорядочить последовательность по неубыванию.
*/
#include <iostream>
#include <string>
bool IsStartWOne(int num) {
    std::string strNum = std::to_string(num);
    return strNum[0] == '1';

}

template<size_t N> 

int* func(int (&arr)[N])
/*
Функция прогоняет массив и проверяет начинается ли число на 1
Потом брейкает цикл проверки и начинает сортировку вставкой
Выводим массив либо изначальный, если массив не прошел проверку, либо сортированный
*/{
for (size_t i = 0; i < N; i++)
{
    if (IsStartWOne(arr[i])) //Проверка на цифру 1
    {
        break;
        for (size_t j = 2; j < N; j++) // Начало сортировки
        {
            int key = arr[j];
            int a = j-1;
            while (a >= 0 && arr[a] > key)
            {
                arr[a+1] = arr[a];
                a = a - 1;
            }
            arr[a+1] = key;
            

        }
    }

    
}

 for (size_t i = 0; i < N; i++) 
 { 
  std::cout << arr[i] << ' '; 
 } 
 return arr; 
} 
 
int main() 
{ 
int a[] = { 210, 20, 31, 5, 312 }; 
func(a); 

return 0;
}