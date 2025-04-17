#include <stdio.h>
#include <math.h>

float calcular_tarifa(int minutos) {
    if (minutos <= 5) {
        return 0.0;
    }
    
    int periodos = (minutos + 14) / 15;
    float valor = 0.0;
    
    if (periodos >= 1) {
        valor += 0.5;
    }
    
    if (periodos >= 2) {
        valor += 0.7;
    }
    
    if (periodos >= 3) {
        valor += 0.7;
    }
    
    if (periodos > 3) {
        valor += (periodos - 3) * 0.9;
    }
    
    return valor;
}

int main() {
    int minutos;
    
    printf("********** ParkStop **********\n");
    printf("**                          **\n");
    printf("**       NIF: 999888111     **\n");
    printf("********************************\n\n");
    printf("Quantidade de minutos a faturar: ");
    scanf("%d", &minutos);
    
    float valor = calcular_tarifa(minutos);
    
    int minutos_faturados = minutos;
    if (minutos <= 5) {
        minutos_faturados = 0;
    }
    
    printf("\nA imprimir recibo ...\n");
    printf("..Valor a pagar: %.1f€\n", valor);
    printf("..Minutos faturados: %d", minutos_faturados);
    printf("\n\n");

    return 0;
}