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
int inserirListaAEmOrdem(int k){
struct no *novoNo ,*item ,*ret;
int achou = 0;

if(k <= 0){
  return 1;
}
novoNo = (struct no *)malloc(sizeof(struct no));
novoNo -> numero = k;

if(listaA.inicio == NULL){
listaA.inicio = novoNo;
novoNo->proximo = NULL;
novoNo->anterior =NULL;
listaA.Nos++;
listaA.fim = novoNo;
return 0;
}


item = listaA.inicio;
while(item->numero != k && item->proximo != NULL && achou == 0){
  if(item -> numero == k){
  achou = 1;
}
  item=item->proximo;
}
if(item -> numero ==  k){
  return -1;
}

while(item->numero != NULL && item->proximo != NULL && achou == 0){

  if(item -> numero > k){
  achou = 1;
  }
  item=item->proximo;
}

  if(item->numero > k){
    if(item == listaA.inicio){
      novoNo -> proximo = listaA.inicio;
      novoNo-> anterior = NULL;
      item->anterior = novoNo;
      listaA.inicio = novoNo;
      listaA.Nos++;
      listaA.fim = novoNo;

    }
    else{
      novoNo ->proximo = item;
      novoNo-> anterior = item-> anterior;
      item ->anterior->proximo =novoNo;
      item -> anterior = novoNo;
      listaA.Nos++;

    }

  }

item -> proximo = novoNo;
novoNo ->anterior = item;
novoNo -> proximo = NULL;
listaA.Nos++;
listaA.fim = novoNo;

return 0;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int inserirListaBEmOrdem(int k){
struct no *novoNo ,*item;
int achou = 0;

if(k <= 0){
  return 1;
}
novoNo = (struct no *)malloc(sizeof(struct no));
novoNo -> numero = k;

if(listaB.inicio == NULL){
listaB.inicio = novoNo;
novoNo->proximo = NULL;
novoNo->anterior =NULL;
listaB.Nos++;
listaB.fim = novoNo;
return 0;
}


item = listaB.inicio;
while(item->numero != k && item->proximo != NULL && achou == 0){
  if(item -> numero == k){
  achou = 1;
}
  item=item->proximo;
}
if(item -> numero ==  k){
  return -1;
}

while(item->numero != NULL && item->proximo != NULL && achou == 0){

  if(item -> numero > k){
  achou = 1;
  }
  item=item->proximo;
}

  if(item->numero > k){
    if(item == listaB.inicio){
      novoNo -> proximo = listaA.inicio;
      novoNo-> anterior = NULL;
      item->anterior = novoNo;
      listaB.inicio = novoNo;
      listaB.Nos++;
      listaB.fim = novoNo;

    }
    else{
      novoNo ->proximo = item;
      novoNo-> anterior = item-> anterior;
      item ->anterior->proximo =novoNo;
      item -> anterior = novoNo;
      listaB.Nos++;

    }

  }

item -> proximo = novoNo;
novoNo ->anterior = item;
novoNo -> proximo = NULL;
listaB.Nos++;
listaB.fim = novoNo;

return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct no *buscaElementoA(int k){

struct no * item;
int achou = 0;

  if(listaA.inicio == NULL){
    return NULL;
  }
item = listaA.inicio;
while(item -> numero!= k && item -> proximo != NULL  ){
   item = item->proximo;

}
if(item->numero == k){
  return item;

}
return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct no *buscaElementoB(int k){

struct no * item;
int achou = 0;

  if(listaB.inicio == NULL){
    return NULL;
  }
item = listaB.inicio;
while(item -> numero!= k && item -> proximo != NULL  ){
   item = item->proximo;

}
if(item->numero == k){
  return item;

}
return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int inserirListaCEmOrden(){
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

item1 = listaA.inicio;
item2 = listaB.inicio;
while(item1 -> numero!= NULL && item2->numero != NULL && item1-> proximo != NULL && item2-> proximo != NULL  ){

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int remover(){

struct no *item, *anterior;
int soma, media;

if(listaC.inicio == NULL){
  return NULL;
}

free(listaC.inicio);


item = listaC.inicio;
while(item->numero != NULL && item->proximo != NULL){

soma= soma + item->numero;
item = item ->proximo;

}

media=soma/listaC.Nos;
return media;

}
