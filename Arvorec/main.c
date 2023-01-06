// * ========== ARVORE BINARIA DE PESQUISA ========== * /

#inclui <stdio.h>
#inclui <stdlib.h>

// * ========== TIPOS DE DADOS ========== * /
# define  true   1
# define  false  0
typedef  unsigned  char  bool ;

typedef  struct {
	int num;
} t_elemento;

typedef  struct s_no t_no;

struct s_no {
	t_no * esq;
	t_elemento dado;
	t_no * dir;
};

typedef t_no * t_arvore;

// * ========== PROTÓTIPOS ========== * /
   menu int                ( vazio );
t_no * criaNo              ( vazio );
bool   isVazia             (t_no * não);
int    COMPARA             (t_elemento item 1, t_elemento Item2);
t_no * busca               (t_arvore raiz, t_elemento dado);
t_no * buscaSetPai         (t_arvore raiz, t_elemento dado, t_no ** pai);
bool   inserir             (t_arvore * raiz, item t_elemento);
  removedor de bool             (t_arvore * raiz, item t_elemento);
void   esvaziar            (t_arvore * raiz);
void   exibirPreOrdem      (t_arvore raiz);
void   exibirInOrdem       (t_arvore raiz);
void   exibirPosOrdem      (t_arvore raiz);

int  main ( int argc, char * argv [])
{
	int op = 0 ;
	t_elemento dado;
	t_arvore raiz = NULL ;

	Faz
	{
		op = menu ();

		sistema ( " cls " );
		switch (op)
		{
			caso  1 : / * INSERIR * /
			{
				printf ( " \ t \ t INSERIR \ n \ n " );
				printf ( " Digite o numero que deseja inserir: " );
				scanf ( " % d " , & dado. num );

				if ( inserir (& raiz, dado))
					printf ( " \ n DADO INSERIDO COM SUCESSO! \ n \ n " );
				senão
					printf ( " \ n ERRO AO INSERIDO O DADO! \ n \ n " );
				sistema ( " pausa " );
				pausa ;
			}
			caso  2 : / * REMOVER * /
			{
				printf ( " \ t \ t REMOVER \ n \ n " );
				printf ( " Digite o numero que deseja remover: " );
				scanf ( " % d " , & dado. num );

				if ( removedor (& raiz, dado))
					printf ( " O NÚMERO INFORMADO FOI REMOVIDO COM SUCESSO! \ n \ n " );
				senão
					printf ( " O NUMERO INFORMADO NAO PODE SER REMOVIDO! \ n \ n " );
				sistema ( " pausa " );
				pausa ;
			}
			pausa ;

			caso  3 : / * PROCURAR * /
			{

				printf ( " \ t \ t PROCURAR \ n \ n " );
				printf ( " Digite o numero que deseja: " );
				scanf ( " % d " , & dado. num );

				if ( busca (raiz, dado)! = NULL )
					printf ( " O NUMERO INFORMADO ENCONTRA-SE NA ARVORE! \ n \ n " );
				senão
					printf ( " O NÚMERO INFORMADO NAO ENCONTRA-SE NA ARVORE! \ n \ n " );
				sistema ( " pausa " );
		    }
			caso  4 : / * ESVAZIAR * /
			{
				esvaziar (& raiz);
				printf ( " A ARVORE FOI ESVAZIADA COM SUCESSO! \ n \ n " );
				sistema ( " pausa " );
				pausa ;
			}
			caso  5 : / * EXIBIR * /
			{
				printf ( " \ n \ n \ t \ t EXIBICAO PRE ORDEM \ n \ n " );
				exibirPreOrdem (raiz);
				printf ( " \ n \ n \ t \ t EXIBICAO IN ORDEM \ n \ n " );
				exibirInOrdem (raiz);
				printf ( " \ n \ n \ t \ t EXIBICAO POS ORDEM \ n \ n " );
				exibirPosOrdem (raiz);
				printf ( " \ n \ n \ n " );
				sistema ( " pausa " );
				pausa ;
			}
			caso  0 : / * SAIR * /
			{
				printf ( " SAINDO ... " );
				pausa ;
			}
		}
	} enquanto (op! = 0 );

	return  0 ;
}

 menu int ( vazio )
{
	int op = 0 ;

	sistema ( " cls " );
	fflush (stdin);
	printf ( " ALUNO: LUCAS FIGUEIREDO PEREIRA \ n " );
	printf ( " DISCIPLINA: ESTRUTURA DE DADOS I \ n " );
	printf ( " PROFESSOR: WALACE BONFIM \ n \ n \ n " );
	printf ( " \ t \ t EDITOR DE ARVORE \ n \ n " );
	printf ( " 1 - INSERIR \ n " );
	printf ( " 2 - REMOVER \ n " );
	printf ( " 3 - PESQUISAR \ n " );
	printf ( " 4 - ESVAZIAR \ n " );
	printf ( " 5 - EXIBIR \ n " );
	printf ( " 0 - SAIR \ n \ n " );
	printf ( " DIGITE SUA OPCAO: " );
	scanf ( " % d " , & op);
	fflush (stdin);

	if ((op < 0 ) || (op> 5 ))
		op = menu ();

	return op;
}

