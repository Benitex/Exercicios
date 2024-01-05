//Estruturas de Repetição – do while

//1)	Faça um programa que imprima os números de 1 até 100 na tela de forma automática.
int n;
main(){
	n=1;
	do{
		printf("%d, ",n);
		n++;
	}while(n<=100);
}

//2)	Faça um programa que imprima os números de 100 até 1 na tela de forma automática.
int n;
main(){
	n=100;
	do{
		printf("%d, ",n);
		n--;
	}while(n>=1);
}

/*4)	Faça um programa que mostre a tabuada de 1 até 10 de um número inteiro lido do teclado. O resultado deve aparecer da seguinte forma:
Se o número lido for 5.
1 x 5 = 5
2 x 5 = 10
.
.
.
10 x 5 = 50*/
int tempo,x;
main(){
	printf("Diga o numero.\n");
	scanf("%d",&x);
	tempo=1;
	do{
		printf("%d x %d = %d\n",tempo,x,x*tempo);
		tempo++;
	}while(tempo<=10);
}

//5)	Faça um programa que imprima os 100 primeiros números pares.
int tempo;
main(){
	tempo=2;
	do{
		printf("%d, ",tempo);
		tempo+=2;
	}while(tempo<=200);
}

//6)	Faça um programa que imprima os múltiplos de 5 no intervalo de 1 até 500.
int tempo;
main(){
	tempo=5;
	do{
		printf("%d, ",tempo);
		tempo+=5;
	}while(tempo<=500);
}

//7)	Faça um programa que imprima o quadrado dos números de 1 até 20.
int tempo;
main(){
	tempo=1;
	do{
		printf("%d, ",tempo*tempo);
		tempo++;
	}while(tempo<=20);
}

//8)	Faça um programa que imprima os números pares de 1 a 600.
int tempo;
main(){
	tempo=2;
	do{
		printf("%d, ",tempo);
		tempo+=2;
	}while(tempo<=600);
}
 
//9)	Faça um programa que leia 10 números e imprima a raiz quadrada de cada número.
int tempo;
float x;
main(){
	tempo=1;
	do{
		printf("Diga o numero que voce quer saber a raiz.\n");
		scanf("%f",&x);
		printf("%.2f e a raiz.\n\n",pow(x,0.5));
		tempo++;
	}while(tempo<=3);
}