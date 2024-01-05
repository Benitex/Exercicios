//Estruturas de Repetição – While

//1)	Faça um programa que imprima os números de 1 até 100 na tela de forma automática.
int n;
main(){
	n=1;
	while(n<=100){
		printf("%d, ",n);
		n++;
	}
}

//2)	Faça um programa que imprima os números de 100 até 1 na tela de forma automática.
int tempo;
main(){
	tempo=100;
	while(tempo>=1){
		printf("%d, ",tempo);
		tempo--;
	}
}
 
/*3)	Faça um programa que mostre a tabuada de 1 até 10 de um número inteiro lido do teclado. O resultado deve aparecer da seguinte forma:
Se o número lido for 5.
1 x 5 = 5
2 x 5 = 10
.
.
.
10 x 5 = 50
*/
int tempo,n;
main(){
	printf("Qual e o numero?\n");
	scanf("%d",&n);
	tempo=1;
	while(tempo<=10){
		printf("%d x %d = %d\n",tempo,n,n*tempo);
		tempo++;
	}
}

//5)	Faça um programa que imprima os 100 primeiros números pares.
int tempo;
main(){
	tempo=2;
	while(tempo<=200){
		printf("%d, ",tempo);
		tempo+=2;
	}
}
 
//6)	Faça um programa que imprima os múltiplos de 5 no intervalo de 1 até 500.
int tempo;
main(){
	tempo=5;
	while(tempo<=500){
		printf("%d, ",tempo);
		tempo+=5;
	}
}

//7)	Faça um programa que imprima o quadrado dos números de 1 até 20.
int tempo;
main(){
	tempo=1;
	while(tempo<=20){
		printf("%d, ",tempo*tempo);
		tempo++;
	}
}

//8)	Faça um programa que imprima os números pares de 1 a 600.
int tempo;
main(){
	tempo=2;
	while(tempo<=600){
		printf("%d, ",tempo);
		tempo+=2;
	}
}
 
//9)	Faça um programa que leia 10 números e imprima a raiz quadrada de cada número.
int tempo,x;
main(){
	tempo=1;
	while(tempo<=10){
		printf("Diga um numero.\n");
		scanf("%d",&x);
		printf("A raiz quadrada desse numero e %.0f.\n",pow(x,0.5));
		tempo++;
	}
}

//10)	Faça um programa que leia 100 números inteiros e diga qual é o menor. 
int tempo,x,menor;
main(){
	tempo=1;
	while(tempo<=100){
		printf("Diga o numero.\n");
		scanf("%d",&x);
		if(tempo==1)
			menor=x;
		if(x<menor)
			menor=x;
		tempo++;
	}
	printf("%d e o menor dos numeros citados.",menor);
}
 
//11)	Faça um programa que leia 100 números inteiros e diga quantos são ímpares.
int tempo, i,x;
main(){
	tempo=1;
	while(tempo<=100){
		printf("Diga um numero.\n");
		scanf("%d",&x);
		if(x%2)
			i++;
		tempo++;
	}
	printf("%d numeros ditos sao impares.",i);
}

//12)	Faça um programa que leia 100 números e diga quantos estão abaixo de 1000, quantos são iguais a 1000 e quantos estão abaixo de 1000.
int tempo,x,maiores,iguais,menores;
main(){
	tempo=1;
	while(tempo<=5){
		printf("Diga o numero.\n");
		scanf("%d",&x);
		if(x==1000)
			iguais++;
		if(x>1000)
			maiores++;
		if(x<1000)
			menores++;
		tempo++;
	}
	printf("%d foram maiores que 1000, %d foram menores e %d foram iguais.",maiores,menores,iguais);
}

//13)	Faça um programa que mostre na tela as letras de a até z.
char tempo;
main(){
	tempo='a';
	while(tempo<='z'){
		printf("%c, ",tempo);
		tempo++;
	}
}

//14)	Faça um programa que imprima a tabela ASCII.
char tempo;
main(){
	tempo=33;
	while(tempo<=126){
		printf("%c, ",tempo);
		tempo++;
	}
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
		tempo=n;
		while(tempo>=2){
			n*=tempo-1;
			tempo--;
		}
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
	tempo=0;
	while(tempo<=n){
		resposta=n1+n2;
		printf("%d, ",resposta);
		n2=n1;
		n1=resposta;
		tempo++
	}
}
 
