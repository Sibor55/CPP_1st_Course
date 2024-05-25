// Задача №6
// “Вектор bool”

// Реализуйте спецификацию шаблона для вектора из булевских значений. Помните, что на каждое значение должен быть потрачен только 1 бит памяти.
// Предусмотрите следующие операции:
// 1. 	Метод добавления в конец вектора
// 2. 	Метод и оператор получения и изменения значения по индексу
// 3. 	Метод size
// 4.  Метод insert и erase
 
// Продемонстрируйте работу с классом.
#include "vectorbool.cpp"
#include <iostream>

int main() {
    BoolVector bv;
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);

    // Получение значения
    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    // Изменение значения
    bv.set(1, true);

    // Проверка изменения
    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    // Вставка и удаление
    bv.insert(1, false);
    bv.erase(2);

    for (size_t i = 0; i < bv.size(); ++i) {
        std::cout << bv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}