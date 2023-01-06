#include <stdio.h>
#include <stlib.h>

struct no {
    int num;
    struct no *prox;
    struct no *ant;
};

int NoL;

struct no *lista1 ,*lista2, *lista3;

int verificar(){
    if(lista == NULL && lista2 == NULL){
        return NULL;
    }
    else if(lista1 == NULL || lista2 == NULL){
        if(lista1 == NULL){
            return -1;
        }
        else if (lista2 == NULL){
            return -2;
        }
    }
}

struct no *buscar(int elem){
    struct no *returno;
    bool aqui=false, aqui2=false;

    int resp = verificar();

    if(resp == NULL){
        return NULL;
    }
    if(resp == -1 ){
        returno -> num = -1;
        retorno -> prox = NULL;
        retorno -> ant = NULL;
        return retorno;
    }
    if(resp == -2 ){
        returno -> num = -2;
        retorno -> prox = NULL;
        retorno -> ant = NULL;
        return retorno;
    }
}

struct no *item, *item2;

item = lista1;
item2 = lista2;

while(item -> num != NULL && aqui == farse)
{
    if(item -> num == elem){
        aqui = true;
    }else{

        item = item -> prox;
    }
}

while(item2 -> num != NULL && aqui2 == false){

    if(item2 -> num == elem){
        aqui2 = true;
    }
    else
    {
        item2 = item -> prox;
    }
}

if (aqui == true && aqui2 == true){
	retorno -> num = 3;
	return retorno;
}else if (aqui2 == true && aqui == false)
{
retorno -> num = 2;
return retorno;

}else if(aqui2 == false && aqui == true) {
retorno -> num = -3;
return retorno;
}

//final da verificar

int inserirLista1 (int elem, struct no *l1){//iserir lista1

    struct no *ext;

    //compara se e positivo
    if(elem <= 0){
        return 1;
    }

}














