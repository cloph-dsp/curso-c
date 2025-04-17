#include <stdio.h>
#include <locale.h>
#include "calculator.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int operacao;
    float num1, num2, resultado;
    int numero;
    
    do {
        mostrarMenu();
        operacao = lerOperacao();
        
        if (operacao == 0) {
            printf("Programa encerrado\n");
            break;
        }
        
        switch (operacao) {
            case 1:
                num1 = lerValor("Digite o primeiro valor: ");
                num2 = lerValor("Digite o segundo valor: ");
                resultado = soma(num1, num2);
                printf("\nResultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
                break;
                
            case 2:
                num1 = lerValor("Digite o primeiro valor: ");
                num2 = lerValor("Digite o segundo valor: ");
                resultado = multiplicacao(num1, num2);
                printf("\nResultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
                break;
                
            case 3:
                num1 = lerValor("Digite o numerador: ");
                num2 = lerValor("Digite o denominador: ");
                resultado = divisao(num1, num2);
                printf("\nResultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
                break;
                
            case 4:
                num1 = lerValor("Digite o primeiro valor: ");
                num2 = lerValor("Digite o segundo valor: ");
                resultado = subtracao(num1, num2);
                printf("\nResultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
                break;
                
            case 5:
                num1 = lerValor("Digite a base: ");
                num2 = lerValor("Digite o expoente: ");
                resultado = potenciacao(num1, (int)num2);
                printf("\nResultado: %.2f elevado a %d = %.2f\n", num1, (int)num2, resultado);
                break;
                
            case 6:
                numero = (int)lerValor("Digite um n�mero para ver a tabuada: ");
                tabuada(numero);
                break;
                
            case 7:
                numero = (int)lerValor("Digite um n�mero para verificar se � primo: ");
                if (verificarPrimo(numero))
                    printf("\nO n�mero %d � primo!\n", numero);
                else
                    printf("\nO n�mero %d n?o � primo!\n", numero);
                break;
                
            case 8:
                numero = (int)lerValor("Digite um n�mero para verificar se � par: ");
                if (verificarPar(numero))
                    printf("\nO n�mero %d � par!\n", numero);
                else
                    printf("\nO n�mero %d � impar!\n", numero);
                break;
                
            default:
                printf("\nTente novamente.\n");
        }
        
        printf("\nPressione Enter para continuar... \n\n");
        getchar();
        getchar();
        
        limparTela();
        
    } while (operacao != 0);
    
    return 0;
}