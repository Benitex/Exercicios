//Estruturas de dados dinâmicas - Ponteiro

//1.	Faça um programa que leia um número inteiro e diga se é par ou ímpar.
#include<stdio.h>
int *ponteiro;
main(){
	ponteiro=(int*)malloc(sizeof(int));
	printf("Diga um numero inteiro.\n");
	scanf("%d",&*ponteiro);
	if(*ponteiro%2)
		printf("%d e impar.",*ponteiro);
	else
		printf("%d e par.",*ponteiro);
	free(ponteiro);
}

//2.	Faça um programa que leia um número inteiro e diga se é um número primo.
#include<stdio.h>
#include<stdlib.h>

int *n,*tempo,*cont;
main(){
    n=(int *)malloc(sizeof(int));
    tempo=(int *)malloc(sizeof(int));
    cont=(int *)malloc(sizeof(int));
    printf("Insira um numero.\n");
    scanf("%d",n);
    *cont=0;
    for((*tempo)=1;(*tempo)<=(*n);(*tempo)++)
		if((*n)%(*tempo)==0)
			(*cont)++;
	if((*cont)>2)
		printf("%d nao e primo.",*n);
	else
		printf("%d e primo.",*n);
    free(n);
    free(tempo);
    free(cont);
}

//3.	Faça um programa que leia um número inteiro e calcule o seu fatorial.
#include<stdio.h>
#include<stdlib.h>
int *n,*tempo;

main(){
	n=(int *)malloc(sizeof(int));
    tempo=(int *)malloc(sizeof(int));
	printf("Diga o numero inteiro.\n");
	scanf("%d",n);
	if((*n)==0)
		*n=1;
	if((*n)<0)
		printf("Esse numero e negativo.");
	else{
		for((*tempo)=*n;(*tempo)>=2;(*tempo)--)
			(*n)=(*n)*((*tempo)-1);
		printf("O fatorial do numero e %d.",*n);
	}
    free(n);
    free(tempo);
}

//4.	Faça um programa que leia um número inteiro e calcule e mostre os n primeiros termos da série de Fibonacci.
#include<stdio.h>
#include<stdlib.h>
int *n,*tempo,*resposta,*n1,*n2;

main(){
	n=(int *)malloc(sizeof(int));
    tempo=(int *)malloc(sizeof(int));
    resposta=(int *)malloc(sizeof(int));
    n1=(int *)malloc(sizeof(int));
    n2=(int *)malloc(sizeof(int));
	printf("Quantos numeros da sequencia fibonacci serao apresentados?\n");
	scanf("%d",n);
    *n1=1;
	*n2=0;
    *resposta=1;
    for((*tempo)=0;(*tempo)<=(*n);(*tempo)++){
		printf("%d, ",*resposta);
        (*resposta)=(*n1)+(*n2);
		(*n2)=(*n1);
		(*n1)=(*resposta);
	}
    free(n);
    free(tempo);
    free(resposta);
    free(n1);
    free(n2);
}

//5.	Faça um programa que leia um número binário qualquer e calcule o seu decimal correspondente.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *binario, *decimal, *ncasa, *casa;

main(){
	binario=(int *)malloc(sizeof(int));
    decimal=(int *)malloc(sizeof(int));
    ncasa=(int *)malloc(sizeof(int));
    casa=(int *)malloc(sizeof(int));
	printf("Diga o numero binario.\n");
	scanf("%d",binario);
	if((*binario)==0)
		printf("Esse numero em decimal e %d.",*binario);
	else{
		*decimal=*binario;
		*ncasa=0;
		while((*decimal)!=0){
			(*ncasa)++;
			(*decimal)/=10;
		}
		*decimal=0;
		*casa=0;
		while((*casa)<=(*ncasa)){
			if((*binario)%10)
				*decimal=(*decimal)+pow(2,*casa);
			(*binario)/=10;
			(*casa)++;
		}
		printf("Esse numero em decimal e %d.",*decimal);
	}
    free(binario);
    free(decimal);
    free(ncasa);
    free(casa);
}

//6.	Faça um programa que leia a matrícula (inteiro) e nota (real) de 5 alunos e em seguida mostre na tela as matrículas dos alunos que obtiveram a nota maior ou igual a média dos 5 alunos. Obs.: Não utilize vetor e crie uma estrutura contendo a matrícula e a nota para cada aluno.
#include<stdio.h>
#include<stdlib.h>
struct matricula{
    int matricula;
    float nota;
};
struct matricula *aluno1,*aluno2,*aluno3,*aluno4,*aluno5;
float *media;

