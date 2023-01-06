#include <stdio.h>



#include <stdlib.h>





struct no{



  int numero;





  struct no *direita;



  struct no *esquerda;



};





struct no *busca (struct no *arvore, int num){



  if (arvore == NULL || arvore->numero == num)



  {



    return arvore;



  }



  if (arvore->numero > num)



  {



    return busca (arvore->esquerda, num);



  }else



  {



    return busca (arvore->direita, num);



  }



}





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

int k,op=0;

  struct no *arvore = NULL;





  struct no *novoNo;

  struct no *search;



  int num;







 while (op!=4)

 {

  printf("1 - Inserir Elemento na arvore\n");

  printf("2 - Buscar Elemento na arvore\n");

  scanf("%d",&op);





    switch (op)

 {

 case 1:

     printf("Digite um numero\n");



    scanf("%d", &num);





    novoNo = (struct no *)malloc(sizeof(struct no));



    novoNo->numero = num;



    novoNo->direita = NULL;



    novoNo->esquerda = NULL;





    arvore = inserirNo(arvore, novoNo);

     break;

     case 2 :

     printf("Qual elemento deseja buscar : ");

     scanf("%d",&k);



     search = busca(arvore, k);



     if(search->numero == k){

         printf("Numero encontrado na arvore\n");

     }else

     printf("Numero nao encontrado");

     break;



  return 0;

  }

    }

      }
