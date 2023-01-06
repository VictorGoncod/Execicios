#include <stdio.h>
#include <stdlib.h>


int Pilha[5], Fila[5], topo, fim;

int  empilhar ( int elemento){
	if (topo< 49) {
		topo++;
		Pilha[topo] = elemento;
		return 0;}
	return -1;
}

int  desempilhar (){
    int elemento;
	if (topo >=0) {
		elemento = Pilha[topo];
		topo--;
		return  elemento;
	}
	return -1;
}

int  enfileirar ( int elemento){
	if (fim < 49) {
		fim++;
		Fila[fim] = elemento;
		return 0;}
	return -1;
}

void  rearrumar (){
    int p;
	for (p= 0; p < fim; p++){
		Fila[p] = Fila[p+1];
	}
}

int desenfileirar (){
    int elemento;
    if (fim>=0) {
	   elemento = Fila[0];
       rearrumar();
	   fim--;
	   return  elemento;
	}
	return -1;
}

int main()
{
    topo=-1;
    fim=-1;

    empilhar (4);
    empilhar (7);
    empilhar (2);
    empilhar(19);
    desempilhar();
    desempilhar();
    empilhar (5);
    empilhar (9);
    empilhar (18);


    enfileirar (4);
    enfileirar (7);
    enfileirar (2);
    enfileirar (19);
    desenfileirar();
    desenfileirar();
    enfileirar(5);
    enfileirar(9);
    enfileirar(18);

    return 0;
}
