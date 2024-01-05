//Modularização - Função

//1)	Faça uma função que receba um número como parâmetro e retorne 1 se o número for par e 0 se o número for ímpar.
int numero;

int evenodd(int numero);

main(){
	printf("Diga o numero.\n");
	scanf("%d",&numero);
	if(evenodd(numero))
		printf("%d e par.",numero);
	else
		printf("%d e impar.",numero);
}

int evenodd(int numero){
	if(numero%2)
		return 0;
	else
		return 1;
}

//2)	Faça uma função que receba um caractere alfa numérico e retorne 1 se for vogal e zero se não for.
char caracter;

int vogal(char valor);

main(){
	printf("Diga o caracter.\n");
	scanf("%c",&caracter);
	if(vogal(caracter))
		printf("%c e uma vogal.",caracter);
	else
		printf("%c nao e uma vogal.",caracter);
}

int vogal(valor){
	valor=toupper(char valor);
	if(valor=='A'||valor=='E'||valor=='I'||valor=='O'||valor=='U')
		return 1;
	else
		return 0;
}

//3)	Faça uma função que receba um caractere alfa numérico e retorne 1 se for consoante e zero se não for.
char caracter;

int consoante(char valor);

main(){
	printf("Diga o caracter alfanumerico.\n");
	scanf("%c",&caracter);
	if(consoante(caracter))
		printf("%c e consoante.",caracter);
	else
		printf("%c nao e consoante.",caracter);
}

int consoante(char valor){
	valor=tolower(valor);
	if((valor>'a'&&valor<'z')&&(valor!='a'||valor!='e'||valor!='i'||valor!='o'||valor!='u'))
		return 1;
	else
		return 0;
}

//4)	Faça uma função que receba um número inteiro como parâmetro e retorne o fatorial desse número
int numero;

int fatorial(int num);

main(){
	printf("Diga o numero.\n");
	scanf("%d",&numero);
	printf("O fatorial de %d e %d.",numero,fatorial(numero));
}

fatorial(int num){
	int tempo;
	for(tempo=num-1;tempo>0;tempo--)
		num*=tempo;
	return num;
}

//5)	Faça as funções necessárias para que o programa abaixo funcione corretamente.
float a, b, c;

float delta(float a,float b,float c);
float raiz1(float a,float b,float delta);
float raiz2(float a,float b,float delta);

main(){
	printf("Entre com os coeficientes da equação do segundo grau:");
	scanf("%f%f%f",&a,&b,&c);
	if (delta(a,b,c)<0)
		printf("Raízes imaginárias %d");
	else
		if (delta(a,b,c)==0)
			printf("Raiz única = %.2f", raiz1(a, b, delta(a,b,c) ) );
		else
			printf("Raizes distintas. x1 = %.2f e x2=%.2f ", raiz1(a, b, delta(a,b,c) ), raiz2(a, b, delta(a,b,c) ));
}

float delta(float a,float b,float c){
	return ((b*b)-(4*a*c));
}

float raiz1(float a,float b,float delta){
	return (((-b+pow(delta,0.5)))/(2*a));
}

float raiz2(float a,float b,float delta){
	return (((-b-pow(delta,0.5)))/(2*a));
}

//6.	Faça uma função que receba como parâmetro um número inteiro e retorne o reverso desse número, por exemplo 1567 =>
int numero;

int numero_reverso(int num);

main(){
	printf("Diga um numero inteiro.\n");
	scanf("%d",&numero);
	printf("%d ao contrario e %d.",numero,numero_reverso(numero));
}

int numero_reverso(int num){
	int reverso,casa,casas;
	reverso=num;
	while(reverso>0){
		reverso/=10;
		casas++;
	}
	reverso=0;
	for(casa=casas-1;casa>-1;casa--){
		reverso+=(num%10)*(pow(10,casa));
		num/=10;
	}
	return reverso;
}

//7.	Faça uma função que receba como parâmetro a altura e o sexo de uma pessoa (0 – masculino e 1 – feminino), em seguida a função deve retornar o peso ideal dessa pessoa. Homens => (72,7*altura) - 58 e mulheres => (62,1*altura)-44,7.
int genero;
float altura;

float peso_ideal(int gerero, float altura);

main(){
	printf("Diga o genero (0 para homem e 1 para mulher) e sua altura.\n");
	scanf("%d%f",&genero,&altura);
	while(altura<0||(genero!=0&&genero!=1)){
		printf("Insira valores validos.\n");
		scanf("%d%f",&genero,&altura);
	}
	printf("Seu peso ideal e %.2f",peso_ideal(genero,altura));
}

float peso_ideal(int genero,float altura){
	if(genero==0)
		return ((72.7*altura)-58);
	if(genero==1)
		return ((62.1*altura)-44.7);
}

//8. Faça um programa que leia a altura e sexo de um grupo de pessoas, e imprima o peso ideal até que seja digitado um valor negativo para a altura. Utilize a função criada no exercício 7 para calcular o peso ideal.
int genero;
float altura;

float peso_ideal(int gerero, float altura);

main(){
	altura=1;
	while(altura!=0){
		printf("Diga o genero (0 para homem e 1 para mulher) e sua altura.\n");
		scanf("%d%f",&genero,&altura);
		while(genero!=0&&genero!=1){
			printf("Insira valores validos.\n");
			scanf("%d%f",&genero,&altura);
		}
		if(altura>0)
			printf("Seu peso ideal e %.2f.\n\n",peso_ideal(genero,altura));
	}
}

float peso_ideal(int genero,float altura){
	if(genero==0)
		return ((72.7*altura)-58);
	if(genero==1)
		return ((62.1*altura)-44.7);
}

//9. Um número de Armstrong é um número inteiro constituído de n dígitos que tem a seguinte propriedade: seu valor é igual à soma de cada um dos valores de seus dígitos componentes elevado à n-ésima potência. Por exemplo, o número 153 (constituído de 3 dígitos) é igual a 13+53+33. Portanto 153 é um número de Armstrog. Abaixo está sendo mostrado um trecho de programa para verificar se um determinado número inteiro é um número de Armstrong. Para que o programa funcione como esperado, implemente as seguintes funções:
int expoente (int num); // recebe como parâmetro um número inteiro e retorna o número de dígitos que compõem esse algarismo.
int Armstrong (int num, int n); // recebe como parâmetro dois números inteiros. O primeiro, num, representa o número que se deseja verificar se é um número de Armstrong e o segundo, n, significa o número de dígitos que compõem esse número num. A função deve retornar a soma de cada um dos valores de seus dígitos componentes elevado a nésima potência.
int n;

int expoente(int num);
int Armstrong(int num, int n);

main(){
	printf("Entre com um número:");
	scanf("%d",&n);
	if(n==Armstrong(n,expoente(n)))
		printf("%d é um número de Armstrong.",n);
	else
		printf("%d não é um número de Armstrong.",n);
}

int expoente(int num){
	int tempo;
	tempo=0;
	while(num>0){
		num/=10;
		tempo++;
	}
	return tempo;
}

int Armstrong(int num, int n){
	int Arm,casa;
	Arm=0;
	for(casa=n;casa>0;casa--){
		Arm+=(pow(num%10,n));
		num/=10;
	}
	return Arm;
}