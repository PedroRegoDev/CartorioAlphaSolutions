#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cudiar das string


int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{   
    //inicio cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //%s refere-se ao armazenamento das string
	
	strcpy(arquivo, cpf);  //respons�vel por copiar os valores das string
	
	FILE *file;  //cria o arquivo no banco de dados
	file = fopen(arquivo,"w");  //cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf);  //salva o valor da vari�vel 
	fclose(file);  //fecha o arquivo  
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file, ",\n NOME: ");  //salva o valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", nome);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file,nome);  //salva o valor da vari�vel 
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file, ",\n SOBRENOME: ");  //salva o valor da vari�vel 
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", sobrenome);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file,sobrenome);  //salva o valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a"significa adicionar 
	fprintf(file, ",\n CARGO: ");  //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", cargo);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a' significa adicionar
	fprintf(file,cargo);  //salva o valor da vari�vel
	fprintf(file, ".\n\n");
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa na tela
	
	
}

int consulta()  //fun��o respos�vel por consultar os usu�rios no sistema
{   
    setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //refere-se ao armazenamento das string
	FILE *file;  //abre o banco de dados
	file = fopen(cpf, "r"); //faz a leitura do arquivo e o "r" significa ler
	
	if(file == NULL) // se a vari�vel inserida n�o corresponder a nenhuma no banco de dados
	{
		printf("Arquivo n�o localizado \n");  // retorno ao usu�rio
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n\n ");  //retorno com os dados do usu�rio cadastrado
	
	while(fgets(conteudo, 200, file) != NULL)  //prcurando o usu�rio no banco de dados
	{
		printf("%s", conteudo);  //refere-se ao armazenamento da string
	}
	
	fclose(file);
	system("pause"); //colocando o sistema em espera 
	
	
	
}

int deletar()  //fun��o respons�vel por deletar usu�rios
{
	//inicio cria��o de vari�veis 
	char cpf[40];
	//final cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //refere-se ao armazenamento das string
	
	remove(cpf);  //removendo o usu�rio do banco de dados do sistema
	
	FILE *file;  //cria o arquivo no banco de dados
	file = fopen(cpf, "r");  //abre o arquivo e o "r" significa ler 
	
	if(file == NULL)  // se a vari�vel inserida n�o corresponder a nenhum cpf registrado no banco de dados
	{
		printf("O usuario n�o se encontra no sistema. \n");  //retorne ao usu�rio
		system("pause");  //colocando o sistema em espera
	}
	
	fclose(file);
}

int main()  //fun�ao repos�vel por iniciar e abrir o menu principal
{
	int opcao=0;  //definindo as vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)  //fun��o rspons�vel por repetir o menu principal 
	{
	
	   system("cls");  //limpando o menu ap�s o usu�rio escolher a op��o
	
	   setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	   printf("### Cart�rio Alpha Solutions ###\n\n");  //inicio do menu
	   printf("Escolha a op��o desejada:\n\n");  
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Sair do sistema\n");
	   printf("Op��o: "); //final do menu

	
       scanf("%d", &opcao);  //armazenando a escolha do usu�rio 
    
       system("cls");  //limpando menu ap�s o usu�rio selecionar a op��o
      
      
	   switch(opcao) //inicio sele��o do meunu
	   {  
	     case 1:
	  	 registro(); //chamada de fun��es
    	 break;
    	
    	 case 2:
    	 consulta();
    	 break;
    	
    	 case 3:
    	 deletar();
		 break;
		 
		 case 4:
		 printf("obrigado por utilizar o sistema\n");
		 return 0;
		 break;
		 
		 
		 default:
		 printf("Essa op��o n�o est� disponivel\n");
		 system("pause");
		 break;
	   }  //fim sele��o do menu
	  	
		
    }

}
