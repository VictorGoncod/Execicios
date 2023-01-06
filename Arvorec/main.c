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

// * ========== PROT�TIPOS ========== * /
   menu int                ( vazio );
t_no * criaNo              ( vazio );
bool   isVazia             (t_no * n�o);
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
				sen�o
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
					printf ( " O N�MERO INFORMADO FOI REMOVIDO COM SUCESSO! \ n \ n " );
				sen�o
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
				sen�o
					printf ( " O N�MERO INFORMADO NAO ENCONTRA-SE NA ARVORE! \ n \ n " );
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

bool  isVazia (t_no * n�o)
{
	resultado bool = verdadeiro ;

	if (n�o == NULL )
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
	t_no * n�o = NULL ;

	if (raiz! = NULL )
	{
		se ( COMPARA (raiz-> dado , dado) == 0 )
			n�o = raiz;
		sen�o
		{
			no = busca (raiz-> esq , dado);

			if (n�o == NULL )
				no = busca (raiz-> dir , dado);
		}
	}

	retornar n�o;
}

t_no * buscaSetPai (t_arvore raiz, t_elemento dado, t_no ** pai)
{
	t_no * n�o = NULL ;

	if (raiz == NULL )
		* pai = NULL ;
	sen�o
	{
		se ( COMPARA (raiz-> dado , dado) == 0 )
			n�o = raiz;
		sen�o
		{
			* pai = raiz;

			se ( COMPARA (raiz-> dado , dado)> 0 )
				no = buscaSetPai (raiz-> esq , dado, pai);
			sen�o
				no = buscaSetPai (raiz-> dir , dado, pai);
		}
	}

	retornar n�o;
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
	sen�o
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
	t_no * n�o, * pai, * sub, * paiSuc, * suc;

	no = pai = sub = paiSuc = suc = NULL ;

	no = buscaSetPai (* raiz, item, & pai);
	if (n�o! = NULL )
	{
		if (no-> esq == NULL )
			sub = n�o-> dir ;
		sen�o
		{
			if (no-> dir == NULL )
				sub = n�o-> esq ;
			sen�o
			{
				paiSuc = n�o;
				sub = n�o-> dir ;
				suc = sub-> esq ;

				enquanto (suc! = NULL )
				{
					paiSuc = sub;
					sub = suc;
					suc = sub-> esq ;
				}

				if (paiSuc! = n�o)
				{
					paiSuc-> esq = sub-> dir ;
					sub-> dir = n�o-> dir ;
				}

				sub-> esq = no-> esq ;
			}
		}

		if (pai == NULL )
			* raiz = sub;
		sen�o
		{
			if (no == pai-> esq )
				pai-> esq = sub;
			sen�o
				pai-> dir = sub;

			gr�tis (n�o);
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