//17)	Faça um programa que leia um número e verifique se ele é um número primo.
int tempo,x,denominadores;
main(){
	printf("Diga o numero que voce quer saber se e primo.\n");
	scanf("%d",&x);
	if(x>1){
		tempo=1;
		while(tempo<=x){
			if(x%tempo==0)
				denominadores=denominadores+1;
			tempo++;
		}
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
	tempo=1;
	while(tempo<x){
		if(x%tempo==0)
			divisores=divisores+tempo;
		tempo++;
	}
	if(divisores==x)
		printf("%d e um numero perfeito.",x);
	else
		printf("%d nao e perfeito.",x);
}

//23)	Faça um programa que leia um número real x e um número inteiro y e calcule x elevado a y. Obs.: Não é permitido a utilização da função pow().
float x,r;
int y;
main(){
	printf("Diga o numero e sua potencia.\n");
	scanf("%f%d",&x,&y);
	r=x;
	while(y>=2){
		r=r*x;
		y--;
	}
	printf("%.2f e a resposta.",r);
}

//24)	Faça um programa que leia um número binário qualquer e calcule o seu decimal correspondente.
int binario, decimal,ncasa,casa;
main(){
	printf("Diga o numero binario.\n");
	scanf("%d",&binario);
	if(binario==0)
		printf("Esse numero em decimal e %d.",binario);
	else{
		decimal=binario;
		ncasa=0;
		while(decimal!=0){
			ncasa++;
			decimal/=10;
		}
		decimal=0;
		casa=0;
		while(casa<=ncasa){
			if(binario%10)
				decimal=decimal+pow(2,casa);
			binario/=10;
			casa++;
		}
		printf("Esse numero em decimal e %d.",decimal);
	}
}
 
//25)	Faça um programa que leia um número decimal qualquer e calcule o seu binário correspondente.
int decimal,binario,ncasa,casa,m;
main(){
	printf("Diga o numero que sera convertido.\n");
	scanf("%d",&decimal);
	binario=decimal;
	ncasa=1;
	while(binario>=2){
		binario/=2;
		ncasa++;
	}
	binario=0;
	casa=1;
	m=1;
	while(casa<=ncasa){
			if(decimal%2)
				binario=binario+1*m;
		m*=10;
		decimal/=2;
		casa++;
	}
	printf("Esse numero em binario e %d.",binario);
}
 
/*26)	Diga quantas vezes a senteça S será executada.
a)
b=0;
do{
c=1 && 0;
S;
b=!b;
}while(!(!b)&&(!c));
2 vezes

b	c	s
0	0	1
1	0	1
0	1	1
1	0	1
0	0	2
1	1	2

b)
b=0;
do{
while (b)
S;
b=!b;
}while(b);

1 vez só.
    b	s
	0	0
	1	1
	0

c)
i=0;
for(j=1; j<=i; j++)
for(l=1; l<=j; l++)
S;
0 vezes, porque j, que vale 1 é maior que i, que vale 0, então o programa pula o for.
*/

//27)	Reescreva o trecho abaixo utilizando while e do while.
i=0;
for(j=1; j<=i; j++)
for(l=1; l<=j; l++)
S;

i=0;
j=1;
l=1;
while(j<=i){
	while(l<=){
		S;
		l++;
	}
	j++;
}
 
i=0;
j=1;
l=1;
do{
	do{
		S;
		l++;
	}(l<=j);
	j++;
}while(j<=i);

//28)	Faça um programa que calcule o valor de S(n).

//a)	S(n) = x/1 – x/2 + x/3 – x/4 + x/5 - .... +- x/n
int tempo,x,Sn,aux;
main(){
	printf("Quantas vezes sera repetido?\n");
	scanf("%d",&Sn);
	printf("Qual e o valor de x?\n");
	scanf("%d",&x);
	aux=Sn;
	Sn=0;
	for(tempo=1;tempo<=aux;tempo++){
		if(tempo%2)
			Sn=Sn+(x/tempo);
		else
			Sn=Sn-(x/tempo);
	}
	printf("%d.",Sn);
}
 
//b)	S(n) = 2/1 + 3/1 + 5/2 + 7/3 + 11/5 + 13/8 + 17/13 + 19/21 + ... (n primeiros termos)
int Snaux,tempo,n1,n2,fibotempo,primo,denominadores,tempoprimo;
float Sn,fibo;
main(){
	printf("Qual e o valor de Sn?\n");
	scanf("%d",&Snaux);
	Sn=0;
	n1=1;
	n2=0;
	primo=1;
	tempo=1;
	fibo=1;
	while(tempo<=Snaux){
		for(fibotempo=1;fibotempo<=tempo;fibotempo++){
			if(fibotempo==1){
				fibo=1;
				n2=1;
				n1=1;
			}
			else
				if(fibotempo==2){
					fibo=1;
					n2=1;
					n1=1;
				}
				else{
					fibo=n1+n2;
					n2=n1;
					n1=fibo;
				}
		}
		while(denominadores!=2){
			denominadores=0;
			primo++;
			for(tempoprimo=1;tempoprimo<=primo;tempoprimo++)
				if((primo%tempoprimo)==0)
					denominadores++;
		}
		denominadores=0;
		Sn=Sn+(primo/fibo);
			printf("%.2f=%d / %.2f\n\n",Sn,primo,fibo);
		tempo++;
	}
	printf("%.2f.",Sn);
}