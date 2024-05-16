#include "matrix.hpp"
#include <iostream>

namespace mtx
{
    // Конструктор по умолчанию
    matrix::matrix()
    {
        this->rows = 1;
        this->cols = 1;

        // Выделение памяти под матрицу и инициализация значением по умолчанию
        this->data = new float *[1];
        this->data[0] = new float[1];
        this->data[0][0] = 0;
    }

    // Конструктор с параметрами
    matrix::matrix(int rows, int cols, bool fill)
    {
        this->rows = rows;
        this->cols = cols;

        // Выделение памяти под матрицу
        this->data = new float *[this->rows];
        for (size_t i = 0; i < rows; i++)
            this->data[i] = new float[this->cols];

        // Заполнение матрицы значениями, если fill == true, иначе заполнение нулями
        if (fill)
        {
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                {
                    std::cout << "Введите значение для (" << i << ',' << j << ") -> ";
                    std::cin >> this->data[i][j];
                };
            std::cout << std::endl;
        }
        else
        {
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    this->data[i][j] = 0;
        }
    }

    // Конструктор копирования
    matrix::matrix(const matrix &other) : matrix(other.rows, other.cols, false)
    {

        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
            {
                this->data[i][j] = other.data[i][j];
            };
    }

    // Оператор присваивания
    matrix &matrix::operator=(const matrix &other)
    {
        if (this != &other) // Проверка на самоприсваивание
        {
            // Освобождение памяти от текущих данных
            for (int i = 0; i < this->rows; i++)
                delete[] this->data[i];
            delete[] this->data;

            // Копирование размеров
            this->rows = other.rows;
            this->cols = other.cols;

            // Выделение памяти под новые данные
            this->data = new float *[this->rows];
            for (int i = 0; i < this->rows; i++)
                this->data[i] = new float[this->cols];

            // Копирование данных
            for (int i = 0; i < this->rows; i++)
                for (int j = 0; j < this->cols; j++)
                    this->data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Оператор сложения
    matrix matrix::operator+(const matrix &other) const
    {
        if (rows != other.rows || cols != other.cols) // Проверка размерностей матриц
        {
            std::cerr << "Размерность матриц должна быть одинакова!\n";
            return matrix();
        }

        // Создание матрицы для результата сложения, без заполнения
        matrix result(rows, cols, false);
        // Сложение соответствующих элементов матриц
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    // Деструктор
    matrix::~matrix()
    {

        for (size_t i = 0; i < rows; i++)
            delete[] this->data[i];
        delete[] this->data;
    }

    // Метод для вывода матрицы на экран
    void matrix::print()
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                std::cout << data[i][j] << '\t';
            }
            std::cout << std::endl;
        }
    }
}