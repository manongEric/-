/*************************************************************************
	> File Name: gradient.c
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Apr 2022 08:46:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double gradient(double a, double b, double c, int cnt) {
    double l = 0.1;
    double x = rand() % 20 - 10;
    for (int i = 0; i < cnt; i++) {
        double k = 2 * a * x + b;
        if (a > 0) {
            x = x - k * l;
        } else {
            x = x + k * l;
        }
        double fx = a * x + b * x + c;
        printf("i = %d x = %lf fx = %lf, k = %lf\n", i, x, fx, k);
    }
    return x;
}

int main() {
    srand(time(0));
    int a = rand() % 20 - 10;
    int b = rand() % 20 - 10;
    int c = rand() % 20 - 10;
    a = a == 0 ? 1 : a;
    printf("f(x) = %dx^2 + %dx + %d", a, b, c);
    gradient(a, b, c, 100);
    return 0;
}
