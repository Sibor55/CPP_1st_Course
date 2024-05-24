#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Matrix
{
private:
    int rows_, cols_;
    double **matrix_;

    // Выделение памяти для матрицы и инициализация нулями
    void allocSpace();

public:
    // Конструкторы
    Matrix(int rows, int cols);
    Matrix(double **arr, int rows, int cols);
    Matrix();

    // Деструктор
    ~Matrix();

    // Конструктор копирования
    Matrix(const Matrix &other);

    // Оператор присваивания
    Matrix &operator=(const Matrix &other);

    // Оператор сложения матриц
    Matrix operator+(const Matrix &other) const;

    // Оператор сложения матрицы с числом
    Matrix operator+(const int &num) const;

    // Оператор добавления матрицы
    Matrix &operator+=(const Matrix &other);

    // Оператор добавления числа
    Matrix &operator+=(const int &num);

    // Оператор умножения матриц
    Matrix operator*(const Matrix &other) const;

    // Оператор умножения матрицы на число
    Matrix operator*(const int &num) const;

    // Оператор умножения матрицы на другую матрицу и присваивания результата
    Matrix &operator*=(const Matrix &other);

    // Оператор умножения матрицы на число и присваивания результата
    Matrix &operator*=(const int &num);

    // Оператор инкремента
    Matrix &operator++();

    // Вычисление определителя матрицы (только для квадратных матриц)
    double determinant() const;

    // Оператор доступа к элементам матрицы
    double &operator()(int i, int j);

    // Оператор вывода матрицы
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    // Оператор ввода матрицы
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);
};

#endif // MATRIX_HPP
