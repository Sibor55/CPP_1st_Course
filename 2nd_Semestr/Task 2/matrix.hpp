#pragma once
namespace mtx
{
    class matrix
    {
    private:
        int rows, cols; // Количество строк и столбцов
        float **data;   // Массив массивов со значениями

    public:
        // Конструкторы
        matrix();
        matrix(int rows, int cols, bool fill);
        matrix(const matrix &other);
        // Операторы
        matrix &operator=(const matrix &other);      // Оператор присваивания
        matrix operator+(const matrix &other) const; // Оператор сложения
        // Деструктор
        ~matrix();
        // Вывод матрицы на экран
        void print();
    };
}