#include <stdio.h>

int mediaVetor(float vet[], int tam) {
    float media, soma = 0;
    int i;

    for(i = 0; i < tam; i++){
        soma += vet[i];
    }

    media = soma / tam;

    return media;
}

int main(){
    float vetor[20] = {3,4,5,2,7,3,7,8,9,8,7,9,5,6,7,9,4,9,5};
    float resultado;

    resultado = mediaVetor(vetor, 20);
    printf("A media dos vetores e de %.2f\n", resultado);
}
