#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�sel por cuidar da string



int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no "banco de dados"
	file = fopen(arquivo,"w");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}


int consulta() // fun��o responsavel por consultar os usuarios do sistema
{
    
	setlocale(LC_ALL, "Portuguese"); //Definindo o Idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL) 
	{
		printf("Arquivo n�o localizado, revise os dados e tente novamente. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		
		printf("Aqui esta os dados solicitados: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	
	system("pause");
	
}


int deletar() //Fun��o responsavel por deletar os usuarios do sistema 
{
	char cpf [40];
	
	printf("Insira o CPF do usu�rio a ser deletado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	
	printf("\tO usu�rio n�o se encontra no sistema!\n\n \tVerifique e tente novamente! \n\n");
	system("pause");
		
	}	 
	
	else 

    {

    fclose(file); // Fecha o arquivo, pois ele existe
    remove(cpf); // Agora voc� pode remover o arquivo
    printf("Usu�rio deletado!\n");
	system("pause");

    }
}


int main()
{
	int opcao=0; //Definindo variaveis
	int Laco=1;
	
	for(Laco=1;Laco=10;)
	
	
	{
		
	setlocale(LC_ALL, "Portuguese"); //Definindo o Idioma
	
	system ("cls"); //Responsavel por lim par as infroma��es da tela
	
	printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
	printf("Escolha a opcao desejada do menu \n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n");
	printf("\t4 - Encerrar o sistema \n\n");
	printf("Op��o: "); //fim do menu
	
	scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
	system ("cls");
	
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
		
		case 4:
		printf("Cartorio EBAC encerrado!");
		return(0);
		break; 	
		
		default:
		 printf("Voc� escolheu uma op��o inv�lida \n");
		 system("pause");
		break;
	}
	
	

	}	
		
}
