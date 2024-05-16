// Задача №4
// “Длинная арифметика”

// Реализуйте класс BigInt для работы со большими целыми числами
// (количество цифр в числе не превосходит 1000).

// У вас должны быть реализованы:
// 1.	Базовый конструктор
// 2.	Конструктор копирования (если необходим)
// 3.	Оператор присваивания копированием (если необходим)
// 4.	Деструктор (если необходим)
// 5.	Операторы + и +=
// 6.	Операторы * и *=
// 7.	Операторы <, >, ==, !=
// 8.	Операторы ввода и вывода в поток

// Продемонстрируйте работу вашего класса. Будьте готовы объяснить написанное.

#include <iostream>
#include <vector>
#include <string>

class BigInt
{
private:
    static const int base = 1000000;
    std::vector<int> digits;
    bool negative;

public:
    // Базовый конструктор
    BigInt() : negative(false) {}

    // Конструктор из целого числа
    BigInt(int number)
    {
        if (number < 0)
        {
            negative = true;
            number = -number;
        }
        else
        {
            negative = false;
        }
        if (number == 0)
        {
            digits.push_back(0);
            return;
        }
        while (number > 0)
        {
            digits.push_back(number % base);
            number /= base;
        }
    }

    // Конструктор из строки
    BigInt(const std::string &number)
    {
        int start = 0;
        if (number[0] == '-')
        {
            negative = true;
            start = 1;
        }
        else
        {
            negative = false;
        }
        for (int i = number.size() - 1; i >= start; i -= 6)
        {
            int digit = 0;
            for (int j = std::max(start, i - 5); j <= i; ++j)
            {
                digit = digit * 10 + (number[j] - '0');
            }
            digits.push_back(digit);
        }
    }

    // Конструктор копирования
    BigInt(const BigInt &other) : digits(other.digits), negative(other.negative) {}

    // Оператор присваивания копированием
    BigInt &operator=(const BigInt &other)
    {
        if (this != &other)
        {
            digits = other.digits;
            negative = other.negative;
        }
        return *this;
    }

    // Деструктор
    ~BigInt() {}

    // Оператор сложения
    BigInt operator+(const BigInt &other) const
    {
        BigInt result = *this;
        if (negative != other.negative)
        {
            return result - other;
        }
        int carry = 0;
        for (size_t i = 0; i < std::max(digits.size(), other.digits.size()) || carry; ++i)
        {
            if (i == result.digits.size())
                result.digits.push_back(0);
            result.digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = result.digits[i] >= base;
            if (carry)
                result.digits[i] -= base;
        }
        return result;
    }

    // Оператор умножения
    BigInt operator*(const BigInt &other) const
    {
        BigInt result;
        result.digits.resize(digits.size() + other.digits.size());
        for (size_t i = 0; i < digits.size(); ++i)
        {
            for (size_t j = 0, carry = 0; j < other.digits.size() || carry; ++j)
            {
                long long cur = result.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = cur % base;
                carry = cur / base;
            }
        }
        while (result.digits.size() > 1 && result.digits.back() == 0)
            result.digits.pop_back();
        result.negative = (negative != other.negative) && (result.digits.size() != 1 || result.digits[0] != 0);
        return result;
    }

    // Оператор меньше
    bool operator<(const BigInt &other) const
    {
        if (negative != other.negative)
            return negative;
        if (digits.size() != other.digits.size())
            return (digits.size() < other.digits.size()) ^ negative;
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] != other.digits[i])
                return (digits[i] < other.digits[i]) ^ negative;
        return false;
    }

    // Оператор больше
    bool operator>(const BigInt &other) const
    {
        return other < *this;
    }

    // Оператор равно
    bool operator==(const BigInt &other) const
    {
        return !(*this < other) && !(other < *this);
    }

    // Оператор не равно
    bool operator!=(const BigInt &other) const
    {
        return !(*this == other);
    }

    // Оператор меньше или равно
    bool operator<=(const BigInt &other) const
    {
        return !(other < *this);
    }

    // Оператор больше или равно
    bool operator>=(const BigInt &other) const
    {
        return !(*this < other);
    }

    // Оператор вывода в поток
    friend std::ostream &operator<<(std::ostream &os, const BigInt &number)
    {
        if (number.negative)
            os << '-';
        os << (number.digits.empty() ? 0 : number.digits.back());
        for (int i = number.digits.size() - 2; i >= 0; --i)
        {
            os << number.digits[i];
        }
        return os;
    }

    // Оператор ввода из потока
    friend std::istream &operator>>(std::istream &is, BigInt &number)
    {
        std::string str
        is >> str;
        number = BigInt(str);
        return is;
    }
};
int main()
{

    std::string a_str, b_str;
    std::cin >> a_str >> b_str;
    BigInt a(a_str), b(b_str);

    if (a < b)
    {
        std::cout << "a<b" << std::endl;
    }
    else
    {
        std::cout << "a>b" << std::endl;
    }
}
