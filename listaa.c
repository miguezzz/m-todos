#include <stdio.h>
#include <math.h>

int passos;

double bissection(double a, double b, double eps);

// Função para encontrar a raiz
double f(double x) {
    // Defina sua função aqui
    return pow(x, 5) - 2*pow(x, 4) - 9*pow(x, 3) + 22*pow(x, 2) + 4*x - 24;
}

// Função para encontrar a raiz
double fb(double x) {
    // Defina sua função aqui
    return cos(x) - sqrt(x);
}

// Função para encontrar a raiz
double fc(double x) {
    // Defina sua função aqui
    return (sqrt(x) - 5) * exp(-x);
}

int main(void) {

    passos = 0;
    double result = bissection (1, 3, 1e-10);

    printf("%.20lf ----- %d passos\n", result, passos);

    return 0;
}

// Método da bisseção
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