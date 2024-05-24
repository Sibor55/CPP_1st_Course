#include "matrix.cpp"

int main()
{
    // Создание и инициализация матрицы m1
    Matrix m1(2, 2);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 4;

    // Создание и инициализация матрицы m2
    Matrix m2(2, 2);
    m2(0, 0) = 5;
    m2(0, 1) = 6;
    m2(1, 0) = 7;
    m2(1, 1) = 8;

    try
    {
        // Умножение матриц m1 и m2 и вывод результата
        Matrix m3 = m1 * m2;
        std::cout << "Matrix m1: " << std::endl
                  << m1 << std::endl;
        std::cout << "Matrix m2: " << std::endl
                  << m2 << std::endl;
        std::cout << "Matrix m3 (m1 * m2): " << std::endl
                  << m3 << std::endl;

        // Вычисление и вывод определителя матрицы m1
        std::cout << "Определитель m1: " << m1.determinant() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}
