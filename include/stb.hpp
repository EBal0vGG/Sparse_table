#ifndef STCLASS_H
#define STCLASS_H
#include <vector>

using namespace std;

// Sparse Table
template <typename Type> class ST {
private:
    vector<vector<Type>> st; // Хранит предвычисленные результаты
    Type n;                  // Размер исходного массива

public:
    // Конструктор принимает массив и строит таблицу
    ST(const vector<Type>& arr);

    // Декструктор по умолчанию
    ~ST() = default;

    // Функция для получения минимального элемента на отрезке [L, R]
    Type query(int L, int R) const;
};
#endif