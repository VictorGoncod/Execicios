#include<stdio.h>
#include<stdlib.h>

struct no{
  int numero;
  struct no *proximo;
  struct no *anterior;
};

 struct lista {
	int nos;
	struct no *inicio;
	struct no *fim;

};

struct lista *listaA, *listaB, *listaC;

//--------------------------------------------------------------------------------------------------------------

int verificar( ){
	if(listaA == NULL && listaB == NULL){
		return NULL;
	}
	else if(listaA == NULL || listaB == NULL){
		if(listaA == NULL){
		return -1;
	}
     	else if(listaB == NULL){
     		return -2;
		 }
	}
}
//-------------------------------------------------------------------------------------------------
struct no *buscar(int elem){

struct no  *retorno;
bool aqui=false, aqui2=false;
int resp = verificar();

if(resp == NULL){
	return NULL;
}
if(resp == -1 ){
	retorno -> numero = -1;
	retorno -> proximo = NULL;
	retorno -> anterior = NULL;
	return retorno;
}
if(resp == -2 ){
	retorno -> numero = -2;
	retorno -> proximo = NULL;
	retorno -> anterior = NULL;
	return retorno;
}
struct no * item, *item2;

item = listaA ->inicio;
item2 = listaB ->inicio;
while(item -> numero != NULL && aqui == false)
{
	if(item->numero == elem){
		aqui = true;
	}else{

	item = item -> proximo;
}
}
while(item2 -> numero != NULL && aqui2 == false ){
	if(item2-> numero == elem){
		aqui2 = true;
	}
	else
	{
		item2 = item2 -> proximo;
	}
}

if (aqui == true && aqui2 == true){
	retorno -> numero = 3;
	return retorno;
}else if (aqui == true && aqui == false)
{
retorno -> numero = 1;
return retorno;

}else {
retorno -> numero = 2;
return retorno;
}

}
//-------------------------------------------------------------------------------------------------------------

struct no buscaPossicao(int k , struct no *l){

  struct no *retorno;

	bool achou = false;

	while(l -> numero != NULL && achou == false){
    if(l->numero == k){
      achou = true;
    }
    else {
      l = l->proximo;
    }
	}

  if(achou == true){
    return l->anterior;
  }
   else{
   	return NULL;
   }
}

 int main (){

int elem = 0;
printf("digite valor para pesquisar: ");
scanf("%d",&elem);

struct no *resp = buscar(elem);

if(resp != NULL){
	if(resp ->numero == 1){
		printf("esta na lista 1\n");
	}
	else if (resp ->numero == 2){
		printf("esta na lista 2\n");
	}else {
		printf("esta em ambas a lista 1 e 2\n");
	}

}else {
	printf("listas 1 e 2 estao vazia ");
}




return 0;
}
