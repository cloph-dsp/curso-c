#ifndef CALCULATOR_H
#define CALCULATOR_H

void mostrarMenu();
int lerOperacao();

float lerValor(const char* mensagem);

float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
float potenciacao(float base, int expoente);
void tabuada(int numero);
int verificarPrimo(int numero);
int verificarPar(int numero);

void limparTela();

#endif // CALCULATOR_H