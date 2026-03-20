#pragma once
#include <stdlib.h>
#include <iostream>
#include "mySatur.h"


void error(const char* msg);

template <typename T>
class vector;

template <typename T>
inline vector<T>&& lvalue_to_rvalue(vector<T>& x) {
    return (vector<T>&&) x;
}

template <typename T>
class vector {
    T* v;
    int sz;
public:
    vector(int s) {
        if (s<1) error("wrong size");
        sz = s;
        v = new T[s];
        if (v==0) {error("out of memory");}
    }

    vector() {
        sz = 99;
        v = new T[sz];
    }
    vector(vector&& other) {
        sz = other.sz;
        v = new T[sz];
        if (v == 0) error("out of memory");
        for (int i = 0; i < sz; i++) {
            v[i] = other.v[i];
        }
    }
    ~vector() {
        delete [] v;
    }

    inline int size() const{
        return sz;
    }
    T& operator[](int i) {
        if (i < 0 || i >= sz) error("index out of range");
        return v[i];
    }


    const T& operator[](int i) const {
        if (i < 0 || i >= sz) error("index out of range");
        return v[i];
    }

    inline T& elem(int i) {
        return v[i];
    }

    inline T& lm() {
        return v[sz-1];
    }

    vector operator+(vector&a) {
        int s = size();
        if (s != a.size())
            error("Vector size mismatch");

        vector sum(s);

        for (int i = 0; i < s; i++)
            sum.elem(i) = elem(i) + a.elem(i);

        return sum;
    }

    vector operator-(vector&a) {
        int s = size();
        if (s != a.size())
            error("Vector size mismatch");
        vector sum(s);
        for (int i = 0; i < s; i++)
            sum.elem(i) = elem(i) - a.elem(i);
        return sum;
    }

    vector& operator=(vector&&a) {
        if (this == &a) {
            return *this;// защита от самоприсваивания
        }

        if (sz == a.sz) { // если размеры одинаковые

            for (int i = 0; i < sz; i++) {
                elem(i) = a.elem(i);
            }
            return *this;
        }

        delete [] v; // уничтожим прошлый массив и сделаем из него копию другого
        sz = a.sz;
        v = new T[sz];

        if (v == 0) error("out of memory");
        for (int i = 0; i < sz; i++) {
            v[i] = a.v[i];
        }

        return *this;
    }

    void print() {
        int s = size();
        std::cout << "[";
        // printf("[");
        for (int i = 0; i<s; i++) {
            std::cout << elem(i);
            if (i < s - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }


    friend vector&& lvalue_to_rvalue<T>(vector& x);


};



template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    int s = v.size();
    os << "[";
    for (int i = 0; i < s; i++) {
        os << v[i];
        if (i < s - 1) os << ", ";
    }
    os << "]";
    return os;
}