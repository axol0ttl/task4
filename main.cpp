#include "vector.h"
#include "mySatur.h"


int main() {
    try {
        vector<vector<double>> a(2, vector<double>(2));

        a[0][0] = 9123.3; a[0][1] = 123; a[1][0] = 98765; a[1][1] = 9.0;

        printf("Matrix A:\n");
        a.print();


        vector<vector<double>> b(2, vector<double>(2,1.1));

   //     b[0][0] = double(100.0);
   //     b[0][1] = double(2.0);
   //     b[1][0] = double(1002.0);
   //     b[1][1] = double(9.0);

        printf("Matrix B:\n");
        b.print();

        vector<vector<double>> res1 = a + b;
        printf("\nResult A + B:\n");
        res1.print();

        vector<double> x(2, double()), y(3, double());

        x[0] = double(9000.0);
        x[1] = double(2.0);
        printf("Matrix A:\n");
        x.print();

        printf("\n");

        y[0] = double(1002.0);
        y[1] = double(9.0);
        printf("Matrix B:\n");
        y.print();

        vector<double> res = x + y;
        printf("\nResult A + B:\n");
        res.print();



    }
    catch (const std::exception& e) {
        printf("Error: %s\n", e.what());
        exit(1);
    }


}