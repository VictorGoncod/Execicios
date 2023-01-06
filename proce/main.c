#include <stdio.h>
#include <stdlib.h>

struct no{
   int numero;
   struct no *proximo;
   struct no *anterior;
};


struct lista{
  int Nos;
  struct no *inicio;
  struct no *fim;
};

struct lista listaA, listaB, listaC;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int inserirListaEmOrdem(int k , struct lista l){
struct no *novoNo ,*item;
int achou = 0;

if(k <= 0){
  return 1;
}
novoNo = (struct no *)malloc(sizeof(struct no));
novoNo -> numero = k;

if(l.inicio == NULL){
l.inicio = novoNo;
novoNo->proximo = NULL;
novoNo->anterior =NULL;
l.Nos++;
l.fim = novoNo;
return 0;
}

item = l.inicio;
while(item->numero != NULL && item->proximo != NULL && achou == 0){

  if(item -> numero > k){
  achou = 1;
  }
  item=item->proximo;
}
if(achou == 1){
  if(item->numero > k){
    if(item == l.inicio){
      novoNo -> proximo = l.inicio;
      novoNo-> anterior = NULL;
      item->anterior = novoNo;
      l.inicio = novoNo;
      l.Nos++;
      l.fim = novoNo;
    }
    else{
      novoNo ->proximo = item;
      novoNo-> anterior = item-> anterior;
      item ->anterior->proximo =novoNo;
      item -> anterior = novoNo;
      l.Nos++;
    }

  }
}
item -> proximo = novoNo;
novoNo ->anterior = item;
novoNo -> proximo = NULL;
l.Nos++;
l.fim = novoNo;
return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct no *buscaElemento(int k, struct lista l){

struct no * item;
int achou = 0;

  if(l.inicio == NULL){
    return NULL;
  }
item = l.inicio;
while(item -> numero!= k && item -> proximo != NULL && achou == 0 ){
 if(item->numero == k){
   achou = 1;
 }else{
   item = item->proximo;
 }
}
if(achou == 1){
  return item;
}
return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int inserirListaCEmOrden(struct lista l, struct lista l2){
  struct no *novoNo, *item1, *item2;

int retorno;

retorno = verificar();
if(retorno == NULL){
  return NULL;
}else if(retorno == -1){
return -1;
}else if(retorno == -2){
  return -2;
}

novoNo = (struct no *)malloc(sizeof(struct no));

item1 = l.inicio;
item2 = l.inicio;
while(item1 -> numero!= NULL && item2->numero != NULL && item1-> proximo != NULL){

 if(item1->numero > item2->numero){

   novoNo-> proximo = item1;
   novoNo = item2;
   novoNo -> anterior = item2->anterior;
   listaC.inicio = novoNo;
   listaC.Nos++;
 }
 else if(item1->numero < item2->numero){
   novoNo-> proximo =item2;
   novoNo = item1;
   novoNo-> anterior = item1->anterior;
   listaC.inicio = novoNo;
   listaC.Nos++;
 }else if (item1-> numero == item2->numero){
   novoNo -> proximo = NULL;
   novoNo -> anterior = NULL;
   novoNo = item1;
   listaC.inicio = novoNo;
   listaC.Nos++;

 }
 item1= item1->proximo;
 item2 = item2->proximo;

}
return 0;
}

int main{

    int op, op1;


    do{
        printf("menu\n");
        printf("1-lista\n");
        printf("0 - para fechar\n")
        printf("digite o valor da opicao: ");

        scanf("%d",&op);
        system("cls");

        switch("op"){

            case 1:
                do{
            printf("menu lista 1\n");
	     	printf("1 - verificar lista 1\n");
	    	printf("2 - inserir lista 1\n");
	       	printf("0 - para sair\n ");
	    	printf("digite valor da opicao: ");

	    	scanf("%d",op1);
	    	system("cls");

               switch(op1){

               case 1:
                do{
                    printf("\nverificar lista 1\n");
			int resp1 = verificar();
			if(resp1 == NULL){

				printf("lista vazia\n");

			}else{
				printf("lista existe\n");
			}


                }
               }

                }
        }
    }

}
