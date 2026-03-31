#pragma once
#include <iostream>
#include <stdexcept>
#include "mySatur.h"

template <typename T>
class vector;

// operator<< для mySatur (нужен для vector<mySatur>)
inline std::ostream& operator<<(std::ostream& os, mySatur& x) {
x.print();
return os;
}

// operator<< для vector<T> (нужен для vector<vector<…>>)
template <typename T>
inline std::ostream& operator<<(std::ostream& os, vector<T>& x) {
x.print_for_matrix();
return os;
}

template <typename T>
class vector {
T* v;
int sz;

public:
// конструкторы


// одномерный вектор размера s
vector(int s) {
    try {
        if (s < 1) throw std::runtime_error("wrong size");
        sz = s;
        v  = new T[s];
        if (v == 0) throw std::runtime_error("out of memory");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// конструктор по умолчанию (размер 99)
vector() : sz(99), v(new T[99]) {}

// копирующий конструктор
vector(const vector& other) {
    try {
        v = new T[sz];
        if (v == 0) throw std::runtime_error("out of memory");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (int i = 0; i < sz; i++)
        v[i] = other.v[i];
}

// конструктов матрицы: rows строк, каждая строка — T(cols)
vector(int rows, int cols) {
    try {
        if (rows < 1 || cols < 1) throw std::runtime_error("wrong size");
        sz = rows;
        v  = new T[rows];
        if (v == 0) throw std::runtime_error("out of memory");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (int i = 0; i < sz; i++)
        v[i] = T(cols);
}

// мув-конструктор (крадём указатель, не копируем элементы)
vector(vector&& other) {
    other.v  = nullptr;
    other.sz = 0;
}

// Деструктор
~vector() {
    delete[] v;
}

// Размер вектора

inline int size() const { return sz; }

// Доступ к элементам

T& operator[](int i) {
    try {
        if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return v[i];
}

const T& operator[](int i) const {
    try {
        if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return v[i];
}

inline T& elem(int i) { return v[i]; }
inline T& lm()        { return v[sz - 1]; }

// операции сложения и вычитания

vector operator+(vector& a) {
    int s = size();
    try {
        if (s != a.size()) throw std::runtime_error("vector size mismatch");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    vector sum(s);
    for (int i = 0; i < s; i++)
        sum.elem(i) = elem(i) + a.elem(i);
    return sum;
}

vector operator-(vector& a) {
    int s = size();
    try {
        if (s != a.size()) throw std::runtime_error("vector size mismatch");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    vector sum(s);
    for (int i = 0; i < s; i++)
        sum.elem(i) = elem(i) - a.elem(i);
    return sum;
}

//Присваивание

vector& operator=(const vector& a) {
    if (this == &a) return *this;

    if (sz == a.sz) {
        for (int i = 0; i < sz; i++)
            v[i] = a.v[i];
        return *this;
    }

    delete[] v;
    sz = a.sz;
    try {
        v = new T[sz];
        if (v == 0) throw std::runtime_error("out of memory");
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    for (int i = 0; i < sz; i++)
        v[i] = a.v[i];
    return *this;
}

vector& operator=(vector&& a) noexcept {
    if (this == &a) return *this;
    delete[] v;
    v    = a.v;
    sz   = a.sz;
    a.v  = nullptr;
    a.sz = 0;
    return *this;
}

// Вывод

void print() {
    std::cout << "[";
    for (int i = 0; i < sz; i++) {
        std::cout << elem(i);
        if (i < sz - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Вызывается оператором << при печати матрицы (vector<vector<...>>)
void print_for_matrix() {
    std::cout << "[";
    for (int i = 0; i < sz; i++) {
        std::cout << elem(i);
        if (i < sz - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}


};