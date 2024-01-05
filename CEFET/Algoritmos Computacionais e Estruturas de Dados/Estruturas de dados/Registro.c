//Estrutura de Dados Heterogêneas - Registro

//1.	Dado os trechos de códigos abaixo, faça as declarações de tipos e variáveis necessárias na linguagem C.
//a)	
struct disc{
	char genero[10];
	int quant;
	float preco;
};

struct rent{
	char endereco[20];
	struct disc fita[100];
};

struct rent locadora[100];

int j,k,l,m;

main(){
	strcpy(locadora[j].fita[k].genero, "ação");
	locadora[l].fita[m].quant = 20;
	strcpy(locadora[j].endereco, "Rua B");
	locadora[l].fita[m].preco = 15.50;
} 
//b)

struct pack{
	int estoque,peca[20];
};
struct pack produto;

struct depart{
	char z[10];
	struct pack xxx;
};
struct depart depto;

struct section{
	char nome[10];
	struct depart indice;
};
struct section setor[20];

int i,k;

main(){
	produto.estoque = 2000;
	produto.peca[i] = 3;
	depto.xxx = produto;
	strcpy(depto.z, "informática");
	setor[k].indice = depto;
	strcpy(setor[k].nome, "almoxarifado");
}
 
//c)
struct client{
	char nome[10];
	int cpf;
};
struct client cliente[1000];

struct invest{
	float entrada,saida;
};

struct ag[100]{
	struct invest totinvest;
};
struct ag agencia[50];

struct bank{
	char sigla[10];
	struct ag agen[100];
};
struct bank banco[50];

int k,i,j;

main(){
	strcpy(cliente[k].nome, "Maria");
	agencia[i].totinvest.entrada = 30.000,00;
	agencia[i].totinvest.saida = 50.000,00;
	banco[j].agen[i] = agencia[i];
	cliente[k].cpf = 12345;
	strcpy(banco[j].sigla, "B145");
}

//d) 
struct n1{
	char nome[13],tipo[13];
	int quant;
};

struct n2{
	char bairro[10];
	struct n1 fitas[100][100];	
};
struct n2 locadora[20];

int x,y,i;

main(){
	strcpy(locadora[i].fitas[x][y].nome, "X-Men");
	strcpy(locadora[i].fitas[x][y].tipo, "ação");
	locadora[i].fitas[x][y].quant = 5;
	strcpy(locadora[i].bairro, "Tijuca");
}

/*2) Foi feita uma estatística nas 200 principais cidades brasileiras para coletar dados sobre acidentes de trânsito em 2020. Foram obtidos os seguintes dados:
• Nome da cidade
• Estado (RS, SC, RJ, PR, SP, ...)
• Número de veículos de passeio
• Número de acidentes de trânsito com vítimas
Deseja-se saber:
a)	Qual o maior e menor índice de acidentes de trânsito e a que cidades pertencem
b)	Qual a média de veículos nas cidades brasileiras
c)	Qual a média de acidentes com vítimas nas cidades do Rio de Janeiro.*/
#include <stdio.h>
#define TAM 3

int maior,menor,tempo,soma,somarj,nrj;

struct cidade{
	char nome[20],estado[3];
	int veiculos,acidentes;
};
struct cidade cidades[TAM];

