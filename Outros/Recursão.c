//Recursão

//1.	Faça uma função recursiva que receba um número inteiro e calcule a soma dos n primeiros números inteiros.
int numero;

int soma(int n);

main(){
	printf("Diga o numero.\n");
	scanf("%d",&numero);
	printf("A soma dos %d primeiros numeros e %d.",numero,soma(numero));
}

int soma(int n){
	if(n==1)
		return 1;
	else
		return n+soma(n-1);
}

//2.	Faça uma função recursiva que receba um número inteiro e calcule o n-ésimo termo da série de Fibonacci.
int numero;

int Fibonnachi(int n);

main(){
	printf("Diga o numero da sequencia de Fibonnachi.\n");
	scanf("%d",&numero);
	printf("O %d° numero da sequencia de Fibonnachi e %d.",numero,Fibonnachi(numero));
}

int Fibonnachi(int n){
	if(n<=2)
		return 1;
	else
		return Fibonnachi(n-1)+Fibonnachi(n-2);
}

//3.	Faça uma função recursiva que calcule e retorne o valor de S, onde:
S=1 + 1/1! + 1/2! + 1/3! + ...+ 1/n!
int numero;

float S(int n);

main(){
	printf("Diga o numero.\n");
	scanf("%d",&numero);
	printf("O valor de S do numero %d e %.2f.",numero,S(numero));
}

float S(int n){
	int fat(int n){
		if (n==0)
			return 1;
		else
			return n*fat(n-1);
	}
	
	if(n==0)
		return 1;
	else
		return S(n-1)+1.0/fat(n);
}

//4.	Faça uma função recursiva que calcule e retorne x elevado a z. Em seguida, apresente o passo a passo de execução do programa com x=2 e z=-2. Obs.: x é um número real e z é um número inteiro. float potencia(float x, int z);
float numero;
int pot;

float potencia(float x, int z);

main(){
	printf("Diga o numero e sua potencia.\n");
	scanf("%f%d",&numero,&pot);
	printf("%.2f elevado a %d e %.2f.",numero,pot,potencia(numero,pot));
}

float potencia(float x, int z){
	if(x==0&&z==0)
		printf("Erro.");
	if(x==0&&z>0)
		return 0;
	if(x!=0&&z==0)
		return 1;
	if(x!=0&&z>0)
		return x*potencia(x,z-1);
	if(x!=0&&z<0)
		return 1/potencia(x,-z);
}

//5.	Dado o programa abaixo, construa a função recursiva mostra( ), que dado um número n positivo natural, escreva a sequência abaixo. (no exemplo abaixo n=5) 5 4 3 2 1 2 3 4 5
int n;

void mostra(int n);

main(){
	printf("Entre com um número: ");
	scanf("%d",&n);
	mostra(n);
}

void mostra(int n){
	if(n==1)
		printf("%d ",n);
	else{
		printf("%d ", n);
		mostra(n-1);
		printf("%d ",n);
	}
}

//6.	Dado o programa abaixo, construa a função recursiva tab( ), para que apareça na tela a tabuada de 1 até 10 de um número inteiro qualquer.
int n;
void tab(int n, int i);

main(){
	printf("Entre com um número: ");
	scanf("%d", &n);
	tab(n,1);
}

void tab(int n, int i){
	if(i==10)
		printf("%d\n",n*i);
	else{
		printf("%d\n",n*i);
		i++;
		tab(n,i);
	}
}

//7.	Os primeiros membros da associação de Pitágoras definiram números poligonais como sendo o número de pontos em determinadas configurações geométricas. Os primeiros números triangulares são 1, 3, 6, 10, 15. Faça uma função recursiva que receba um número natural positivo e encontre o n-ésimo número triangular.
int numero;

int triangular(int num);

main(){
	printf("Qual e a posicao do numero triangular?\n");
	scanf("%d",&numero);
	printf("%d e o numero.",triangular(numero));
}

int triangular(int num){
	if(num==1)
		return 1;
	else
		return num+triangular(num-1);
}

//8.	Os primeiros membros da associação de Pitágoras definiram números poligonais como sendo o número de pontos em determinadas configurações geométricas. Os primeiros números pentagonais são 1, 5, 12, 22. Faça uma função recursiva que receba um número natural positivo e encontre o n-ésimo número pentagonal.
int numero;

int pentagonal(int num);

main(){
	printf("Qual e a posicao do numero pentagonal?\n");
	scanf("%d",&numero);
	printf("%d e o numero.",pentagonal(numero));
}

int pentagonal(int num){
	if(num==1)
		return 1;
	else
		return ((num*3)-2)+pentagonal(num-1);
}

//9.	Construa uma função recursiva que calcule e retorne o valor de S. S = 1^1! + 2^1! + 3^2! + 4^3! + 5^5! + 6^8! + 7^13! + ... Onde ^ significa elevado. Exemplo 1^1 significa 1 elevado a 1.
int numero;
int S(int rep);

main(){
	printf("Qual e a posicao do numero?\n");
	scanf("%d",&numero);
	printf("%d e o numero na posicao %d.",S(numero),numero);
}

int S(int num){
	int Fibonnachi(int n){
		if(n<=2)
			return 1;
		else
			return Fibonnachi(n-1)+Fibonnachi(n-2);
	}
	int fat(int n){
		if (n==0)
			return 1;
		else
			return n*fat(n-1);
	}
	
	if(num==1)
		return 1;
	else
		return pow(num,fat(Fibonnachi(num)))+S(num-1);
}

//10.	Em um experimento, uma determinada colônia de bactérias tem uma população inicial de 50000 bactérias. A população é contada a cada 2 horas e, ao final de cada intervalo de 2 horas, a população triplica. Faça uma função recursiva cont( ), que calcule o número de bactérias presentes no início do n-ésimo período de tempo.
int horas;

int cont(int h);

main(){
	printf("Qual e o numero de horas a ser conferido?\n");
	scanf("%d",&horas);
	printf("Haverao %d bacterias depois de %d horas.",cont(horas),horas);
}

int cont(int h){
	if(h<2)
		return 50000;
	else
		return 3*cont(h-2);
}

//11.	Uma quantia de R$500,00 é investida em uma aplicação que paga juros de 10% capitalizados anualmente. Faça uma função recursiva P( ), que calcule a quantidade total da aplicação no início do n-ésimo ano. Lembre-se que no início do primeiro ano, tem-se aplicado R$500,00.
int anos;

int P(int tempo);

main(){
	printf("Voce quer saber quanto tera em quantos anos?\n");
	scanf("%d",&anos);
	printf("Voce tera RS%d,00 depois de %d anos.",P(anos),anos);
}

int P(int tempo){
	if(tempo==1)
		return 500;
	else
		return P(tempo-1)+(P(tempo-1)*0.1);
}

//12.	Complete o que falta para que o programa funcione corretamente. Obs.: Não é permitido criar nenhum tipo de variável.
int n;

int trans(int n, int i);

main(){
	printf("Entre com um número decimal: ");
	scanf("%d", &n);
	printf("%d em binário é igual a %d em decimal.", trans(n,1), n);
}

int trans(int n, int i){
	if (n==0)
		return 0;
	else
		return n%2*i+trans(n/2,i*10);
}

//13.	Dado o programa abaixo, reescreva a função primo(), sem utilizar nenhuma estrutura de repetição.
int n;

void primo(int n, int i, int cont);

main(){
	printf("Entre com um número: ");
	scanf("%d",&n);
	primo(n,1,0);
}

void primo(int n, int i, int cont){
	if((n%i)==0)
			cont++;
	if(i==n){
		if(cont==2)
			printf("Primo.");
		else
			printf("Nao e primo.");
	}
	else
		primo(n,i+1,cont);
}

//14.	Dado o programa abaixo, reescreva a função perfeito(), sem utilizar nenhuma estrutura de repetição.
int n;

void perfeito(int n, int i, int cont);

main(){
	printf("Entre com um número: ");
	scanf("%d",&n);
	perfeito(n,1,0);
}

void perfeito(int n, int i, int cont){
	if(i==n)
		if(cont==n)
			printf("E um numero perfeito.");
		else
			printf("Nao e um numero perfeito.");
	else
		if((n%i)==0)
			cont+=i;
		perfeito(n,i+1,cont);
}

//15.	Complete o que falta para que o programa funcione corretamente. Obs.: Não é permitido criar nenhum tipo de variável.
int n;

int trans(int n, int i);

main(){
	printf("Entre com um número binário: ");
	scanf("%d", &n);
	printf("%d em binário é igual a %d em decimal.",  n,trans(n,1));
}

int trans(int n, int i){
	if (n==0)
		return 0;
	else
		return (n%10*i)+trans(n/10,i*2);
}