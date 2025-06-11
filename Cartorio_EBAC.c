#include <stdio.h> // Biblioteca de comunica��o com o usuario
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de memoria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca de string
int registro()// fun��o responsavel por cadastrar os usuarios no sistema
{
	//criando variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser registrado: ");
	scanf("%s", cpf);//%s se refere a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;//crio o arquivo
	file = fopen(arquivo, "w");//"w" escreve o arquivo
	fprintf(file, "CPF :");//inseriu o cpf no arquivo
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//"a" atualiza o arquivo
	fprintf(file, cpf);//inserindo uma virgula no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");//"a" atualiza o arquivo
	fprintf(file, "|||");//inserindo uma separa��o nas informa��es
	fclose(file);
	
	file = fopen(arquivo, "a");//"a" atualiza o arquivo
	fprintf(file, "Nome :");
	fclose(file);
	
	printf("Digite o nome a ser registrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);	
	
	printf("Digite o sobrenome a ser registrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "|||");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo :");
	fclose(file);
	
	printf("Digite o cargo a ser registrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}
int consulta()
{
	setlocale(LC_ALL, "portuguese");//determinando a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo \nUsuario n�o localizado\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: \n");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	fclose(file);
	system("pause");
	
}
int deletar()
{
	setlocale(LC_ALL, "portuguese");//determinando a linguagem
	
	char cpf[40];
	char conteudo[200];
	char resposta[10];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo \nUsuario n�o localizado\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nDeseja deletar esse usuario? \n");//garantindo que n�o para n�o deletar o usuario errado
		printf("%s", conteudo);
		printf("\n\nDigite Y para sim e N para n�o: \n");
		scanf("%s", resposta);
		
		if(strcmp(resposta, "y") == 0 || strcmp(resposta, "Y") == 0)
		{
			fclose(file);
			remove(cpf);
			printf("Usuario deletado!\n");
		}
		else if (strcmp(resposta, "n") == 0 || strcmp(resposta, "N") == 0)
		{
			printf("Usuario n�o deletado\n");
		}
		else
		{
			printf("Resposta invalida, porfavor digite 'y' ou 'n'.\n");
		}
		
	}
	
	system("pause");
	
}


int main()//determinando as variaveis
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)//criando os la�os
	{
	
	system("cls");//apagando a tela
	
	setlocale(LC_ALL, "portuguese");//determinando a linguagem
	
	printf("___Cart�ria da EBAC___\n\n");//inicio do programa
	printf("Escolha a op��o desejada\n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Excluir nomes\n\n"); 
	printf("escolha uma op��o: ");
	
	scanf("%d", &opcao);//dando valor as variaveis
	
	system("cls");//apagando a tela denovo kkk
	
	switch(opcao)
	{
	
	case 1:
	registro();
	break;
	
	case 2:
	consulta();
    break;
    
    case 3:
   	deletar();
	break;
	
	default:
	printf("Essa op��o n�o est� disponivel!\n");
	system("pause");//fim do programa
	break;
}

	
}
}
