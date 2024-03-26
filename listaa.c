#include <stdio.h>
#include <math.h>

int passos;

double bissection(double a, double b, double eps);
double bissectionB(double a, double b, double eps);
double bissectionC(double a, double b, double eps);

double f(double x);
double fb(double x);
double fc(double x);


int main(void) {

    passos = 0;
    double resultA = bissection(1, 3, 1e-10);
    printf("Função A: %.20lf ----- %d passos\n", resultA, passos);
    // Função A: 2.99999999988358467817 ----- 35 passos

    passos = 0;
    double resultB = bissectionB(0, 1, 1e-10);
    printf("Função B: %.20lf ----- %d passos\n", resultB, passos);
    // Função B: 0.64171437092591077089 ----- 34 passos

    passos = 0;
    double resultC = bissectionC(23, 26, 1e-10);
    printf("Função C: %.20lf ----- %d passos\n", resultC, passos);
    // Função C: 25.00000000005820766091 ----- 35 passos

    return 0;
}

double f(double x) {
    return pow(x, 5) - 2*pow(x, 4) - 9*pow(x, 3) + 22*pow(x, 2) + 4*x - 24;
}

double fb(double x) {
    return cos(x) - sqrt(x);
}

double fc(double x) {
    return (sqrt(x) - 5) * exp(-x);
}

// Método da bisseção para a função a
double bissection(double a, double b, double eps) {
    
    double x0 = a, x1 = b;

    do {
        x0 = x1;
        x1 = (a + b) / 2;

        if (f(x1) * f(a) < 0) {
            b = x1;
            passos++;
        }
        else {
            a = x1;
            passos++;
        }

    } while (fabs(x1 - x0) > eps);

    return x0;
}

// Método da bisseção para a função b
double bissectionB(double a, double b, double eps) {
    
    double x0 = a, x1 = b;

    do {
        x0 = x1;
        x1 = (a + b) / 2;

        if (fb(x1) * fb(a) < 0) {
            b = x1;
            passos++;
        }
        else {
            a = x1;
            passos++;
        }

    } while (fabs(x1 - x0) > eps);

    return x0;
}

// Método da bisseção para a função c
double bissectionC(double a, double b, double eps) {
    
    double x0 = a, x1 = b;

    do {
        x0 = x1;
        x1 = (a + b) / 2;

        if (fc(x1) * fc(a) < 0) {
            b = x1;
            passos++;
        }
        else {
            a = x1;
            passos++;
        }

    } while (fabs(x1 - x0) > eps);

    return x0;
}