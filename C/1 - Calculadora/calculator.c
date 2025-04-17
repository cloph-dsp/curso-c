#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculator.h"

void mostrarMenu() {
    printf("******************************\n");
    printf("*** Calculadora \"C\" ***\n");
    printf("******************************\n");
    printf("*** 1- Soma                ***\n");
    printf("*** 2- Multiplicação       ***\n");
    printf("*** 3- Divisão            ***\n");
    printf("*** 4- Subtração          ***\n");
    printf("*** 5- Potenciação       ***\n");
    printf("*** 6- Tabuada           ***\n");
    printf("*** 7- Verificar primo   ***\n");
    printf("*** 8- Verificar par      ***\n");
    printf("*** 0- Terminar          ***\n");
    printf("******************************\n\n");
    printf("Opção: ");
}

int lerOperacao() {
    int op;
    scanf("%d", &op);
    return op;
}

float lerValor(const char* mensagem) {
    float valor;
    printf("%s", mensagem);
    scanf("%f", &valor);
    return valor;
}

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisao por zero!\n");
        return 0;
    }
    return a / b;
}

float potenciacao(float base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    
    float resultado = 1;
    
    if (expoente > 0) {
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }
    } else {
        for (int i = 0; i < -expoente; i++) {
            resultado *= base;
        }
        resultado = 1 / resultado;
    }
    
    return resultado;
}

void tabuada(int numero) {
    int i;
    printf("Tabuada do %d:\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
}

int verificarPrimo(int numero) {
    if (numero <= 1) return 0;
    
    int i;
    for (i = 2; i <= numero/2; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int verificarPar(int numero) {
    return (numero % 2 == 0);
}

void limparTela()  {
    system("cls");
}
