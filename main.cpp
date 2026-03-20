//
// Created by Arseny on 11/03/2026.
//
// #include <algorithm> // std::move (для перемещения ресурсов вместо копирования)
#include "vector.h"
#include "mySatur.h"

int main() {


    vector<mySatur> x(2), y(2);
    x[0] = 8255.4357; x[1] = 2.0;
    y[0] = 1642.0; y[1] = 67.0;

    vector<mySatur> res = x + y; // сложение массивов
    res.print();

    // vector res2 = std::move(res); // операция копирования
    vector<mySatur> res2 = lvalue_to_rvalue(res); // 18 и 19 строка выполняют одно и то же, но в 19 самописная функция в vector.h
    res2.print();
    // res2[2] = 123.2351; // index out of range
    x = lvalue_to_rvalue(y);
    // x.print();

    y = lvalue_to_rvalue(x);
    y.print();
    mySatur test = res2.lm(); //возвращает ссылкой последний элемент без проверок
    test.print();

    vector<int> l1(3); // встроенный int
    l1[0] = 1; l1[1] = 2; l1[2] = 3;
    l1.print();

    vector<float> l2(3); // встроенный float
    l2[1] = 2.34; l2[2] = 67.34;
    l2.print();

    vector<vector<int>> mnogomernich(2);
    mnogomernich.print();
    //там получается много нулей, т.к. мы изначально
    //инициализируем вектор с 99 значениями


    return 0;
}