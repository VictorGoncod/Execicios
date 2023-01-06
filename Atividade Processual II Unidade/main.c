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

			struct lista listaA,  listaB, listaC;

			int verificar(){
			  if(listaA.inicio == NULL && listaB.inicio == NULL){
			    return 0;
			  }else if(listaA.inicio==NULL){
			   return -1;
			  }
			  else {return -2;}
			  return 0;

			}

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


			int  buscaElemento(int k){

			struct no * item1 , *item2;
			int achou = 0;

			  if(listaA.inicio == NULL && listaB.inicio == NULL){
			    return NULL;
			  }
			item1 = listaA.inicio;
			item2 = listaB.inicio;
			while(item1 -> numero!= k && item1 -> proximo != NULL  ){
			   item1 = item1->proximo;

			}

			while(item2 -> numero!= k && item2 -> proximo != NULL  ){
			   item2 = item2->proximo;

			}

			if(item1->numero == k && item2->numero == k){
			  return 3;

			}

			if(item1->numero == k){
			  return 1;

			}

			if(item2->numero == k){
			  return 2;

			}



			return 0;
			}

			int inserirListaCEmOrden(){
			  struct no *novoNo, *item1, *item2;


			if(listaA.inicio == NULL && listaB.inicio == NULL){
			    return 0;
			  }else if(listaA.inicio==NULL){
			   return -1;
			  }
			  else {return -2;}




			novoNo = (struct no *)malloc(sizeof(struct no));

			item1 = listaA.inicio;
			item2 = listaB.inicio;
			while(item1 -> numero!= NULL && item2->numero != NULL && item1-> proximo != NULL && item2-> proximo != NULL  ){

			 if(item1->numero > item2->numero){

			   novoNo-> proximo = item1;
			   novoNo -> anterior = item2->anterior;
			   novoNo = item2;
			   listaC.inicio = novoNo;
			   listaC.Nos++;
			 }

			 else if(item1->numero < item2->numero){
			   novoNo-> proximo =item2;
			   novoNo-> anterior = item1->anterior;
			   novoNo = item1;
			   listaC.inicio = novoNo;
			   listaC.Nos++;

			 }else if (item1-> numero == item2->numero){
			   novoNo -> proximo = NULL;
			   novoNo -> anterior = item1->anterior;
			   novoNo = item1;
			   listaC.inicio = novoNo;
			   listaC.Nos++;

			 }
			 item1= item1->proximo;
			 item2 = item2->proximo;

			}
			return 0;
			}

			int remover(){

			struct no *item;
			int soma, media;



			if(listaC.inicio == NULL){
			  return 0;
			}
             if(listaC.inicio->numero == NULL){
              return 0;
             }

			struct no * no = listaC.inicio;
             listaC.inicio  = no-> proximo;
             if(no->proximo!= NULL){
             no->proximo->anterior = NULL;
            }

            listaC.Nos--;

            free(no);


			item = listaC.inicio;

			while(item->numero != NULL && item->proximo != NULL){

			soma= soma + item->numero;
			item = item ->proximo;

			}

			media=soma/listaC.Nos;
			return media;

			}


			int main(){


			  listaA.inicio = NULL;
			  listaA.fim = NULL;
			  listaA.Nos = 0;

			  listaB.inicio = NULL;
			  listaB.fim = NULL;
			  listaB.Nos = 0;

			  listaC.inicio = NULL;
			  listaC.fim = NULL;
			  listaC.Nos = 0;

			int numero = 0, retorno,  op, op1,op11,op2, op22, op3, op33,opv,cont = 0, enter;


			do{
			  printf("\t--------<Menu>--------\n");
        printf("\t----------------------\n");
			  printf("\t[1] - Verificar Listas\n");
			  printf("\t[2] - Lista 1\n");
			  printf("\t[3] - Lista 2\n");
			  printf("\t[4] - Lista 3\n");
			  printf("\t[0] - Para Fechar\n");
        printf("\t----------------------\n");
			  printf("\tDigite o Valor da Opicao: ");

				scanf("%d",&op);
				system("cls");

			switch(op){

			case 1:
			do{
				printf("\tVerificar Listas: \n");
			  retorno = verificar();
			  if(retorno == 0){
			   	printf("\tLista-A e Lista-B esta Vazia \n");
			  }else if(retorno == -1){
			    printf("\tLista-A esta Vazia \n");
			  }else if(retorno == -2){
			    printf("\tLista-B esta Vazia \n");
			  }
			  else{

			    printf("\tLista-A e Lista-B esta Cheia \n");

			  }
				printf("\tDigite 1 para Continuar 0 ou outro Valor para Sair : ");
				scanf("%d",&opv);
				system("cls");
			}while(opv == 1);
			break;

			case 2:

			do{


			      printf("\t-----Menu Lista 1-----\n");
            printf("\t----------------------\n");
			      printf("\t1 - Inserir Lista 1\n");
				    printf("\t2 - Buscar Elemento na Lista 1\n");
				    printf("\t0 - Para Sair\n ");
            printf("\t----------------------\n");
				    printf("\tDigite Valor da Opicao: ");

				   scanf("%d", &op1);

			       setbuf(stdin, 0);
				     system("cls");

			switch(op1){
			case 1:

			do{
			printf("\tInserir Lista 1:\n");
			printf("\tDigite Numero não Negativo: ");
			scanf("%d", &numero);
			setbuf(stdin, 0);

			retorno = inserirListaAEmOrdem(numero);

			if(retorno == 1){
			  printf("\tNumero Negativo nao pode Inserir\n ");
			}else if(retorno == -1){
			printf("\tNumero Existe nao pode Inserir\n ");
			}else{
			  printf("\tInserido\n ");
			}

			printf("\tDigite 1 para Continuar 0 ou outro valor para Sair : ");
			  scanf("%d", &op11);


			  setbuf(stdin, NULL);
				system("cls");

			}while(op11==1);

			break;

			case 2:
			do{
			printf("\tBuscar Elemento na Lista 1: \n");

			printf("\tDigite Numero para Buscar: ");
			scanf("%d", &numero);
			setbuf(stdin, 0);

			retorno= buscaElemento(numero);

			if(retorno == 0){
			  printf("\tLista esta Vazia\n");
			}
			else if (retorno == 1){
			 printf("\tNumero %d esta na Lista 1\n",numero);

			}else if(retorno == 3){
			printf("\tNumero %d esta na Lista 1 e Lista 2\n",numero);
			}

			printf("\tDigite 2 para Continuar 0 ou outro valor para Sair : ");
				scanf("%d", &op11);
			  setbuf(stdin, 0);
				system("cls");

			}while(op11 == 2);

			break;
			}
			}while(op1 != 0);


			break;

			case 3:
			do{
			      printf("\t-----Menu Lista 2-----\n");
            printf("\t----------------------\n");
			      printf("\t[1] - Inserir lista 2\n");
				    printf("\t[2] - Buscar Elemento na Lista 2\n");
				    printf("\t[0] - Para Sair\n ");
            printf("\t----------------------\n");
				    printf("\tdigite valor da Opicao: ");

			       scanf("%d", &op2);
			       setbuf(stdin, 0);
				   system("cls");

			switch(op2){
			case 1:
			do{

			printf("\tInserir Lista 2:\n");

			printf("\tDigite Numero não Negativo: ");
			scanf("%d", &numero);
			setbuf(stdin, 0);

			retorno = inserirListaBEmOrdem(numero);

			if(retorno == 1){
			  printf("\tNumero Negativo nao pode Inserir\n ");
			}else if(retorno == -1){
			printf("\tNumero Existe nao pode Inserir\n ");
			}else{
			  printf("\tInserido\n ");
			}

			printf("\tDigite 1 para Continuar 0 ou outro Valor para Sair : ");
			scanf("%d", &op22);
			setbuf(stdin, 0);
			system("cls");

			}while(op22 == 1);
			break;
			case 2:
			do{
			printf("\tBuscar Elemento na Lista 2: \n");

			printf("\tDigite Numero para Buscar: ");
			scanf("%d", &numero);
			setbuf(stdin, 0);

			retorno= buscaElemento(numero);

			if(retorno == 0){
			  printf("\tLista A Vazia\n");
			}
			else if (retorno  == 2){
			 printf("\tNumero %d esta na Lista 2\n",numero);

			}else if(retorno == 3){
			printf("\tNumero %d esta na Lista 1 e Lista 2\n",numero);
			}
			printf("\tDigite 2 para Continuar 0 ou outro Valor para Sair: ");
		    scanf("%d", &op22);
			setbuf(stdin, 0);
			system("cls");

			}while(op22==2);

			break;

			}

			}while(op2 !=0);


			break;

			case 4:
			do{
			      printf("\t-----menu lista 3-----\n");
            printf("\t----------------------\n");
			      printf("\t[1] - gerar lista 3\n");
				    printf("\t[2] - exculir Elemento na lista 3\n");
				    printf("\t[0] - Para Sair\n ");
            printf("\t----------------------\n");
				    printf("\tDigite Valor da Opicao: ");

			        scanf("%d", &op3);
			        setbuf(stdin, 0);
				      system("cls");

			switch(op3){
			case 1:

			do{
			   if(cont == 1){
			    printf("\tSo pode Gerar uma vez a Lista 3 \n");

			   printf("\tDigite 1 para Continuar 0 ou outro Valor para Sair : ");
			   scanf("%d", &op33);
			   setbuf(stdin, 0);
			   system("cls");
			}
			  while(cont == 0){
			  printf("\tGerar Lista 3\n");

			 retorno = inserirListaCEmOrden();

			  if(retorno == 0){
			  printf("\tLista 3 não Gerada Lista 1 e Lista 2 deve esta Vazia \n");
			  }else{
			    printf("\tLista 3 Gerada \n");
			  }

			  printf("\tDigite 1 para Continuar 0 ou outro Valor para Sair : ");
			  scanf("%d", &op33);
			  setbuf(stdin, 0);
			  system("cls");
			  cont ++;
			  }

			}while(op33 == 1);
			break;

			case 2:
				do{


				printf("\tExculir Elemento na lista 3\n");

			  retorno = remover();

			if(retorno == 0){
			  	printf("\tLista 3 Vazia\n");
			}else{
			  	printf("\tElemento Removido Media %d\n",retorno);
			}
			printf("\tDigite 2 para Continuar 0 ou outro Valor para Sair : ");
			scanf("%d", &op33);
			setbuf(stdin, 0);
				system("cls");

		    }while(op33 == 2);
			break;

			}

			}while(op3 !=0);
			break;
			}

			}while(op!=0);
			}
