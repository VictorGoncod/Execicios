programa
{
	
	funcao inicio()
	{
		real n1, n2, n3, n4, media
		cadeia aluno

		escreva("Digite o Nome do Aluno: ")
		leia(aluno)
		escreva("Escreva nota 1:")
		leia(n1)
		escreva("Escreva nota 2:")
		leia(n2)
		escreva("Escreva nota 3:")
		leia(n3)
		escreva("Escreva nota 4:")
		leia(n4)

		media = (n1+n2+n3+n4)/4

		escreva("O sua media é: " + media )

		se(media>=7) {
			
			     escreva("\n" + "Parabéns!! Você foi aprovado")
			}senao {
				escreva("\n" + "Inelizmente você foi Reprovado")
				}
		
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 495; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */