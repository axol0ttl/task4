#pragma once
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "mySatur.h"
//
//
// void error(const char* msg);//????? throw + catch

template <typename T>
class vector;

inline std::ostream& operator<<(std::ostream& os, mySatur& x) { // cout для vector<mySatur>
    x.print();
    return os;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, vector<T>& x) { // cout для vector<vector>
    x.print_for_matrix();
    return os;
}

template <typename T>
class vector {
    T* v;
    int sz;
public:
    vector(int s) {
        try {
            // if (s<1) error("wrong size");
            if (s < 1) throw std::runtime_error("wrong size");
            sz = s;
            v = new T[s];
            if (v==0) throw std::runtime_error("out of memory");
            // if (v==0) {error("out of memory");}
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    vector() {
        sz = 99;
        v = new T[sz];
    }

    vector(vector const& other) {
        sz = other.sz;
        try {
            v = new T[sz];
            if (v == 0) throw std::runtime_error("out of memory");
        }

        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }

        for (int i = 0; i < sz; i++) {
            v[i] = other.v[i];
        }
    }

    vector(int rows, int cols) {
        try {
            // if (rows < 1) error("wrong size");
            if (rows < 1 || cols < 1) throw std::runtime_error("wrong size");
            // if (cols < 1) throw std::runtime_error("wrong size");
            sz = rows;
            v = new T[rows];
            // if (v == 0) error("out of memory");
            if (v == 0) throw std::runtime_error("out of memory");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
        for (int i = 0; i < rows; i++) {
            v[i] = T(cols);  // Создаём каждый внутренний вектор размера cols
        }
    }

    // vector(int rows, int cols, T val) {
    //     try {
    //         // if (rows < 1) error("wrong size");
    //         if (rows < 1 || cols < 1) throw std::runtime_error("wrong size");
    //         // if (cols < 1) throw std::runtime_error("wrong size");
    //         sz = rows;
    //         v = new T[rows];
    //         // if (v == 0) error("out of memory");
    //         if (v == 0) throw std::runtime_error("out of memory");
    //
    //         for (int i = 0; i < rows; i++) {
    //             for (int j = 0; j < cols; j++) {
    //                 v[i][j] = val; // Инициализируем каждый элемент значением val
    //             }
    //         }
    //     }
    //     catch (std::runtime_error& e) {
    //         std::cerr << e.what() << std::endl;
    //     }
    //     for (int i = 0; i < rows; i++) {
    //         v[i] = T(cols);  // Создаём каждый внутренний вектор размера cols
    //
    //     }
    // }

    vector(vector&& other) {
        sz = other.sz;
        try {
            v = new T[sz];
            // if (v == 0) error("out of memory");
            if (v==0) throw std::runtime_error("out of memory");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
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
        try {
            if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
        }
        // if (i < 0 || i >= sz) error("index out of range");
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
        return v[i];
    }


    const T& operator[](int i) const {
        try {
            if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
            // if (i < 0 || i >= sz) error("index out of range");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
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
        try {
            if (s != a.size())
                throw std::runtime_error("vector size mismatch");
                // error("Vector size mismatch");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
        vector sum(s);

        for (int i = 0; i < s; i++)
            sum.elem(i) = elem(i) + a.elem(i);

        return sum;
    }

    vector operator-(vector&a) {
        int s = size();
        try {
            if (s != a.size())
                throw std::runtime_error("Vector size mismatch");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
        vector sum(s);
        for (int i = 0; i < s; i++)
            sum.elem(i) = elem(i) - a.elem(i);
        return sum;
    }


    vector& operator=(const vector& a) {
        if (this == &a) return *this;  // защита от самоприсваивания

        if (size() == a.size()) { // если размеры одинаковые, просто копируем элементы
            for (int i = 0; i < sz; i++) {
                v[i] = a.v[i];
            }
            return *this;
        }


        delete[] v; // если ни то, ни другое, удаляем
        sz = a.sz;
        try {
            v = new T[sz];
            // if (v == 0) error("out of memory");
            if (v == 0) throw std::runtime_error("out of memory");
        }
        catch (std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
        for (int i = 0; i < sz; i++) {
            v[i] = a.v[i];
        }
        return *this;
    }


    vector& operator=(vector&&a) {
        // if (this == &a) {
        //     return *this;// защита от самоприсваивания
        // }
        //
        // if (sz == a.sz) { // если размеры одинаковые
        //
        //     for (int i = 0; i < sz; i++) {
        //         elem(i) = a.elem(i);
        //     }
        //     return *this;
        // }
        //
        // delete [] v; // уничтожим прошлый массив и сделаем из него копию другого
        // sz = a.sz;
        // try {
        //     v = new T[sz];
        //     // if (v == 0) error("out of memory");
        //     if (v == 0) throw std::runtime_error("out of memory");
        // }
        // catch (std::runtime_error& e) {
        //     std::cerr << e.what() << std::endl;
        // }
        // for (int i = 0; i < sz; i++) {
        //     v[i] = a.v[i];
        // }
        //
        // // return *this;
        // printf("\nya huesos\n");
        if (this == &a) return *this;
        delete[] v;

        v = a.v;
        sz = a.sz;

        a.v = nullptr;
        a.sz = 0;

        return *this;
    }

    // vector operator <<(std::ostream& os) {
    //     int a = size();
    //         for (int i = 0; i<a; i++) {
    //             os << elem(i);
    //             if (i < a - 1) os << ", ";
    //         }
    //     return os;
    // }
    void print() {
        int s = size();
        std::cout << "[";
        // printf("[");
        for (int i = 0; i<s; i++) {
            std::cout << elem(i);
            // elem(i).print();
            if (i < s - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    void print_for_matrix() {
        int s = size();
        std::cout << "[";
        // printf("[");
        for (int i = 0; i<s; i++) {
            std::cout << elem(i);
            if (i < s - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }



};



// template <typename T>
// std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
//     int s = v.size();
//     os << "[";
//     for (int i = 0; i < s; i++) {
//         v.elem(i).print();
//         if (i < s - 1) os << ", ";
//     }
//     os << "]";
//     return os;
// }
//
// std::ostream& operator<<(std::ostream& os, const myFloat& mF) {
//     // std::cout<< c << abs(d) << std::endl;
//     printf("%d.%04d", mF.c, abs(mF.d));
//     return os;
// }
