#include <stdio.h>
#include <stdlib.h>

struct no {
	int num;
	struct no *prox;
	struct no *ant;
};

int NoL;

struct no *lista1 ,*lista2, *lista3;


int verificar(){
	if(lista1 == NULL && lista2 == NULL){
		return NULL;
	}
	else if(lista1 == NULL || lista2 == NULL){
		if(lista1 == NULL){
		return -1;
	}
     	else if(lista2 == NULL){
     		return -2;
		 }
	}
}

struct no *buscar(int elem){

struct no  *retorno;
bool aqui=false, aqui2=false;

int resp = verificar();

if(resp == NULL){
	return NULL;
}
if(resp == -1 ){
	retorno -> num = -1;
	retorno -> prox = NULL;
	retorno -> ant = NULL;
	return retorno;
}
if(resp == -2 ){
	retorno -> num = -2;
	retorno -> prox = NULL;
	retorno -> ant = NULL;
	return retorno;
}
struct no * item, *item2;

item = lista1;
item2 = lista2;
while(item -> num != NULL && aqui == false)
{
	if(item->num == elem){
		aqui = true;
	}else{

	item = item -> prox;
}
}
while(item2 -> num != NULL && aqui2 == false ){
	if(item2-> num == elem){
		aqui2 = true;
	}
	else
	{
		item2 = item2 -> prox;
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

}

//final da verificar

int inserirLista1 (int elem, struct no *l1){//inserir lista1

struct no  *ext;

// compara se é positivo
    if(elem <= 0){
	return 1;
    }


  struct no *resp = buscar(elem);

  if(resp -> num == 1){
  	return 2;
  }
  else if(resp -> num == 3){
  	return 3;
  }


  l1 = (struct no *)malloc(sizeof(struct no));
  l1 -> num = elem;

  if(lista1 == NULL){
  	lista1 = l1;
  	l1 -> prox = NULL;
  	l1 -> ant = NULL;
  	return 0;
  }

  ext = lista1;
  while(ext -> num < elem && ext -> prox != NULL){
  	ext = ext->prox;
  }


  if(ext->num > elem ){
  	if(ext == lista1){
  		l1->prox = lista1;
  		l1->ant = NULL;
		ext->ant= l1;
		lista1= l1;
	  }


   else{
  	l1->prox = ext;
  	l1->ant= ext -> ant;
  	ext -> ant-> prox = l1;
  	ext ->ant =l1;
  }
}

  ext -> prox = l1;
  l1 -> ant = ext;
  l1->prox = NULL;



return 0;
}//final inserir lista1

int inserirLista2 (int elem, struct no *l2){//inserir lista2

struct no *ext;

// compara se é positivo
    if(elem <= 0){
	return 1;
    }


  struct no *resp = buscar(elem);

  if(resp -> num == 2){
  	return 2;
  }
  else if(resp -> num == 3){
  	return 3;
  }


  l2 = (struct no *)malloc(sizeof(struct no));
  l2 -> num = elem;

  if(lista2 == NULL){
  	lista2 = l2;
  	l2 -> prox = NULL;
  	l2 -> ant = NULL;
  	return 0;
  }

  ext = lista2;
  while(ext -> num < elem && ext -> prox != NULL){
  	ext = ext->prox;
  }


  if(ext->num > elem ){
  	if(ext == lista2){
  		l2->prox = lista2;
  		l2->ant = NULL;
		ext->ant= l2;
		lista2= l2;
	  }


   else{
  	l2->prox = ext;
  	l2->ant= ext -> ant;
  	ext -> ant-> prox = l2;
  	ext ->ant =l2;
  }
}

  ext -> prox = l2;
  l2 -> ant = ext;
  l2->prox = NULL;



return 0;
}//final inserir lista1

int unirListas(struct no *l1, struct no *l2){// inicio unirLista

	struct no *l3;



	if(lista1 == NULL && lista2 == NULL){//  teste listas vazia
		return NULL;
	}

	l3 = (struct no *)malloc((sizeof(struct no)));
	l1 = lista1;
	l2 = lista2;





  while(l1 ->num != l2 ->num && l1->prox != NULL && l2->prox != NULL ){

		l1= l1->prox;// nulo
		l2 = l2->prox;
	}
	if (l1 -> num == l2->num){

	 l3 -> prox = NULL;
	 l3 -> ant = NULL;
	 l3 = l1;
	 lista3 = l3;

    }else {

    if(l1 -> num > l2 -> num){

    	l3 = l2;
    	l3 -> prox = l1;
    	l3 -> ant = NULL;
		lista3 = l3;

	}
	if(l1 -> num < l2 -> num){

		l3 = l1;
		l3 -> prox = l2;
		l3 -> ant = NULL;
		lista3 = l3;


	}
	return 0;

	}

}// fim unirLista

int excluirEmOrdem(struct no * l3){//inicio excluirEmOrdem

	struct no  *No, *menor;
	int aux;

	if(lista3 == NULL){// lista vazia
		return -1;
	}

	l3 = lista3;


	while(l3->num != NULL && l3->prox != NULL ){//busca menor valor

		l3= l3->prox;

		if(l3->num > l3->ant ->num){// anterior < atual
			menor ->num = l3->ant ->num;
			menor -> ant= NULL;
			menor -> prox = NULL;


		}
		if(l3->num < l3->ant -> num ){//anterior > atual
		     menor ->num = l3 ->num;
		     menor -> ant= NULL;
			 menor -> prox = NULL;
		}
		if(l3->num > l3->prox ->num){// proximo < atual
			menor ->num = l3-> prox ->num;
			menor -> ant= NULL;
			menor -> prox = NULL;

		}
		if(l3->num < l3->prox -> num ){//proximo > atual
		     menor ->num = l3 ->num;
		     menor -> ant= NULL;
		     menor -> prox = NULL;
		}

	}

	while (l3->num != menor ->num && l3->prox!=NULL){

		l3= l3->prox;
	}

	if(l3 -> num == menor->num ){

		No = l3;
		free(l3);
		lista3=l3;
	}

	 aux = No ->num;
	 return aux;
}//final excluirEmOrdem

int media(){// inicio  de media

	struct no *soma;
	int media;

	if(lista3 == NULL){// lista vazia
		return -1;
	}

	while (lista3->num != NULL && lista3->prox!=NULL){

	lista3= lista3->prox;
	soma += lista3->num;
	NoL = NoL++;

	}

	media = soma -> num/NoL;
	return media;

} // fim de media



int main()
{
	int elem, op,op1,op11,enter, op2, op3, aux1,aux2, aux3;

	do{//inicio menu.

	printf("\t------MENU------\n");
	printf("\t[1]- Lista 1\n");
	printf("\t[2]- Lista 2\n");
	printf("\t[3]- Lista 3\n");
	printf("\t[0]- Para Fechar\n");
	printf("\t----------------------\n");
	printf("\tDigite o Valor da Opicao: ");

	 scanf("%d",&op);
	system("cls");

	switch(op){


		case 1:// inicio lista 1
		do{

		    printf("\t--Menu Lista 1--\n");
	     	printf("\t[1] - Verificar Lista 1\n");
	    	printf("\t[2] - Inserir Lista 1\n");
	       	printf("\t[0] - Para Sair\n ");
	    	printf("\tDigite o Valor da Opicao: ");


		 scanf("%d",&op1);
	     system("cls");

	    	switch(op1){
			case 1://inicio verificar lista 1

			do{

			printf("\nVerificar Lista 1\n");
			int resp1 = verificar();
			if(resp1 == NULL){

				printf("\tLista Vazia\n");

			}else{
				printf("\tLista eEiste\n");
			}



		    getchar();
			printf("\tDigite 1 para Continuar ou outro Valor para Sair: ");
			scanf("%d",&aux1);
			printf("\n");
			system("cls");


			}while(aux1 == 1);

		    break;// fim verificar lista 1

			case 2://inicio inserir lista 1
			do{

			printf("\tInserir Lista 1\n");

			printf("\tDigite o valor não Negativo ou Neutro: ");
			getchar();
			scanf("%d",&elem);

			 int resp11 = inserirLista1(elem, lista1);//chamada da função.

			if(resp11 == 1){
				printf("\tTu é Cego");
			}else if(resp11 == 2){
				printf("\tNumero Existente\n");
			}else if(resp11 == 3){
				printf("\tNumero Existe na Lista 1 e Lista 2");
			}
			else{

			 printf("\tInserção Efetuada\n ");

		    }
		    printf("\tDigite 2 para Continuar ou outro Valor para Sair: ");

			scanf("%d",&aux1);
			system("cls");

		  }while(aux1== 2);
			break;// fim inserir lista 1

		 }//fim lista 1
	     }while(op1 !=0);
	     break;

		case 2://inicio da lista 2
			do{

			printf("\t--Menu lista 2--\n");
		    printf("\t[1] - Verificar Lista 2\n");
		    printf("\t[2] - Inserir Lista 2\n");
		    printf("\t[0] - Para Sair\n ");
		    printf("\tDigite Valor do Opicao: ");

		     scanf("%d",&op2);
		     system("cls");

		switch(op2){
			case 1:// verificar lista 2

			do{
			printf("\tVerificar Lista 2\n");
			int resp2 = verificar();

      	if(resp2 == NULL){

				printf("\tLista Vazia\n");

			}else{
				printf("\tLista Existe\n");
			}

      printf("\tDigite Numero para Busca");
      scanf("%d",&elem);
        struct no *resp = buscar(elem);

          if(resp -> num == NULL){
            printf("\tLista 2 Esta Vazia");
        }
        if(resp -> num == 2){
          printf("\tNumero Esta na Lista 2");
        }
        if (resp -> num == 2){
             printf("\tNumero esta na Lista 1 e Lista 2");
        }
         if(resp -> num == -3){
           printf("\tNumero nao Encontrado");
        }





			printf("\tDigite 1 para Continuar ou outro Valor para Sair; ");

			scanf("%d",&aux2);
			system("cls");

			}while(aux2 == 1);
		    break;// fim verificar lista 2


			case 2:// inicio inserir lista 2
			do{

			printf("\tInserir Lista 2\n");

			printf("\tDigite o valor não Negativo ou Neutro: ");

			scanf("%d",&elem);

			 int resp12 = inserirLista2(elem, lista2);//chamada da função.

			if(resp12 == 1){
				printf("\tTu é Cego");
			}else{

			 printf("\tInserção Efetuada ");

		    }
		    printf("\tDigite 2 para Continuar ou outro Valor para Sair: ");

			scanf("%d",&aux2);
			system("cls");

		  }while(aux2== 2);
			break;//fim inserir lista 2


		}//FIM LISTA 2
	   }while(op2 != 0 );


		break;
		case 3://inicio da lista 3
		do{

			printf("\t--Menu Conjunto c--\n");
			printf("\t[1] - Gerar lista 3\n");
			printf("\t[2] - Excluir Elemento da lista 3\n");
			printf("\t[0] - Para Sair\n ");
			printf("\tDigite o Valor do Opicao: ");

			scanf("%d", &op3);
			system("cls");

			switch(op3){//inicio gerar lista 3
			case 1:
				do{

			printf("\tGerar Lista 3\n");
			int resU = unirListas(lista1, lista2);
			if(resU != NULL){

				 printf("\tLista Gerada\n");
			}else{
				printf("\tLista 1 e Lista 2 esta Vazia\n");

			}
			printf("\tPara Continuar 1 ou outro Valor para Sair: ");
			scanf("%d",&aux3);
			system("cls");

		}while(aux3 == 1);

			break;//fim gerar lista 3

			case 2://inicio excluir lista 3
				do{

				printf("\tExcluir Elemento da Lista 3\n");
				 int res = excluirEmOrdem(lista3);
				if(res == -1){

				printf("\tLista Vazia\n");


			     }else{
				  printf("\tElemento Excluido ");
				  int resM = media();
			      printf("media %d",resM);

			    }
			    printf ("\tDigite 2 para Continuar ou outro Valor para Sair: ");
			    scanf("%d",&aux3);
			  	system("cls");

		        }while(aux3==2);



			break;// fim excluir lista 3




			}
		}while(op3 != 0);

		break;// fim da lista 3


      }// fim do menu

	} while(op != 0);


	return 0;


	}
