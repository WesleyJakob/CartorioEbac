#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//fim da cria��o de vari�veis
	
	//coletando informa��o do usu�rio
	 printf("Digite o cpf a ser cadastrado:");
	 scanf("%s", cpf);
	 
	 strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	 
	 FILE *file; //cria o arquivo no banco de dados
	 file = fopen(arquivo, "w"); //salva na pasta em que o arquivo est�
	 fprintf(file,cpf); //salva o valor da variavel
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // atualiza o arquivo
	 fprintf(file,","); // adiciona uma virgola no arquivo
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado:");
	 scanf("%s", nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a"); // atualiza o arquivo
	 fprintf(file,","); // adiciona uma virgola no arquivo
	 fclose(file);
	 
	 
	 printf("Digite o sobrenome a ser cadastrado:");
	 scanf("%s",sobrenome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a"); // atualiza o arquivo
	 fprintf(file,","); // adiciona uma virgola no arquivo
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado:");
	 scanf("%s", cargo);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,cargo);
	 fclose(file);
}
	

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite qual cpf deseja deletar:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	
int opcao = 0; // definindo as variaveis
int x = 1;
	for(x=1; x=1;)
	{
		system("cls");
		setlocale(LC_ALL, "portuguese"); // definindo linguagem
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t 1- Inserir Usu�rio\n");
		printf("\t 2- Consultar Usu�rio\n");
		printf("\t 3- Deletar Usu�rio\n\n");
		printf("Op��o:");//fim do menu
		
		scanf("%d", &opcao);// armazenando escolha do usu�rio na variavel opcao
		
		system("cls"); // limpando a tela ao fim da escolha do usu�rio
		
		switch(opcao){
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
				
			default:
			printf("Op��o invalida!\n");
			system("pause");
			break;
		}
	}
} // fim da sele��o
