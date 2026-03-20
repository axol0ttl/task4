#pragma once
#include <iostream>

class myFloat {
protected:
    int c;      // ???????  целая часть
    int d;      // десятичная часть (хранится как целое число, масштабированное на 10000)
public:
    myFloat(double x = 0.0);
    myFloat(int a, int b);
    myFloat(const myFloat& other) : c(other.c), d(other.d) {} // конструктор копирования
    void print();
    myFloat Sin(myFloat x);
    
    friend myFloat operator+(myFloat a, myFloat b);
    friend myFloat operator-(myFloat a, myFloat b);
    friend myFloat operator*(myFloat a, myFloat b);
    friend myFloat operator/(myFloat a, myFloat b);
    friend bool operator>(myFloat a, myFloat b);
    friend bool operator<(myFloat a, myFloat b);



    friend std::ostream& operator<<(std::ostream& os, const myFloat& mF); //mF == myFloat
    //ostream& - тип потока данных вывода (stdout), operator<< - перегрузка оператора вывода, os - объект потока, mF - объект myFloat для вывода
};