main(){
	soma=0;
	somarj=0;
	nrj=0;
	for(tempo=0;tempo<TAM;tempo++){
		printf("\n\nDiga o nome e a sigla do estado da proxima cidade.\n");
		fflush(stdin);
		gets(cidades[tempo].nome);
		fflush(stdin);
		gets(cidades[tempo].estado);
		printf("Diga agora o numero de veiculos e de acidentes de transito.\n");
		scanf("%d",&cidades[tempo].veiculos);
		scanf("%d",&cidades[tempo].acidentes);
		soma+=cidades[tempo].veiculos;
		if(strcmp("RJ",cidades[tempo].estado)==0){
			somarj+=cidades[tempo].acidentes;
			nrj++;
		}
		if(tempo==0){
			maior=cidades[tempo].acidentes;
			menor=cidades[tempo].acidentes;
		}
		else{
			if(cidades[tempo].acidentes>maior)
				maior=cidades[tempo].acidentes;
			if(cidades[tempo].acidentes<menor)
				menor=cidades[tempo].acidentes;
		}
	}
	for(tempo=0;tempo<TAM;tempo++){
		if(maior==cidades[tempo].acidentes)
			printf("%s foi a cidade com mais acidentes, tendo % acidentes.\n",cidades[tempo].nome,cidades[tempo].acidentes);
		if(menor==cidades[tempo].acidentes)
			printf("%s foi a cidade com menos acidentes, tendo apenas %d acidentes.\n",cidades[tempo].nome,maior);
	}
	printf("\nA media de veiculos nas cidades analisadas e %d veiculos por cidade.",soma/TAM);
	printf("\nA media de acidentes nas cidades do RJ e %d acidentes por cidade.",somarj/nrj);
}
 
/*3.	Um escritório de advocacia, especializada em direito de família, deseja fazer um sistema para automatizar todo o seu processo. Você foi designado para realizar tal tarefa. Faça um programa que receba as seguintes informações de 1000 clientes:
• nome (100 posições)
• sexo (feminino-1 e masculino-2)
• estado civil (solteiro =1, casado=2, divorciado=3, viúvo=4)
• idade
• salário do pai
• salário do cônjuge (se não for casado o salário é zero)
Com base no vetor de registro criado, faça um programa que crie um segundo vetor de registro
contendo todas essa informações, mais a pensão a que tem direito, sabendo-se que:
• caso seja homem, solteiro e tenha idade inferior a 18 anos, tem direito a pensão do pai
(15% do salário do pai)
• caso seja mulher (sexo=1) e tenha idade inferior a 21 anos tem direito a pensão do pai
(20% do salário do pai)
• se for solteira; caso contrário terá direito a pensão do cônjuge (30% do salário do
cônjuge) se for casada.
• Se não atender a nenhuma das condições acima, a pessoa não terá direito a pensão
(pensão será zero)
Ao final mostre o conteúdo do segundo vetor na tela em formato de tabela, mostrando sexo e
estado civil por extenso.*/
 
#include <stdio.h>
#define TAM 1000
struct ind{
	char nome[100];
	int sexo,estciv,idade;
	float salpai,salconj;
};

struct dir{
	struct ind pessoa[TAM];
	float pensao;
};
struct dir cliente[TAM];

int tempo;

