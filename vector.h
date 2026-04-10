#pragma once
#include <iostream>
#include <stdexcept>
#include "mySatur.h"

template <typename T>
class vector;

// operator<< для mySatur (нужен для vector<mySatur>)
inline void operator<<(std::ostream& os, mySatur& x) {x.print();}

// operator<< для vector<T> (нужен для vector<vector<…>>)
template <typename T>
void operator<<(std::ostream& os, vector<T>& x) {x.print_for_matrix();} //?????

template <typename T>
class vector {
T* v;
int sz;

public:
// конструкторы


// копирующий конструктор
vector(const vector& other) {
        sz = other.sz;
        v = new T[sz];
        if (v == nullptr) {
            throw std::runtime_error("out of memory");
        }

        for (int i = 0; i < sz; i++){
            v[i] = other.v[i];
        }

}

// конструктов матрицы и просто массива: rows строк, каждая строка — T(cols)
vector(int s = 1, const T& val = T()) {
    if (s < 1)
        throw std::runtime_error("Wrong size");
    sz = s;
    v = new T[sz];
    if (v == nullptr)
        throw std::runtime_error("Not enough memory");
    for (int i = 0; i < sz; i++)
        v[i] = val;
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
    if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
    {
        return v[i];
    }
}

const T& operator[](int i) const {
        if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
    {return v[i];}
}

inline T& elem(int i) { return v[i]; }
inline T& lm()        { return v[sz - 1]; }

vector operator+(const vector<T>& a) const {
    int s = size();
    if (s != a.size()) throw std::runtime_error("vector size mismatch");
    vector sum(s);
    for (int i = 0; i < s; i++)
        sum.v[i] = v[i] + a.v[i];
    return sum;
}



vector operator-(const vector<T>& a) const {
    int s = size();
    if (s != a.size()) throw std::runtime_error("vector size mismatch");
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
        v = new T[sz];
        if (v == nullptr) throw std::runtime_error("out of memory");
    for (int i = 0; i < sz; i++) {
        v[i] = a.v[i];
    }
    return *this;
}

vector& operator=(vector&& a) {
    if (this == &a) return *this;
    delete[] v;
    v = a.v;
    sz = a.sz;
    a.v = nullptr;
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
    std::cout << "]";
}

};