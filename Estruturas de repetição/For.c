//Estruturas de Repetição – For

//1)	Faça um programa que imprima os números de 1 até 100 na tela de forma automática.
int x;
main(){
	for(x=1;x<100;x++)
		printf("%d, ",x);
}

//2)	Faça um programa que imprima os números de 100 até 1 na tela de forma automática.
int x;
main(){
	for(x=100;x>0;x--)
		printf("%d, ",x);
}

//3)	Preencha o que falta, no retângulo vermelho, para que o programa que imprima os números de 100 até 1 na tela de forma automática.
int i;
main(){
	for(i=1;i<=100;i++)
		printf("%d, ",101-i);
}
 
/*4)	Faça um programa que mostre a tabuada de 1 até 10 de um número inteiro lido do teclado. O resultado deve aparecer da seguinte forma:
Se o número lido for 5.
1 x 5 = 5
2 x 5 = 10
.
.
.
10 x 5 = 50
*/
int x,m;
main(){
	printf("Diga o numero inteiro: ");
	scanf("%d",&x);
	if(x%1)
		printf("Esse nao e um numero inteiro");
	else
		for(m=1;m<=10;m++)
			printf("%d, ",m*x);
}

//5)	Faça um programa que imprima os 100 primeiros números pares.
int n;
main(){
	for(n=0;n<=100;n++)
		printf("%d, ",n*2);
}

//6)	Faça um programa que imprima os múltiplos de 5 no intervalo de 1 até 500.
int n;
main(){
	for(n=1;n<=100;n++)
		printf("%d, ",n*5);
}

//7)	Faça um programa que imprima o quadrado dos números de 1 até 20.
int x;
main(){
	for(x=1;x<=20;x++)
		printf("%d, ",x*x);
}

//8)	Faça um programa que imprima os números pares de 1 a 600.
int x;
main(){
	for(x=1;x<=300;x++)
		printf("%d, ",x*2);
}

//9)	Faça um programa que leia 10 números e imprima a raiz quadrada de cada número.
int tempo;
float n;
main(){
	for(tempo=1;tempo<=10;tempo++){
		printf("Diga o numero: ");
		scanf("%f",&n);
		printf("%.2f\n",pow(n,0.5));
	}
}

//10)	Faça um programa que leia 100 números inteiros e diga qual é o menor.
int n,menor,x;
main(){
	printf("Diga o primeiro numero inteiro: ");
	scanf("%d",&n);
	menor=n;
	for(x=1;x<=100;x++){
		printf("Diga o proximo inteiro: ");
		scanf("%d",&n);
		if(n<menor)
			menor=n;
	}
	printf("%d e o menor numero.",menor);
}

//11)	Faça um programa que leia 100 números inteiros e diga quantos são ímpares.
int x,impares,tempo;
main(){
	impares=0;
	for(tempo=1;tempo<=100;tempo++){
		printf("Diga o numero: ");
		scanf("%d",&x);
		if((x%2)!=0)
			impares=impares+1;
	}
	printf("Foram digitados %d numeros impares.",impares);
}

//12)	Faça um programa que leia 100 números e diga quantos estão abaixo de 1000, quantos são iguais a 1000 e quantos estão abaixo de 1000.
float n;
int tempo,acima,abaixo,mil;
main(){
	acima=0;
	abaixo=0;
	mil=0;
	for(tempo=1;tempo<=100;tempo++){
		printf("Diga o numero: ");
		scanf("%f",&n);
		if(n==1000)
			mil=mil+1;
		if(n>1000)
			acima=acima+1;
		if(n<1000)
			abaixo=abaixo+1;
	}
	printf("%d numeros acima de 1000 foram digitados, %d numeros foram menores, %d numeros sao iguais a mil.",acima,abaixo,mil);
}

//13)	Faça um programa que mostre na tela as letras de a até z.
char l;
main(){
	for(l='a';l<='z';l++)
		printf("%c, ",l);
}

//14)	Faça um programa que imprima a tabela ASCII.
char tempo;
main(){
	for(tempo=33;tempo<=126;tempo++)
		printf("%c, ",tempo);
}

//15)	Faça um programa que leia um número inteiro e calcule o seu fatorial.
int n,tempo;
main(){
	printf("Diga o numero inteiro.\n");
	scanf("%d",&n);
	if(n==0)
		n=1;
	if(n<0)
		printf("Esse numero e negativo.");
	else{
		for(tempo=n;tempo>=2;tempo--)
			n=n*(tempo-1);
		printf("O fatorial do numero e %d",n);
	}
}

