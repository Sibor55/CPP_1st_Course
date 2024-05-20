// Реализуйте шаблонный класс для описания матриц (в частном случае, векторов).
// Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
// В составе класса должны быть:
// 1.     Конструктор копирования
// 2.     Оператор присваивания копированием
// 3.     Оператор ввода и вывода
// 4.     Операторы +, +=, *, *=
// 5.     Оператор ++, который увеличивает все элементы матрицы на 1
// 6.     Метод вычисления определителя
// 7.     Метод или оператор для получения и изменения элемента матрицы по индексу

// Продемонстрируйте работу с классом.

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
    for (int i = 0; i < rows_; ++i)
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
    for (int i = 0; i < rows_; ++i)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;

    // Копируем размеры и данные из другого объекта
    rows_ = other.rows_;
    cols_ = other.cols_;
    allocSpace();
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
    return *this;
}
int main()
{
    return 0;
}
