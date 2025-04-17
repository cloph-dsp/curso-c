#include <stdio.h>

int tamanho(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

const char *encontrar(const char *str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

int alfabetico(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char minuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int maiuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

char para_maiuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

void encriptar(char *texto) {
    const char *original = "abcdefghijlmnopqrstuvxz";
    const char *encriptado = "defghijlmnopqrstuvxzabc";
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (alfabetico(texto[i])) {
            char c = minuscula(texto[i]);
            const char *posicao = encontrar(original, c);
            
            if (posicao != NULL) {
                int indice = posicao - original;
                if (maiuscula(texto[i])) {
                    texto[i] = para_maiuscula(encriptado[indice]);
                } else {
                    texto[i] = encriptado[indice];
                }
            }
        }
    }
}

void desencriptar(char *texto) {
    const char *original = "abcdefghijlmnopqrstuvxz";
    const char *encriptado = "defghijlmnopqrstuvxzabc";
    int i;
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (alfabetico(texto[i])) {
            char c = minuscula(texto[i]);
            const char *posicao = encontrar(encriptado, c);
            
            if (posicao != NULL) {
                int indice = posicao - encriptado;
                if (maiuscula(texto[i])) {
                    texto[i] = para_maiuscula(original[indice]);
                } else {
                    texto[i] = original[indice];
                }
            }
        }
    }
}

int main() {
    char texto[201];
    char opcao;
    
    printf("Indique o texto: ");
    fgets(texto, sizeof(texto), stdin);
    
    int tamanho_texto = tamanho(texto);
    if (tamanho_texto > 0 && texto[tamanho_texto-1] == '\n') {
        texto[tamanho_texto-1] = '\0';
    }
    
    printf("Tarefa (E ou D): ");
    scanf(" %c", &opcao);
    
    if (opcao == 'E' || opcao == 'e') {
        encriptar(texto);
    } else if (opcao == 'D' || opcao == 'd') {
        desencriptar(texto);
    } else {
        printf("Opcao invalida!\n");
        return 1;
    }
    
    printf("Resultado:\n%s\n", texto);
    
    return 0;
}