t_no * criaNo ( vazio )
{
	t_no * novo = NULL ;

	novo = (t_no *) malloc ( sizeof (t_no));
	if (novo! = NULL )
	{
		novo-> esq = novo-> dir = NULL ;
		novo-> dado . num = 0 ;
	}

	return novo;
}

bool  isVazia (t_no * não)
{
	resultado bool = verdadeiro ;

	if (não == NULL )
		resultado = falso ;

	resultado de retorno ;
}

int  COMPARA (t_elemento item 1, t_elemento Item2)
{
	resultado int = 0 ;

	if (item1. num > item2. num )
		resultado = 1 ;
	else  if (item1. num <item2. num )
		resultado = - 1 ;

	resultado de retorno ;
}

t_no * busca (t_arvore raiz, t_elemento dado)
{
	t_no * não = NULL ;

	if (raiz! = NULL )
	{
		se ( COMPARA (raiz-> dado , dado) == 0 )
			não = raiz;
		senão
		{
			no = busca (raiz-> esq , dado);

			if (não == NULL )
				no = busca (raiz-> dir , dado);
		}
	}

	retornar não;
}

t_no * buscaSetPai (t_arvore raiz, t_elemento dado, t_no ** pai)
{
	t_no * não = NULL ;

	if (raiz == NULL )
		* pai = NULL ;
	senão
	{
		se ( COMPARA (raiz-> dado , dado) == 0 )
			não = raiz;
		senão
		{
			* pai = raiz;

			se ( COMPARA (raiz-> dado , dado)> 0 )
				no = buscaSetPai (raiz-> esq , dado, pai);
			senão
				no = buscaSetPai (raiz-> dir , dado, pai);
		}
	}

	retornar não;
}

bool  inserir (t_arvore * raiz, t_elemento item)
{
	resultado bool = falso ;

	if (* raiz == NULL )
	{
		* raiz = criaNo ();

		if (* raiz! = NULL )
		{
			(* raiz) -> dado = item;
			resultado = verdadeiro ;
		}
	}
	senão
	{
		if ( compara ((* raiz) -> dado , item)> 0 )
			resultado = inserir (& ((* raiz) -> esq ), item);
		else  if ( compara ((* raiz) -> dado , item) < 0 )
			resultado = inserir (& ((* raiz) -> dir ), item);
	}

	resultado de retorno ;
}

 removedor de bool (t_arvore * raiz, item t_elemento)
{
	resultado bool = falso ;
	t_no * não, * pai, * sub, * paiSuc, * suc;

	no = pai = sub = paiSuc = suc = NULL ;

	no = buscaSetPai (* raiz, item, & pai);
	if (não! = NULL )
	{
		if (no-> esq == NULL )
			sub = não-> dir ;
		senão
		{
			if (no-> dir == NULL )
				sub = não-> esq ;
			senão
			{
				paiSuc = não;
				sub = não-> dir ;
				suc = sub-> esq ;

				enquanto (suc! = NULL )
				{
					paiSuc = sub;
					sub = suc;
					suc = sub-> esq ;
				}

				if (paiSuc! = não)
				{
					paiSuc-> esq = sub-> dir ;
					sub-> dir = não-> dir ;
				}

				sub-> esq = no-> esq ;
			}
		}

		if (pai == NULL )
			* raiz = sub;
		senão
		{
			if (no == pai-> esq )
				pai-> esq = sub;
			senão
				pai-> dir = sub;

			grátis (não);
			resultado = verdadeiro ;
		}

	}

	resultado de retorno ;
}

void  esvaziar (t_arvore * raiz)
{
	if (* raiz! = NULL )
	{
		esvaziar (& (* raiz) -> esq );
		esvaziar (& (* raiz) -> dir );
		livre (* raiz);
		* raiz = NULL ;
	}
}

void  exibirPreOrdem (t_arvore raiz)
{
	if (raiz! = NULL )
	{
		printf ( " % d  " , raiz-> dado . num );
		exibirPreOrdem (raiz-> esq );
		exibirPreOrdem (raiz-> dir );
	}
}

void  exibirInOrdem (t_arvore raiz)
{
	if (raiz! = NULL )
	{
		exibirInOrdem (raiz-> esq );
		printf ( " % d  " , raiz-> dado . num );
		exibirInOrdem (raiz-> dir );
	}
}

void  exibirPosOrdem (t_arvore raiz)
{
	if (raiz! = NULL )
	{
		exibirPosOrdem (raiz-> esq );
		exibirPosOrdem (raiz-> dir );
		printf ( " % d  " , raiz-> dado . num );
	}
}
