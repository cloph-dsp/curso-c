#include <stdio.h>

int tamanho(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char minuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int main() {
    char texto[81];
    char caracter;
    char case_sensitive;
    int posicoes[80];
    int num_eliminacoes = 0;
    int i, j;
    
    printf("Indique o texto: ");
    fgets(texto, sizeof(texto), stdin);
    
    int tamanho_texto = tamanho(texto);
    if (tamanho_texto > 0 && texto[tamanho_texto-1] == '\n') {
        texto[tamanho_texto-1] = '\0';
        tamanho_texto--;
    }
    
    printf("Indique o caracter a eliminar: ");
    scanf(" %c", &caracter);
    
    printf("Ignorar maiusculas/minusculas (s/n)? ");
    scanf(" %c", &case_sensitive);
    
    for (i = 0, j = 0; i < tamanho_texto; i++) {
        int remover = 0;
        
        if (case_sensitive == 's' || case_sensitive == 'S') {
            if (minuscula(texto[i]) == minuscula(caracter)) {
                remover = 1;
            }
        } else {
            if (texto[i] == caracter) {
                remover = 1;
            }
        }
        
        if (remover) {
            posicoes[num_eliminacoes] = i;
            num_eliminacoes++;
        } else {
            texto[j] = texto[i];
            j++;
        }
    }
    texto[j] = '\0';
    
    printf("\nForam feitas %d eliminacoes: %s\n", num_eliminacoes, texto);
    
    if (num_eliminacoes > 0) {
        printf("\nPosicoes eliminadas: ");
        for (i = 0; i < num_eliminacoes; i++) {
            printf("%d", posicoes[i] + 1);
            if (i < num_eliminacoes - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    
    return 0;
}