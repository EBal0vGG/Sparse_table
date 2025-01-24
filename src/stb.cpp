#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

#include "stb.hpp"

using namespace std;

// Конструктор принимает массив и строит таблицу
template<typename Type>
ST<Type>::ST(const vector<Type>& arr) : n(arr.size()) {
    int maxLog = log2(n) + 1;

    // Инициализируем таблицу размером n x maxLog
    st.resize(n, vector<Type>(maxLog));

    // Заполняем первый столбец значениями из исходного массива
    for (int i = 0; i < n; ++i)
        st[i][0] = arr[i];

    // Заполнение остальных столбцов
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            // Операция для вычисления значений в таблице
            // Здесь используем min() для поиска минимума на отрезках
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Функция для получения минимального элемента на отрезке [L, R]
template<typename Type>
Type ST<Type>::query(int L, int R) const {
    if (L > R || L < 0 || R >= n) return INT_MAX; // Проверка корректности индексов

    int length = R - L + 1;
    int k = log2(length);

    // Используем предвычисленные значения из таблицы
    return min(st[L][k], st[R - (1 << k) + 1][k]);
}

template class ST<int>;
template class ST<float>;