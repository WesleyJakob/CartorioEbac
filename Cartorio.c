#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()// função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//fim da criação de variáveis
	
	//coletando informação do usuário
	 printf("Digite o cpf a ser cadastrado:");
	 scanf("%s", cpf);
	 
	 strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	 
	 FILE *file; //cria o arquivo no banco de dados
	 file = fopen(arquivo, "w"); //salva na pasta em que o arquivo está
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
		printf("Arquivo não encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("O usuário foi deletado com sucesso!\n");
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
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t 1- Inserir Usuário\n");
		printf("\t 2- Consultar Usuário\n");
		printf("\t 3- Deletar Usuário\n\n");
		printf("Opção:");//fim do menu
		
		scanf("%d", &opcao);// armazenando escolha do usuário na variavel opcao
		
		system("cls"); // limpando a tela ao fim da escolha do usuário
		
		switch(opcao){
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
				
			default:
			printf("Opção invalida!\n");
			system("pause");
			break;
		}
	}
} // fim da seleção
