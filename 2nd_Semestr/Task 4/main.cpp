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
  static const int base = 1000000; // База для хранения больших чисел
  std::vector<int> digits;         // Вектор для хранения цифр числа
  bool negative;                   // Флаг для отрицательности числа

public:
  // Конструктор по умолчанию
  BigInt() : negative(false) {}

  // Конструктор по целому числу
  BigInt(int number)
  {
    // Определение знака числа
    if (number < 0)
    {
      negative = true;
      number = -number; // Получение абсолютного значения числа
    }
    else
    {
      negative = false;
    }

    // Если число равно нулю, добавляем одну цифру 0
    if (number == 0)
    {
      digits.push_back(0);
      return;
    }

    // Разбиваем число на цифры и сохраняем в вектор
    while (number > 0)
    {
      digits.push_back(number % base); // Получаем остаток от деления на базу
      number /= base;                  // Уменьшаем число на базу
    }
  }

  // Конструктор по строке
  BigInt(const std::string &number)
  {
    int start = 0;
    if (number[0] == '-') // Если число отрицательное
    {
      negative = true;
      start = 1;
    }
    else
    {
      negative = false;
    }

    // Разбиваем строку на группы по 6 цифр и сохраняем в вектор
    for (int i = number.size() - 1; i >= start; i -= 6)
    {
      int digit = 0;
      for (int j = std::max(start, i - 5); j <= i; ++j)
      {
        digit = digit * 10 + (number[j] - '0'); // Преобразуем символы в числа
      }
      digits.push_back(digit);
    }
  }

  // Конструктор копирования
  BigInt(const BigInt &other) : digits(other.digits), negative(other.negative) {}

  // Оператор присваивания
  BigInt &operator=(const BigInt &other)
  {
    if (this != &other)
    {
      digits = other.digits;     // Копируем цифры
      negative = other.negative; // Копируем флаг отрицательности
    }
    return *this;
  }

  // Деструктор
  ~BigInt() {}

  // Оператор вычитания
  BigInt operator-(const BigInt &other) const
  {
    // Если знаки чисел разные, возвращаем результат сложения чисел с абсолютным значением другого числа
    if (negative != other.negative)
    {
      BigInt absOther = other;
      absOther.negative = false;
      return *this + absOther;
    }

    BigInt result;
    int borrow = 0;
    // Вычитаем каждую цифру вектора other из соответствующей цифры вектора digits
    for (size_t i = 0; i < std::max(digits.size(), other.digits.size()); ++i)
    {
      int digit = (i < digits.size() ? digits[i] : 0) - borrow;
      if (i < other.digits.size())
        digit -= other.digits[i];
      borrow = (digit < 0);
      if (borrow)
        digit += base;
      result.digits.push_back(digit);
    }

    // Удаляем ведущие нули
    while (result.digits.size() > 1 && result.digits.back() == 0)
      result.digits.pop_back();

    // Устанавливаем знак результата
    result.negative = (negative && !other.negative) || (!negative && other.negative);

    return result;
  }

  // Оператор сложения
  BigInt operator+(const BigInt &other) const
  {
    // Если знаки чисел разные, возвращаем результат вычитания чисел
    if (negative != other.negative)
    {
      return *this - other;
    }

    BigInt result = *this;
    int carry = 0;
    // Складываем каждую цифру вектора other с соответствующей цифрой вектора digits
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
    result.digits.resize(digits.size() + other.digits.size()); // Устанавливаем размер результата
    for (size_t i = 0; i < digits.size(); ++i)
    {
      for (size_t j = 0, carry = 0; j < other.digits.size() || carry; ++j)
      {
        long long cur = result.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry; // Вычисляем текущий результат умножения

        result.digits[i + j] = cur % base; // Сохраняем текущую цифру
        carry = cur / base;                // Вычисляем перенос
      }
    }
    // Удаляем ведущие нули
    while (result.digits.size() > 1 && result.digits.back() == 0)
      result.digits.pop_back();
    // Устанавливаем знак результата
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

  // Оператор равенства
  bool operator==(const BigInt &other) const
  {
    return !(*this < other) && !(other < *this);
  }

  // Оператор неравенства
  bool operator!=(const BigInt &other) const
  {
    return !(*this == other);
  }

  // Оператор вывода
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

  // Оператор ввода
  friend std::istream &operator>>(std::istream &is, BigInt &number)
  {
    std::string str;
    is >> str;
    number = BigInt(str);
    return is;
  }
};

int main()
{
  std::string a_str, b_str;
  std::cout << "Введите два числа" << std::endl;
  std::cin >> a_str >> b_str;
  BigInt a(a_str), b(b_str);

  if (a < b)
  {
    std::cout << "a < b" << std::endl;
  }

  if (a > b)
  {
    std::cout << "a < b" << std::endl;
  }

  if (a == b)
  {
    std::cout << "a = b" << std::endl;
  }

  BigInt sum = a + b;
  BigInt subtr = a - b;
  BigInt product = a * b;
  std::cout << "a + b = " << sum << std::endl;
  std::cout << "a - b = " << subtr << std::endl;
  std::cout << "a * b = " << product << std::endl;

  return 0;
}