//16)	Faça um programa que leia um número inteiro e calcule e mostre os n primeiros termos da série de Fibonacci.
int n,tempo,resposta,n1,n2;
main(){
	n1=1;
	n2=0;
	printf("Quantos numeros da sequencia fibonacci serao apresentados?\n");
	scanf("%d",&n);
	for(tempo=0;tempo<=n;tempo++){
		resposta=n1+n2;
		printf("%d, ",resposta);
		n2=n1;
		n1=resposta;
	}
}

//17)	Faça um programa que leia um número e verifique se ele é um número primo.
int tempo,x,denominadores;
main(){
	printf("Diga o numero que voce quer saber se e primo.\n");
	scanf("%d",&x);
	if(x>1){
		for(tempo=1;tempo<=x;tempo++)
			if(x%tempo==0)
				denominadores=denominadores+1;
		if(denominadores>2)
			printf("Nao e primo.");
		else
			printf("E primo.");
	}
	else
		printf("Nao e primo.");
}

//18)	Um número perfeito é um número natural para o qual a soma de todos os seus divisores naturais próprios (excluindo ele mesmo) é igual ao próprio número. Exemplo 6 é um número perfeito, pois 6 = 1 + 2 +3. Exemplo 6 é um número perfeito, pois 6 = 1 + 2 +3. 28 é um número perfeito, pois 28 = 1+2+4+7+14. Faça um programa que leia um número e diga se ele é um número perfeito.
int tempo,x,divisores;
main(){
	divisores=0;
	printf("Diga o numero.\n");
	scanf("%d",&x);
	for(tempo=1;tempo<x;tempo++)
		if(x%tempo==0)
			divisores=divisores+tempo;
	if(divisores==x)
		printf("%d e um numero perfeito.",x);
	else
		printf("%d nao e perfeito.",x);
}

//19)	Faça um programa que leia um número inteiro n qualquer e mostre na tela a figura abaixo.
int n,tempo,tempoaux;
main(){
	printf("Diga um numero.\n");
	scanf("%d",&n);
	for(tempo=1;tempo<=n;tempo++){
		for(tempoaux=1;tempoaux<=tempo;tempoaux++)
			printf("*");
		printf("\n");
	}
}

/*20)	Faça um programa que leia a altura e o sexo (codificado em 1=masculino e 2=feminino) de um grupo de n pessoas lidas do teclado.
Calcule e escreva:
a) Média da altura do grupo
b) Média da altura dos homens
c) Média da altura das mulheres
d) Maior altura do grupo
e) Menor altura do grupo
*/
int tempo,n,sexo,m,f;
float altura,mediag,mediaf,mediam,maior,menor;
main(){
	printf("Diga quantas pessoas fazem parte do grupo.\n");
	scanf("%d",&n);
	for(tempo=1;tempo<=n;tempo++){
		printf("Diga o sexo e a altura, masculino e 1 e feminino e 2.\n");
		scanf("%d%f",&sexo,&altura);
		mediag=mediag+altura;
		if(sexo==1){
			mediam=mediam+altura;
			m=m+1;
		}
		if(sexo==2){
			mediaf=mediaf+altura;
			f=f+1;
		}
		if(tempo==1){
			menor=altura;
			maior=altura;
		}
		if(altura>maior)
			maior=altura;
		if(altura<menor)
			menor=altura;
	}
	if(m==0)
		m=1;
	if(f==0)
		f=1;
	printf("\nA media da altura do grupo e: %.2f,\nA media da altura das mulheres e %.2f.\nA media da altura dos homens e %.2f.\nA maior altura e %.2f e a menor e %.2f.",mediag/n,mediaf/f,mediam/m,maior,menor);
}
 
/*21)	Faça um programa que leia um número inteiro n qualquer e mostre na tela a figura abaixo.
*
**
***
**
*
*/
int n, tempo,tempom,tempon;
main(){
	printf("Qual e o tamanho do desenho?\n");
	scanf("%d",&n);
	for(tempo=1;tempo<=n;tempo++){
		for(tempom=1;tempom<=tempo;tempom++)
			printf("*");
		printf("\n");
	}
	for(tempo=n;tempo>=1;tempo--){
		for(tempon=tempo-1;tempon>=1;tempon--)
			printf("*");
		printf("\n");
	}
}
 
