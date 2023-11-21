#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cudiar das string


int registro()  //Função responsável por cadastrar os usuários no sistema
{   
    //inicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", cpf);  //%s refere-se ao armazenamento das string
	
	strcpy(arquivo, cpf);  //responsável por copiar os valores das string
	
	FILE *file;  //cria o arquivo no banco de dados
	file = fopen(arquivo,"w");  //cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf);  //salva o valor da variável 
	fclose(file);  //fecha o arquivo  
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file, ",\n NOME: ");  //salva o valor da variável
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", nome);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file,nome);  //salva o valor da variável 
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file, ",\n SOBRENOME: ");  //salva o valor da variável 
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", sobrenome);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a" significa adicionar
	fprintf(file,sobrenome);  //salva o valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e o "a"significa adicionar 
	fprintf(file, ",\n CARGO: ");  //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", cargo);  //%s refere-se ao armazenamento das string
	
	file = fopen(arquivo,"a");  //abre o arquivo e o "a' significa adicionar
	fprintf(file,cargo);  //salva o valor da variável
	fprintf(file, ".\n\n");
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa na tela
	
	
}

int consulta()  //função resposável por consultar os usuários no sistema
{   
    setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");  //coletando informação do usuário
	scanf("%s", cpf);  //refere-se ao armazenamento das string
	FILE *file;  //abre o banco de dados
	file = fopen(cpf, "r"); //faz a leitura do arquivo e o "r" significa ler
	
	if(file == NULL) // se a variável inserida não corresponder a nenhuma no banco de dados
	{
		printf("Arquivo não localizado \n");  // retorno ao usuário
	}
	
	printf("\nEssas são as informações do usuário: \n\n ");  //retorno com os dados do usuário cadastrado
	
	while(fgets(conteudo, 200, file) != NULL)  //prcurando o usuário no banco de dados
	{
		printf("%s", conteudo);  //refere-se ao armazenamento da string
	}
	
	fclose(file);
	system("pause"); //colocando o sistema em espera 
	
	
	
}

int deletar()  //função responsável por deletar usuários
{
	//inicio criação de variáveis 
	char cpf[40];
	//final criação de variáveis
	
	printf("Digite o CPF do usuário a ser deletado: ");  //coletando informação do usuário
	scanf("%s", cpf);  //refere-se ao armazenamento das string
	
	remove(cpf);  //removendo o usuário do banco de dados do sistema
	
	FILE *file;  //cria o arquivo no banco de dados
	file = fopen(cpf, "r");  //abre o arquivo e o "r" significa ler 
	
	if(file == NULL)  // se a variável inserida não corresponder a nenhum cpf registrado no banco de dados
	{
		printf("O usuario não se encontra no sistema. \n");  //retorne ao usuário
		system("pause");  //colocando o sistema em espera
	}
	
	fclose(file);
}

int main()  //funçao reposável por iniciar e abrir o menu principal
{
	int opcao=0;  //definindo as variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)  //função rsponsável por repetir o menu principal 
	{
	
	   system("cls");  //limpando o menu após o usuário escolher a opção
	
	   setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	   printf("### Cartório Alpha Solutions ###\n\n");  //inicio do menu
	   printf("Escolha a opção desejada:\n\n");  
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Sair do sistema\n");
	   printf("Opção: "); //final do menu

	
       scanf("%d", &opcao);  //armazenando a escolha do usuário 
    
       system("cls");  //limpando menu após o usuário selecionar a opção
      
      
	   switch(opcao) //inicio seleção do meunu
	   {  
	     case 1:
	  	 registro(); //chamada de funções
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
		 printf("Essa opção não está disponivel\n");
		 system("pause");
		 break;
	   }  //fim seleção do menu
	  	
		
    }

}
