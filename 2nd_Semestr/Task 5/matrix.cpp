#include "matrix.hpp"

void Matrix::allocSpace()
{
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i] = new double[cols_];
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = 0;
        }
    }
}

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
        return *this;

    for (int i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;

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
        throw std::invalid_argument("Матрицы должны быть одного размера для сложения");
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
        for (int j = 0; j < cols_; j++)
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
        throw std::invalid_argument("Матрицы должны быть одного размера для сложения");
    }
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] += other.matrix_[i][j];
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
            matrix_[i][j] += num;
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
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] *= num;
        }
    }
    return *this;
}

Matrix &Matrix::operator++()
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j]++;
        }
    }
    return *this;
}

double Matrix::determinant() const
{
    if (rows_ != cols_)
    {
        throw std::invalid_argument("Матрица должна быть квадратной для вычисления определителя");
    }
    if (rows_ == 1)
    {
        return matrix_[0][0];
    }
    else if (rows_ == 2)
    {
        return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    }
    else if (rows_ == 3)
    {
        return matrix_[0][0] * (matrix_[1][1] * matrix_[2][2] - matrix_[1][2] * matrix_[2][1]) -
               matrix_[0][1] * (matrix_[1][0] * matrix_[2][2] - matrix_[1][2] * matrix_[2][0]) +
               matrix_[0][2] * (matrix_[1][0] * matrix_[2][1] - matrix_[1][1] * matrix_[2][0]);
    }
    return 0;
}

double &Matrix::operator()(int i, int j)
{
    if (i >= rows_ || j >= cols_)
    {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return matrix_[i][j];
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < matrix.rows_; i++)
    {
        for (int j = 0; j < matrix.cols_; j++)
        {
            os << std::setw(10) << matrix.matrix_[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix)
{
    for (int i = 0; i < matrix.rows_; i++)
    {
        for (int j = 0; j < matrix.cols_; j++)
        {
            is >> matrix.matrix_[i][j];
        }
    }
    return is;
}

