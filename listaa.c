#include <stdio.h>
#include <math.h>

int passos;

double bissection(double (*f)(double), double a, double b, double eps);
double secante(double (*f)(double), double a, double b, double eps);

double fa(double x);
double fb(double x);
double fc(double x);


int main(void) {

    passos = 0;
    double resultA = bissection(fa, 1, 3, 1e-10);
    printf("Função A (bissection): %.20lf ----- %d passos\n", resultA, passos);
    // Função A: 2.00000000000000000000 ----- 1 passo

    passos = 0;
    double resultB = bissection(fb, 0, 1, 1e-10);
    printf("Função B (bissection): %.20lf ----- %d passos\n", resultB, passos);
    // Função B: 0.64171437086770310998 ----- 34 passos

    passos = 0;
    double resultC = bissection(fc, 23, 26, 1e-10);
    printf("Função C (bissection): %.20lf ----- %d passos\n", resultC, passos);
    // Função C: 24.99999999997089616954 ----- 35 passos

    printf("\n");

    passos = 0;
    double resultAA = secante(fa, 1, 3, 1e-10);
    printf("Função A (secante): %.20lf ----- %d passos\n", resultAA, passos);
    // Função A (secante): 1.99999038936205031369 ----- 40 passos

    passos = 0;
    double resultBB = secante(fb, 0, 1, 1e-10);
    printf("Função B (secante): %.20lf ----- %d passos\n", resultBB, passos);
    // Função B (secante): 0.64171437087288263346 ----- 6 passos

    passos = 0;
    double resultCC = secante(fc, 23, 26, 1e-10);
    printf("Função C (secante): %.20lf ----- %d passos\n", resultCC, passos);
    // Função C (secante): -nan ----- 3 passos. NÃO CONVERGE!!!
    


    return 0;
}

double fa(double x) {
    return pow(x, 5) - 2*pow(x, 4) - 9*pow(x, 3) + 22*pow(x, 2) + 4*x - 24;
}

double fb(double x) {
    return cos(x) - sqrt(x);
}

double fc(double x) {
    return (sqrt(x) - 5) * exp(-x);
}

// Método da bisseção
double bissection(double (*f)(double), double a, double b, double eps) {
    
    double x1;

    do {
        passos++;

        x1 = (a + b) / 2;
        if(f(x1) == 0.0) {
            break;
        }
        else if (f(x1) * f(a) < 0) {
            b = x1;
        }
        else {
            a = x1;
        }

    } while (fabs(b - a) > eps);

    return x1;
}

double secante(double (*f)(double), double a, double b, double eps) {

    double x0 = a, x1 = b, x2;

    while (fabs(x1 - x0) > eps) {
        passos++;
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }

    return x1;
}