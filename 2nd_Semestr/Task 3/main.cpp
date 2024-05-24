/* Реализуйте класс String для работы со строками.
 Понятное дело, что std::string для реализации использовать нельзя,
  только char.

У вас должны быть реализованы:
1.	Базовый конструктор
2.	Конструктор копирования (правило 3-х)
3.	Оператор присваивания копированием (правило 3-х)
4.	Деструктор (правило 3-х)
5.	Операторы + и +=
6.	Оператор [] – чтение и изменение элемента
7.	Операторы <, >, ==
8.	Операторы ввода и вывода в поток
9.	Метод find – поиск первого вхождения символа в строку слева
10.	 Метод length – длина строки
11.	 Метод c_str – получить массив char
12.	 Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки

Продемонстрируйте работу вашего класса. Будьте готовы объяснить написанное.

 */
#include <iostream>
#include <cstring> // Для функции strlen

class string
{
private:
  char *m_str;
  size_t length;

public:
  // Базовый конструктор
  string() : m_str(nullptr), length(0) {}

  // Конструктор из C-строки
  string(const char *str)
  {
    if (str)
    {
      length = std::strlen(str);
      m_str = new char[length + 1];
      std::strcpy(m_str, str);
    }
    else
    {
      m_str = nullptr;
      length = 0;
    }
  }

  // Конструктор копирования
  string(const string &other) : length(other.length)
  {
    m_str = new char[length + 1];
    std::strcpy(m_str, other.m_str);
  }

  // Деструктор
  ~string()
  {
    delete[] m_str;
  }

  // Оператор присваивания копированием
  string &operator=(const string &other)
  {
    if (this != &other)
    {
      delete[] m_str;
      length = other.length;
      m_str = new char[length + 1];
      std::strcpy(m_str, other.m_str);
    }
    return *this;
  }

  // Метод для получения длины строки
  size_t len() const
  {
    return length;
  }

  // Метод для поиска первого вхождения символа
  size_t find(char c) const
  {
    for (size_t i = 0; i < length; ++i)
    {
      if (m_str[i] == c)
      {
        return i;
      }
    }
    return std::string::npos;
  }

  // Метод для получения C-строки
  const char *c_str() const
  {
    return m_str;
  }

  // Метод at с проверкой на выход за пределы строки
  char &at(size_t index)
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return m_str[index];
  }

  const char &at(size_t index) const
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return m_str[index];
  }

  // Оператор []
  char &operator[](size_t index)
  {
    return m_str[index];
  }

  const char &operator[](size_t index) const
  {
    return m_str[index];
  }

  // Операторы сравнения
  bool operator<(const string &other) const
  {
    return std::strcmp(m_str, other.m_str) < 0;
  }

  bool operator>(const string &other) const
  {
    return std::strcmp(m_str, other.m_str) > 0;
  }

  bool operator==(const string &other) const
  {
    return std::strcmp(m_str, other.m_str) == 0;
  }

  // Операторы + и +=
  string operator+(const string &other) const
  {
    size_t new_length = length + other.length;
    char *new_str = new char[new_length + 1];
    std::strcpy(new_str, m_str);
    std::strcat(new_str, other.m_str);

    string result(new_str);
    delete[] new_str;
    return result;
  }

  string &operator+=(const string &other)
  {
    *this = *this + other;
    return *this;
  }

  // Операторы ввода и вывода в поток
  friend std::ostream &operator<<(std::ostream &os, const string &str)
  {
    if (str.m_str)
    {
      os << str.m_str;
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, string &str)
  {
    char buffer[1000];
    is >> buffer;
    str = string(buffer);
    return is;
  }
};
int main()
{
  string a = "abacasfas";
  string b = "caacaca";
  std::cout << a << std::endl;

  return 0;
}
