//
// Created by Arseny on 11/03/2026.
#include "vector.h"
#include "mySatur.h"

int main() {


    vector<mySatur> x(2), y(2), xxx(x);
    x[0] = 8255.4357; x[1] = 2.0;
    y[0] = 1642.0; y[1] = 67.0;



    vector<mySatur> res = x + y; // сложение массивов
    res.print();

    vector<mySatur> res2 = res;
    res2.print();
    // res2[2] = 123.2351; // index out of range
    x = y;
    // x.print();

    // y = x;
    // y.print();

    vector<int> another_matrix(3);

    // x.print();
    xxx.print();

    another_matrix.print();

    vector<vector<double>> matrix(2,4);
    matrix.print();
    return 0;
}