main(){
	for(tempo=0;tempo<TAM;tempo++){
		printf("\nInsira seu nome.\n");
		fflush(stdin);
		gets(cliente[tempo].pessoa[tempo].nome);
		printf("\nAgora, insira seu sexo, 1 para feminino e 2 para masculino.\n");
		scanf("%d",&cliente[tempo].pessoa[tempo].sexo);
		while(cliente[tempo].pessoa[tempo].sexo>2||cliente[tempo].pessoa[tempo].sexo<1){
			printf("\nInsira uma resposta valida.\n");
			scanf("%d",&cliente[tempo].pessoa[tempo].sexo);
		}
		printf("\nInsira seu estado civil, 1 para solteiro, 2 para casado, 3 para divorciado e 4 para viuvo.\n");
		scanf("%d",&cliente[tempo].pessoa[tempo].estciv);
		while(cliente[tempo].pessoa[tempo].estciv>4||cliente[tempo].pessoa[tempo].estciv<1){
			printf("\nInsira uma resposta valida.\n");
			scanf("%d",&cliente[tempo].pessoa[tempo].estciv);
		}
		printf("\nInsira sua idade.\n");
		scanf("%d",&cliente[tempo].pessoa[tempo].idade);
		if(cliente[tempo].pessoa[tempo].estciv==2){
			printf("\nPor fim, insira o salario do seu pai e do seu conjuge.\n");
			scanf("%f%f",&cliente[tempo].pessoa[tempo].salpai,&cliente[tempo].pessoa[tempo].salconj);
		}
		else{
			printf("\nPor fim, insira o salario do seu pai.\n");
			scanf("%f",&cliente[tempo].pessoa[tempo].salpai);
			cliente[tempo].pessoa[tempo].salconj=0;
		}
		if(cliente[tempo].pessoa[tempo].sexo==2)
			if(cliente[tempo].pessoa[tempo].estciv==1&&cliente[tempo].pessoa[tempo].idade<18)
				cliente[tempo].pensao=0.15*cliente[tempo].pessoa[tempo].salpai;
			else
				cliente[tempo].pensao=0;
		else
			if(cliente[tempo].pessoa[tempo].estciv==2)
				cliente[tempo].pensao=0.3*cliente[tempo].pessoa[tempo].salconj;
			else
				if(cliente[tempo].pessoa[tempo].estciv==1&&cliente[tempo].pessoa[tempo].idade<21)
					cliente[tempo].pensao=0.2*cliente[tempo].pessoa[tempo].salpai;
				else
					cliente[tempo].pensao=0;
	}
	printf("\n\n\nNome:\tIdade:\tSexo:\tEstado civil\tSalario do pai:\tSalario do conjuge:\tPensao:\n");
	for(tempo=0;tempo<TAM;tempo++){
		printf("%s\t%d\t",cliente[tempo].pessoa[tempo].nome,cliente[tempo].pessoa[tempo].idade);
		if(cliente[tempo].pessoa[tempo].sexo==1)
			printf("Mulher\t");
		else
			printf("Homem\t");
		if(cliente[tempo].pessoa[tempo].estciv==1)
			printf("Solteiro\t");
		if(cliente[tempo].pessoa[tempo].estciv==2)
			printf("Casado\t");
		if(cliente[tempo].pessoa[tempo].estciv==3)
			printf("Divorciado\t");
		if(cliente[tempo].pessoa[tempo].estciv==4)
			printf("Viuvo\t");
		printf("%.2f\t%.2f\t%.2f\n",cliente[tempo].pessoa[tempo].salpai,cliente[tempo].pessoa[tempo].salconj,cliente[tempo].pensao);
	}
}

/*4.	Faça um programa que gerencie o estoque de um mercado e:
•	crie e leia um vetor de 5 produtos, com os dados: código (inteiro), nome (máximo 15 letras), preço e quantidade.
•	leia um pedido, composto por um código de produto e a quantidade. Localize este código no vetor e, se houver quantidade suficiente para atender ao pedido integralmente, atualize o estoque, e informe o usuário o valor total do pedido realizado.
Repita este processo até ler um código igual a zero.
Se por algum motivo não for possível atender ao pedido, mostre uma mensagem informando qual erro ocorreu.*/
#include <stdio.h>
#define TAM 5
struct produto{
	int code,quantidade;
	float preco;
	char nome[16];
};
struct produto prod[TAM];

int tempo,codigo,quant;

main(){
	for(tempo=0;tempo<TAM;tempo++){
		printf("\nInsira o codigo do produto.\n");
		scanf("%d",&prod[tempo].code);
		printf("Insira o nome do produto.\n");
		fflush(stdin);
		gets(prod[tempo].nome);
		printf("Insira o preco do produto.\n");
		scanf("%f",&prod[tempo].preco);
		printf("Insira a quantidade do produto.\n");
		scanf("%d",&prod[tempo].quantidade);
	}
	do{
		printf("\nInsira o codigo e a quantidade do produto desejado.\n");
		scanf("%d%d",&codigo,&quant);
		for(tempo=0;tempo<TAM;tempo++)
			if(codigo==prod[tempo].code)
				if(quant<=prod[tempo].quantidade){
					prod[tempo].quantidade=prod[tempo].quantidade-quant;
					printf("O valor a ser pago e de R$%.2f.\n",prod[tempo].preco*quant);
				}
				else
					printf("Quantidade indisponivel.\n");
			else
				if(tempo==TAM-1)
					printf("Nao ha nenhum produto com esse codigo no estoque.\n");
	}while(codigo!=0);
}