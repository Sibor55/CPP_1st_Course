/*Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
Найти строку, сумма элементов которой наиболее близка к 0,
и заменить все элементы этой строки числом 0.*/
#include <iostream>

template <int N, int M>
void func(int (&arr)[N][M])
{
    int res = 999;
    int numS = 0;
    for (int i = 0; i < N; i++)
    {
        int sumS = 0;
        for (int j = 0; j < M; j++)
        {
            sumS += arr[i][j];
        }
        if (sumS < res)
        {
            res = sumS;
            numS = i;
        }
    }
    for (int i = 0; i < M; i++)
    {
        arr[numS][i] = 0;
    }
    
}
int main()
{

    int a[4][2] =
        {
            {1234, 56},
            {1212, 33},
            {1434, 80},
            {1312, 78}};

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    func(a);
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
