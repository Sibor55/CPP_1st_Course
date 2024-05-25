#include <vector>
#include <stdexcept>

class BoolVector
{
private:
    // Вектор байтов
    std::vector<unsigned char> data;
    // Количество битов (булевых значений)
    size_t bits;

    // Проверка корректности индекса
    void check_index(size_t index) const
    {
        if (index >= bits)
        {
            throw std::out_of_range("Индекс вне диапазона");
        }
    }

public:
    // Конструктор по умолчанию
    BoolVector() : bits(0) {}

    // Метод добавления в конец вектора
    void push_back(bool value)
    {
        // Если количество бит кратно 8, добавляем новый байт
        if (bits % 8 == 0)
        {
            data.push_back(0);
        }
        // Если добавляемое значение равно 1
        if (value)
        {
            // Определяем последний байт (bits / 8)
            // Сдвигаем 1 на (bits % 8) позиций, чтобы установить бит в нужной позиции
            data[bits / 8] |= (1 << (bits % 8)); // Устанавливаем бит в 1
        }
        ++bits;
    }

    // Метод получения значения по индексу
    bool at(size_t index) const
    {
        check_index(index);
        // Сдвигаем байт вправо на (index % 8) позиций и проверяем, установлен ли бит
        return (data[index / 8] >> (index % 8)) & 1;
    }

    // Оператор получения значения по индексу
    bool operator[](size_t index) const
    {
        return at(index);
    }

    // Оператор изменения значения по индексу
    void set(size_t index, bool value)
    {
        check_index(index);
        if (value)
        {
            // Устанавливаем бит в 1
            data[index / 8] |= (1 << (index % 8));
        }
        else
        {
            // Сбрасываем бит в 0
            data[index / 8] &= ~(1 << (index % 8));
        }
    }

    // Метод size
    size_t size() const
    {
        return bits;
    }

    // Метод insert
    void insert(size_t index, bool value)
    {
        if (index > bits)
        {
            throw std::out_of_range("Индекс вне диапазона");
        }
        data.insert(data.begin() + (index / 8), 0);
        for (size_t i = bits; i > index; --i)
        {
            set(i, at(i - 1));
        }
        set(index, value);
        ++bits;
    }

    // Метод erase
    void erase(size_t index)
    {
        check_index(index);
        for (size_t i = index; i < bits - 1; ++i)
        {
            set(i, at(i + 1));
        }
        --bits;
        if (bits % 8 == 0)
        {
            data.pop_back();
        }
    }
};