main(){
	aluno1=(struct matricula *)malloc(sizeof(struct matricula));
    aluno2=(struct matricula *)malloc(sizeof(struct matricula));
    aluno3=(struct matricula *)malloc(sizeof(struct matricula));
    aluno4=(struct matricula *)malloc(sizeof(struct matricula));
    aluno5=(struct matricula *)malloc(sizeof(struct matricula));
    media=(float *)malloc(sizeof(float));
    printf("Entre com a matricula e a nota do aluno 1.\n");
    scanf("%d%f",&aluno1->matricula,&aluno1->nota);
    printf("Entre com a matricula e a nota do aluno 2.\n");
    scanf("%d%f",&aluno2->matricula,&aluno2->nota);
    printf("Entre com a matricula e a nota do aluno 3.\n");
    scanf("%d%f",&aluno3->matricula,&aluno3->nota);
    printf("Entre com a matricula e a nota do aluno 4.\n");
    scanf("%d%f",&aluno4->matricula,&aluno4->nota);
    printf("Entre com a matricula e a nota do aluno 5.\n");
    scanf("%d%f",&aluno5->matricula,&aluno5->nota);
    *media=((aluno1->nota)+(aluno2->nota)+(aluno3->nota)+(aluno4->nota)+(aluno5->nota))/5;
    if(aluno1->nota>*media)
        printf("%d\n",aluno1->matricula);
    if(aluno2->nota>*media)
        printf("%d\n",aluno2->matricula);
    if(aluno3->nota>*media)
        printf("%d\n",aluno3->matricula);
    if(aluno4->nota>*media)
        printf("%d\n",aluno4->matricula);
    if(aluno5->nota>*media)
        printf("%d\n",aluno5->matricula);
    free(media);
    free(aluno1);
    free(aluno2);
    free(aluno3);
    free(aluno4);
    free(aluno5);
}
/*7.	Faça um programa que leia a altura e o sexo (codificado em 1=masculino e 2=feminino) de um grupo de n pessoas lidas do teclado. Calcule e escreva:
a) Média da altura dos membros do grupo
b) Média da altura dos homens
c) Média da altura das mulheres
d) Maior altura do grupo
e) Menor altura do grupo
Obs.: crie uma estrutura contendo a altura e o sexo de cada uma das n pessoas.
*/

#include<stdio.h>
#include<stdlib.h>
int *tempo,*n,*sexo,*m,*f;
float *altura,*mediag,*mediaf,*mediam,*maior,*menor;

main(){
    tempo=(int *)malloc(sizeof(int));
    n=(int *)malloc(sizeof(int));
    sexo=(int *)malloc(sizeof(int));
    m=(int *)malloc(sizeof(int));
    f=(int *)malloc(sizeof(int));
    altura=(float *)malloc(sizeof(float));
    mediag=(float *)malloc(sizeof(float));
    mediaf=(float *)malloc(sizeof(float));
    mediam=(float *)malloc(sizeof(float));
    maior=(float *)malloc(sizeof(float));
    menor=(float *)malloc(sizeof(float));
    *m=0;
    *f=0;
    printf("Diga quantas pessoas fazem parte do grupo.\n");
	scanf("%d",n);
	for(*tempo=1;*tempo<=*n;(*tempo)++){
		printf("Diga o sexo e a altura, masculino e 1 e feminino e 2.\n");
		scanf("%d%f",sexo,altura);
		*mediag+=*altura;
		if(*sexo==1){
			(*mediam)+=*altura;
			(*m)++;
		}
		if(*sexo==2){
			(*mediaf)+=*altura;
			(*f)++;
		}
		if(*tempo==1){
			*menor=*altura;
			*maior=*altura;
		}
		if(*altura>*maior)
			*maior=*altura;
		if(*altura<*menor)
			*menor=*altura;
	}
	if(*m==0)
		*m=1;
	if(*f==0)
		*f=1;
	printf("\nA media da altura do grupo e: %.2f,\nA media da altura das mulheres e %.2f.\nA media da altura dos homens e %.2f.\nA maior altura e %.2f e a menor e %.2f.",(*mediag/ *n),(*mediaf/ *f),(*mediam/ *m),*maior,*menor);
    free(tempo);
    free(n);
    free(sexo);
    free(altura);
    free(m);
    free(f);
    free(mediag);
    free(mediaf);
    free(mediam);
    free(maior);
    free(menor);
}