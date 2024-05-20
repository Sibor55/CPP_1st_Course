// Реализуйте шаблонный класс для описания матриц (в частном случае, векторов).
// Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
// В составе класса должны быть:
// 1.     Конструктор копирования
// 2.     Оператор присваивания копированием
// 3.     Оператор ввода и выводаgc
// 4.     Операторы +, +=, *, *=
// 5.     Оператор ++, который увеличивает все элементы матрицы на 1
// 6.     Метод вычисления определителя
// 7.     Метод или оператор для получения и изменения элемента матрицы по индексу

// Продемонстрируйте работу с классом.
#include <iostream>
#include <stdexcept>


class Matrix
{
private:
    int rows_, cols_;
    double **matrix_;
    // Функция выделения памяти для двумерного массива
    void allocSpace()
    {
        matrix_ = new double *[rows_];
        for (int i = 0; i < rows_; i++)
        {
            matrix_[i] = new double[cols_];
        }
    }

public:
    // Конструктор с параметрами
    Matrix(int, int);
    // Конструктор с двойного массива
    Matrix(double **, int, int);
    // Базовый конструктор
    Matrix();
    // Деструктор
    ~Matrix();
    // Конструктор копирования
    Matrix(const Matrix &);
    // Оператор присваивания копированием
    Matrix &operator=(const Matrix &);

    // Операторы сложения
    Matrix operator+(const Matrix &) const;
    Matrix operator+(const int &) const;
    Matrix &operator+=(const Matrix &);
    Matrix &operator+=(const int &);
    Matrix &operator++();

    // Операторы умножения
    Matrix operator*(const Matrix &) const;
    Matrix operator*(const int &) const;
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(const int &);
    
};



Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
}

Matrix::Matrix(double **arr, int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = arr[i][j];
        }
    }
}

Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

Matrix::~Matrix()
{
    for (int i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

Matrix::Matrix(const Matrix &other) : rows_(other.rows_), cols_(other.cols_)
{
    allocSpace();
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this; // Проверка на самоприсваивание

    // Освобождаем текущую память
    for (int i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;

    // Копируем размеры и данные из другого объекта
    rows_ = other.rows_;
    cols_ = other.cols_;
    allocSpace();
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
    {
        throw std::invalid_argument("Матрицы не могут быть умножены: несоответствие размеров");
    }

    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const int &num) const
{
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; i < cols_; j++)
        {
            result.matrix_[i][j] = matrix_[i][j] + num;
        }
    }
    return result;
}

Matrix &Matrix::operator+=(const Matrix &other)
{

    if (rows_ != other.rows_ || cols_ != other.cols_)
    {
        throw std::invalid_argument("Матрицы не могут быть умножены: несоответствие размеров");
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const int &num)
{

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = matrix_[i][j] + num;
        }
    }
    return *this;
}


Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols_ != other.rows_)
    {
        throw std::invalid_argument("Матрицы не могут быть умножены: несоответствие размеров");
    }

    Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < other.cols_; ++j)
        {
            result.matrix_[i][j] = 0;
            for (int k = 0; k < cols_; ++k)
            {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const int &num) const
{
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            result.matrix_[i][j] = matrix_[i][j] * num;
        }
    }
    return result;
}

// Matrix &Matrix::operator*=(const Matrix &other)
// {
//     if (cols_ != other.rows_)
//     {
//         throw std::invalid_argument("Матрицы не могут быть умножены: несоответствие размеров");
//     }
//     Matrix result(rows_, other.cols_);
//     for (int i = 0; i < rows_; ++i)
//     {
//         for (int j = 0; j < other.cols_; ++j)
//         {
//             result.matrix_[i][j] = 0;
//             for (int k = 0; k < cols_; ++k)
//             {
//                 result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
//             }
//         }
//     }
//     *this = result;
//     return *this;
// }

Matrix &Matrix::operator*=(const Matrix &other)
{
    if (cols_ != other.rows_)
    {
        throw std::invalid_argument("Матрицы не могут быть умножены: несоответствие размеров");
    }

    Matrix result = (*this) * other;
    *this = result;
    return *this;
}

Matrix &Matrix::operator*=(const int &num)
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; i < cols_; j++)
        {
            matrix_[i][j] *= num;

        }
    }
    return *this;
}

int main()
{
    Matrix m1(3, 3);
    Matrix m2(3, 3);
    m1 += 12;
    m2 += 12;
    m1 *= m2;
    
    
    
    return 0;
}
