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

class string
{
private:
  char *m_str;
  size_t length;

public:
  string() : m_str(nullptr), length(0){};
  string(const char *str);
  string(const string &other);
  // Методы
  void print(int index = -1);
  size_t len();
  size_t find(char c);
  // todo: дописать методы
  char &at(size_t index);
  char *c_str();

  string &operator=(const string &other);
  string operator+(const string &other) const;
  string &operator+=(const string &other);

  // // Оператор []
  char &operator[](size_t index);

  // // Операторы сравнения
  int compare(const string &other) const;
  bool operator<(const string &other) const;
  bool operator>(const string &other) const;
  bool operator==(const string &other) const;
  ~string();
};

string::string(const char *str)
{
  length = 0;
  while (str[length] != '\0')
  {
    ++length;
  }
  m_str = new char[length + 1];
  for (size_t i = 0; i < length; i++)
  {
    m_str[i] = str[i];
  }
  m_str[length] = '\0';
}

string::string(const string &other) : length(other.length)
{
  m_str = new char[length + 1];
  for (size_t i = 0; i < length; i++)
    m_str[i] = other.m_str[i];
  m_str[length] = '\0';
}

void string::print(int index)
{
  if (index < 0)
  {
    std::cout << m_str << std::endl;
  }
  else if (index >= length)
  {
    std::cerr << "Index out of bounds" << std::endl;
  }
  else
  {
    std::cout << m_str[index] << std::endl;
  }
}

size_t string::len()
{
  return this->length;
}

size_t string::find(char c)
{

  for (size_t i = 0; i < length; i++)
    if (m_str[i] == c)
      return i;

  return 0;
}

char &string::at(size_t index)
{
  if (index >= length)
  {
    std::cerr << "Index out of bounds" << std::endl;
  }
  return m_str[index];
}

char *string::c_str()
{
  return this->m_str;
}

string &string::operator=(const string &other)
{
  if (this != &other)
  {
    delete[] m_str;
    length = other.length;
    m_str = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
      m_str[i] = other.m_str[i];
    }
    m_str[length] = '\0';
  }
  return *this;
}

string string::operator+(const string &other) const
{
  size_t result_length = length + other.length;
  char *temp = new char[result_length + 1];

  for (size_t i = 0; i < length; i++)
  {
    temp[i] = m_str[i];
  }
  for (size_t i = 0; i < other.length; i++)
  {
    temp[length + i] = other.m_str[i];
  }
  temp[result_length] = '\0';

  string result(temp);
  delete[] temp;
  return result;
}

string &string::operator+=(const string &other)
{
  size_t result_length = length + other.length;
  char *temp = new char[result_length + 1];

  for (size_t i = 0; i < length; i++)
  {
    temp[i] = m_str[i];
  }
  for (size_t i = 0; i < other.length; i++)
  {
    temp[length + i] = other.m_str[i];
  }
  temp[result_length] = '\0';

  delete[] m_str;
  m_str = temp;
  length = result_length;
  return *this;
}

char &string::operator[](size_t index)
{
  if (index >= length)
  {
    std::cerr << "Index out of bounds" << std::endl;
  }
  return m_str[index];
}
int string::compare(const string &other) const
{
  const char *str1 = m_str;
  const char *str2 = other.m_str;

  while (*str1 && *str2 && *str1 == *str2)
  {
    ++str1;
    ++str2;
  }

  if (*str1 < *str2)
  {
    return -1;
  }
  if (*str1 > *str2)
  {
    return 1;
  }
  return 0;
}
bool string::operator<(const string &other) const
{
  return compare(other) == -1;
}
bool string::operator>(const string &other) const
{
  return compare(other) == 1;
}
bool string::operator==(const string &other) const
{
  return compare(other) == 0;
}

string::~string()
{
  delete[] m_str;
}
// Я не знаю почему это не работает. 
std::ostream &operator<<(std::ostream &stream, const string &str)
{
  stream << str.m_str;
  return stream;
}
std::ostream &operator>>(std::ostream &stream, string &str)
{
  char temp[1000];
  stream >> temp;
  str = string(temp);
  return stream;
}

int main()
{
  string a = "abacasfas";
  string b = "caacaca";
  std::cout << a << std::endl;

  return 0;
}
