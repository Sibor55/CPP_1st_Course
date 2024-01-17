#pragma once
#include <iostream>

// Различные операции над статическими матрицами
namespace mtrx
{
    // Вычисляет абсолютное значение числа
    int module(int a)
    {
        if (a < 0)
        {
            a = a * -1;
        }
        return a;
    }

    // Проверяет, является ли число простым
    bool is_prime(int n)
    {
        if (n == 2 || n == 3)
            return true;
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    // Выводит элементы матрицы
    template <int ROWS, int COLS>
    void print_matrix(int (&matrix)[ROWS][COLS])
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Получает элементы определенного столбца матрицы
    template <int ROWS, int COLS>
    void get_col(int (&matrix)[ROWS][COLS], int col, int (&result)[ROWS])
    {
        for (size_t i = 0; i < ROWS; i++)
        {
            result[i]=matrix[i][col];
        }
        
        
        // std::copy(&matrix[0][col], &matrix[ROWS-1][col], result);
    }

    // Получает элементы определенной строки матрицы
    template <int ROWS, int COLS>
    void get_row(int (&matrix)[ROWS][COLS], int row, int (&result)[COLS])
    {
        std::copy(&matrix[row][0], &matrix[row][COLS], result);
    }

    // Вставляет строку в матрицу на заданную позицию
    template <int ROWS, int COLS>
    void insert_row(int (&matrix)[ROWS][COLS], int (&myrow)[COLS], int target_row)
    {
        for (size_t i = 0; i < COLS; i++)
        {
            matrix[target_row][i] = myrow[i];
        }
    }

    // Вычисляет сумму абсолютных значений элементов строки матрицы
    template <int ROWS, int COLS>
    int row_arr_sum(int (&matrix)[ROWS][COLS], int row)
    {
        int a[COLS];
        get_row(matrix, row, a);
        int sum = 0;
        for (size_t i = 0; i < COLS; i++)
        {
            sum += module(a[i]);
        }
        return sum;
    }

    // Проверяет, равны ли два массива
    template <int n>
    bool eq_arr_check(int (&f_arr)[n], int (&s_arr)[n])
    {
        for (size_t i = 0; i < n; i++)
        {
            if (f_arr[i] != s_arr[i])
            {
                return false;
            }
        }
        return true;
    }

    // Проверяет, содержит ли матрица простое число
    template <int ROWS, int COLS>
    bool prime_matrix(int (&matrix)[ROWS][COLS])
    {
        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++)
            {
                if (is_prime(module(matrix[i][j])))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Проверяет, равны ли два столбца матрицы
    template <int ROWS, int COLS>
    bool eq_col_check(int (&matrix)[ROWS][COLS])
    {
        int tmp1[ROWS];
        int tmp2[ROWS];
        for (size_t i = 0; i < COLS; i++)
        {
        
            for (size_t j = 0; j < COLS; j++)
            {
                if (i == j)
                {
                    continue;
                }
                get_col(matrix, i, tmp1);
                get_col(matrix, j, tmp2);
                if (eq_arr_check(tmp1, tmp2))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Меняет местами две строки матрицы
    template <int ROWS, int COLS>
    void swap_row(int (&matrix)[ROWS][COLS], int f_row, int s_row)
    {
        int temp[COLS];
        get_row(matrix, f_row, temp);
        for (size_t i = 0; i < COLS; i++)
        {
            matrix[f_row][i] = matrix[s_row][i];
        }
        for (size_t i = 0; i < COLS; i++)
        {
            matrix[s_row][i] = temp[i];
        }
    }

    // Сортирует строки матрицы по сумме элементов
    template <int ROWS, int COLS>
    void sort_rows(int (&matrix)[ROWS][COLS])
    {
        for (size_t i = 1; i < ROWS; i++)
        {
            // print_matrix(matrix);
            int key = row_arr_sum(matrix, i);
            int key_row[COLS];
            get_row(matrix, i, key_row);
            int j = i - 1;
            while (j >= 0 && row_arr_sum(matrix, j) > key)
            {
                swap_row(matrix, j + 1, j);
                j--;
            }
            insert_row(matrix, key_row, j + 1);
        }

        // for (size_t i = 0; i < ROWS; i++)
        // {
        //     int f = 0;
        //     int min = i;
        //     for (size_t j = i; j < ROWS-1-i; i++)
        //     {
        //         if (row_arr_sum(matrix,j)>row_arr_sum(matrix,j+1));
        //         {
        //             swap_row(matrix,j,j+1);
        //             f = 1;
        //         }
        //         if (row_arr_sum(matrix,j)<row_arr_sum(matrix,min))
        //         {
        //             min = j;
        //         }

        //     }
        //     if (f == 0)
        //     {
        //         break;
        //     }
        //     if (min!=i)
        //     {
        //         swap_row(matrix,i,min);
        //     }
    }
}
