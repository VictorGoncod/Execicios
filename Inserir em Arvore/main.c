#include <stdio.h>

#include <stdlib.h>



struct no{

    int numero;



    struct no *direita;

    struct no *esquerda;

};





struct no *inserirNo (struct no *raiz, struct no *No){

    if (raiz == NULL){

        return No;

    }



    if (No->numero < raiz->numero){

        raiz->esquerda = inserirNo(raiz->esquerda, No);

    }else{

        raiz->direita = inserirNo(raiz->direita, No);

    }



    return raiz;

}



void exibirArvore(struct no *raiz){

    if(raiz != NULL){

        printf("Raiz: %d", raiz->numero);

        printf("(");

        printf("E: ");

        exibirArvore(raiz->esquerda);

        printf("D: ");

        exibirArvore(raiz->direita);

        printf(")");

    }

}



int main()

{

    struct no *arvore = NULL;



    struct no *novoNo;

    int num;



    for(int i=1;i<=5; i++){

        printf("Digite um numero\n");

        scanf("%d", &num);



        novoNo = (struct no *)malloc(sizeof(struct no));

        novoNo->numero = num;

        novoNo->direita = NULL;

        novoNo->esquerda = NULL;



        arvore = inserirNo(arvore, novoNo);

    }

    if(arvore == NULL){

        printf("Arvore vazia");

    }else{

        exibirArvore(arvore);

    }

    return 0;

}
