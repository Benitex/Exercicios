//Estruturas Condicionais - Operador Ternário

//1)	Faça um programa que leia um número e diga se ele é par ou ímpar utilizando operador ternário.
int n;
main(){
	printf("Diga o numero:\n");
	scanf("%d",&n);
	(n%2)?printf("%d e impar.",n):printf("%d e par",n);
}

//2)	Faça um programa que leia um número e diga se ele é positivo, negativo ou nulo utilizando operador ternário.
float n;
main(){
	printf("Diga um numero:\n");
	scanf("%f",&n);
	(n==0)?printf("%d e nulo.",n):(n>0)?printf("%.2f e positivo",n):printf("%.2f e negativo.",n);
}

//3)	Faça um programa que leia três números e diga qual é o maior. Utilize operador ternário.

float x,y,z;
main(){
	printf("Diga os tres numeros.\n");
	scanf("%f%f%f",&x,&y,&z);
	(x>y)&&(x>z)?printf("%.2f e o maior",x):(y>z)&&(y>x)?printf("%.2f e o maior",y):printf("%.2f e o maior",z);
}
 
char v;
main(){
	printf("Diga uma vogal.\n");
	scanf("%c",&v);
	v=tolower(v);
	(v=='a')||(v=='e')||(v=='i')||(v=='o')||(v=='u')?printf("%c e uma vogal",v):printf("%c nao e vogal.",v);
}