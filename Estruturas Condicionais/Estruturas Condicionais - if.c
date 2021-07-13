//Estruturas Condicionais - if

//1)	Faça um programa que leia um número e diga se ele é par ou ímpar.
int x;
main(){
	printf("Diga um numero:\n");
	scanf("%d",&x);
	if(x%2==0)
		printf("%d e par.",x);
	else
		printf("%d e impar.",x);
}

//2)	Faça um programa que leia um número, e se ele for maior que 20 então imprima metade do número, caso contrário imprima o dobro do valor.
float  n;
main(){
	printf("Diga o numero:\n");
	scanf("%f",&n);
	if (n>20){
		printf("O numero %.2f e maior que vinte, entao virou %.2f",n,n/2);
	}
	else{
		printf("O numero %.2f e maior que 20, entao virou %.2f",n,n*2);
	}
}
 
//3)	Faça um programa que leia um número e diga se esse número é positivo, negativo ou nulo.
float n;
main(){
	printf("Diga o numero:\n");
	scanf("%f",&n);
	if(n>0)
		printf("%.2f e positivo.",n);
	else{
		if(n<0)
			printf("%.2f e negativo.",n);
		else
			printf("%.2f e nulo.",n);
	}
}

//4)	Faça um programa que imprima a raiz quadrada de um número caso ele seja positivo e o quadrado do número caso ele seja negativo.
float x;
main(){
	printf("Diga o numero\n");
	scanf("%f",&x);
	if(x>0)
		printf("A raiz de %.2f e %.2f",x,pow(x,0.5));
	if(x<0)
		printf("A potencia de %.2f e %.2f",x,pow(x,2));
	if(x==0)
	printf(“O numero tem valor nulo.”);
}
 
//5)	Faça um programa que leia um peso no planeta Terra e o número de um planeta e imprima o valor do seu peso neste planeta. A relação dos planetas é dada a seguir juntamente com o valor das gravidades relativas ao planeta Terra.
float peso;
int planeta;
main(){
	printf("Diga seu peso e o numero do planeta:\n");
	scanf("%f%d",&peso,&planeta);
	if(planeta==1)
		printf("seu peso em mercurio e %.2f",peso*0.37);
	if(planeta==2)
		printf("seu peso em venus e %.2f",peso*0.88);
	if(planeta==3)
		printf("seu peso em marte e %.2f",peso*0.38);
	if(planeta==4)
		printf("seu peso em jupiter e %.2f",peso*2.64);
	if(planeta==5)
		printf("seu peso em saturno e %.2f",peso*1.15);
	if(planeta==6)
		printf("seu peso em urano e %.2f",peso*1.17);
if(planeta<=0||planeta>6)
	printf(“Esse nao e um valor valido.”);
}

//6)	Faça um programa que leia um caractere alfanumérico e diga se ele é uma vogal.
char x;
main(){
	printf("diga se uma letra.\n");
	scanf("%c",&x);
	x=tolower(x);
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
		printf("%c e vogal",x);
	else
		printf("%c e uma consoante",x);
}

//7)	Faça um programa que leia um caractere alfanumérico e diga se ele é consoante, número ou vogal.
char a;
main(){
	printf("Diga o caracter alfa numerico:\n");
	scanf("%c",&a);
	a=tolower(a);
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		printf("%c e vogal",a);
	else
		if(a>='b'&&a<='z')
			printf("%c e uma consoante",a);
		else
			if(a>='0'&&a<='9')
				printf("%c e um numero",a);
			else
				printf("outros casos");
}

//8)	Faça um programa que peça para o usuário entrar com uma senha e diga se a senha está correta ou incorreta. A senha é definida como uma constante pelo programador.
#define SENHA "senha"

char s[13];
main(){
	printf("insira a senha.\n");
	scanf("%s",&s);
	if(strcmp(s,senha))
		printf("senha incorreta");
	else
		printf("senha correta");
}

//9)	Pesquise as funções strcpy(), strcat(), strlen(). Diga para que servem e como são usadas. Dê exemplos.

/*Primeiro, strcpy(). Essa funcao serve para copiar o
conteudo de uma string para a outra. Por exemplo,
strcpy(colar,copiar) vai copiar o conteudo da string
"copiar" e colar na string "colar". Ex no código:*/

char colar [11],copiar[11];
main(){
	printf("Diga a palavra que vai ser copiada e depois a substituida\n");
	scanf("%s%s",&copiar,&colar);
	strcpy(colar,copiar);
	printf("%s %s, como ve, a palavra foi substituida.",colar, copiar);
}
 
/*Agora, strcat(). Essa funcao junta duas strings
em apenas uma, conforme o exemplo a seguir:
strcat(base,juntar), essa funcao vai adicionar
a string "base" o conteudo da string "juntar".*/

char base [51],juntar[51];
main(){
	printf("Primeiro, diga uma palvra.\n");
	scanf("%s",&base);
	printf("%s? Otimo, agora diga outra.\n",base);
	scanf("%s",&juntar);
	strcat(base,juntar);
	printf("%s. Como ve, as duas se juntaram em uma.",base);
}

/*Por fim, strlen(). Essa funcao diz a quantidade
de letras de uma string, que fica armazenada em
uma outra variavel. Conforme o exemplo abaixo.*/

char palavra[21];
int tamanho;
main(){
	printf("Diga uma palavra.\n");
	scanf("%s",&palavra);
	tamanho=strlen(palavra);
	printf("Essa palavra tem %d letras",tamanho);
}

//10)	Faça um programa que leia um número e diga se ele é ou não é múltiplo de 3.
int m;
main(){
	printf("Diga um numero:\n");
	scanf("%d",&m);
	if(m%3)
		printf("%d nao e multiplo de 3",m);
	else
		printf("%d e multiplo de 3",m);
}

//11)	Faça um programa que leia um número e diga se ele é ou não é divisível por 5.
int m;
main(){
	printf("Diga um numero:\n");
	scanf("%d",&m);
	if(m%5)
		printf("%d nao e multiplo de 5",m);
	else
		printf("%d e multiplo de 5",m);
}

//12)	Faça um programa que leia um número e diga se ele é divisível por 3 e por 7. Obs.: utilize operador lógico.
int x;
main(){
	printf("diga o numero:\n");
	scanf("%d",&x);
	if((x%3==0)&&(x%7==0))
		printf("%d e multiplo de 3 e de 7",x);
	else
		printf("%d nao e multiplo de 3 e 7.",x);
}

//13)	Faça um programa que leia um número e diga se ele é divisível por 3 e por 7. Obs.: Não é permitido a utilização de operador lógico. Se o número for divisível por 21 ele então é divisível por 3 e por 7.
int x;
main(){
	printf("diga o numero:\n");
	scanf("%d",&x);
	if(x%21)
		printf("%d nao e multiplo de 3 e 7.",x);
	else
		printf("%d e multiplo de 3 e de 7",x);
}

//14)	Faça um programa que leia um número e diga se ele está compreendido entre 20 e 90 ou não.
float x;
main(){
	printf("diga o numero:\n");
	scanf("%f",&x);
	if((x>=20)&&(x<=90))
		printf("%.2f esta entre 20 e 90",x);
	else
		printf("%.2f nao esta entre 20 e 90",x);
}
 
//15)	Faça um programa que leia a sigla do estado em que uma pessoa nasceu e imprima uma das mensagens abaixo: •carioca •paulista •mineiro •baiano •outros casos
char sigla[3];
main(){
printf("diga a sigla do seu estado:\n");
scanf("%s",&sigla);
if(!(strcmp(sigla,"RJ")))
	printf("Carioca");
else
	if(!(strcmp(sigla,"SP")))
		printf("Paulista");
	else
		if(!(strcmp(sigla,"MG")))
			printf("Mineiro");
		else
			if(!(strcmp(sigla,"BA")))
				printf("Baiano");
			else
				printf("Outros casos.");
}
 
//16)	Faça um programa que leia um número inteiro de 3 dígitos e informe se o algarismo da casa das centenas é par ou ímpar.
int x;
main(){
	printf("Diga um numero inteiro de 3 digitos:\n");
	scanf("%d",&x);
	if(x<1000){
		x=x/100;
		if(x%2)
			printf("%d, o numero da casa das centenas, e impar. ",x);
		else
			printf("%d, o numero da casa das centenas, e par. ",x);
	}
	else
		printf("%d tem mais de 3 digitos.",x);
}
//17)	Faça um programa que leia 2 palavras e diga se elas são iguais ou diferentes.
char palavra [10],word[10];
main(){
	printf("diga duas palavras\n");
	scanf("%s%s",&palavra,&word);
	if(strcmp(palavra,word))
		printf("sao duas palavras diferentes.");
	else
		printf("sao duas palavras iguais.");
}
 
//18)	Faça um programa que leia 3 números diferentes e os imprima em ordem crescente e decrescente. Se houver números iguais exibir mensagem de erro.
float x,y,z;
main(){
	printf("Diga os tres numeros diferentes.\n");
	scanf("%f%f%f",&x,&y,&z);
	if((x==y)||(x==z)||(y==z))
		printf("Os numeros devem ser diferentes.");
	else
		if((x>y)&&(x>z)&&(y>z))
			printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",x,y,z,z,y,x);
		else
			if((x>y)&&(x>z)&&(z>y))
				printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",x,z,y,y,z,x);
			else
				if((y>x)&&(y>z)&&(x>z))
					printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",y,x,z,z,x,y);
				else
					if((y>x)&&(y>z)&&(z>x))
						printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",y,z,x,x,z,y);
					else
						if((z>x)&&(z>y)&&(x>y))
							printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",z,x,y,y,x,z);
						else
							if((z>x)&&(z>y)&&(y>x))
								printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f",z,y,x,x,y,z);
}
 
//19)	Faça um programa que leia 5 números e identifique o maior e o menor.
float a,b,c,d,e,maior,menor;
main(){
	printf("Diga 5 numeros.\n");
	scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
	maior=a;
	menor=a;
	if(b>maior)
		maior=b;
	if(c>maior)
		maior=c;
	if(d>maior)
		maior=c;
	if(e>maior)
		maior=e;
	if(b<menor)
		menor=b;
	if(c<menor)
		menor=c;
	if(d<menor)
		menor=d;
	if(e<menor)
		menor=e;
	printf("O maior e %.2f e o menor e %.2f.",maior, menor);
}
 
//20)	Faça um programa que leia 3 nomes e os coloque em ordem alfabética.
char x[10],y[10],z[10];
main(){
	printf("Diga tres nomes.\n");
	scanf("%s%s%s",&x,&y,&z);
	if((strcmp(x,y)<0)&&(strcmp(x,z)<0)&&(strcmp(y,z)<0))
		printf("%s, %s, %s. Em ordem alfabetica.",x,y,z);
	else
		if((strcmp(x,y)<0)&&(strcmp(x,z)<0)&&(strcmp(z,y)<0))
			printf("%s, %s, %s. Em ordem alfabetica.",x,z,y);
		else
			if((strcmp(y,x)<0)&&(strcmp(y,z)<0)&&(strcmp(x,z)<0))
				printf("%s, %s, %s. Em ordem alfabetica.",y,x,z);
			else
				if((strcmp(y,x)<0)&&(strcmp(y,z)<0)&&(strcmp(z,x)<0))
					printf("%s, %s, %s. Em ordem alfabetica.",y,z,x);
				else
					if((strcmp(z,x)<0)&&(strcmp(z,y)<0)&&(strcmp(x,y)<0))
						printf("%s, %s, %s. Em ordem alfabetica.",z,x,y);
					else
						if((strcmp(z,x)<0)&&(strcmp(z,y)<0)&&(strcmp(y,x)<0))
							printf("%s, %s, %s. Em ordem alfabetica.",z,y,x);
}

//21)	Faça um programa que leia 3 números e diga se eles podem ou não tomar um triângulo.  Obs.: para formar um triângulo é necessário que a soma de dois lados seja sempre maior que o terceiro lado.
float lado1,lado2,lado3;
main(){
	printf("Diga os lados do triangulo.\n");
	scanf("%f%f%f",&lado1,&lado2,&lado3);
	if(((lado1+lado2)>lado3)&&((lado2+lado3)>lado1)&&((lado1+lado3)>lado2))
		printf("Esses lados podem formar um triangulo.");
	else
		printf("Nao e possivel formar um triangulo com esses lados.");
}
22)	Faça um programa que leia 3 números e diga se eles podem ou não formar um triângulo, caso afirmativo, diga se o triângulo é equilátero, isósceles ou escaleno.
float lado1,lado2,lado3;
main(){
	printf("Diga os lados do triangulo.\n");
	scanf("%f%f%f",&lado1,&lado2,&lado3);
	if(((lado1+lado2)>lado3)&&((lado2+lado3)>lado1)&&((lado1+lado3)>lado2)){
		printf("Esses lados podem formar um triangulo.");
			if((lado1==lado2)&&(lado1==lado3))
				printf("E um triangulo equilatero.");
			else
				if((lado1!=lado2)&&(lado2!=lado3)&&(lado1!=lado3))
					printf("E um triangulo escaleno.");
				else
					printf("E um triangulo isosceles.");
	}
	else
		printf("Nao e possivel formar um triangulo com esses lados.");
}
 
//23)	Faça um programa que leia os coeficientes de uma equação do segundo grau e calcule as suas raízes. O programa deve mostrar quando possível o valor das raízes calculadas e a classificação das mesmas (raízes imaginárias, raiz única as raízes reais distintas).
float a,b,c,x;
main(){
	printf("Diga os valores de a, b e c.\n");
	scanf("%f%f%f",&a,&b,&c);
	if(((b*b)-4*a*c)<0)
		printf("Raizes imaginarias.");
	else
		if(((b*b)-4*a*c)==0){
			c=-b/(2*a);
			printf("Raiz unica. %.2f",c);
		}
		else
			if(((b*b)-4*a*c)>0){
				x=(-b+pow(((b*b)-4*a*c),0.5))/(2*a);
				c=(-b-pow(((b*b)-4*a*c),0.5))/(2*a);
				printf("Raizes reais distintas. %.2f e %.2f",c,x);
			}
}
//24)	Um comerciante comprou um produto que quer vende-lo com um lucro de 45% se o valor da compra for menor que 20 BRL caso contrário o lucro será de 30%. Entre com o valor do produto e imprima o valor de venda.
float preco;
main(){
	printf("Qual foi valor do produto?\n");
	scanf("%f",&preco);
	if(preco<20)
		printf("O produto sera vendido por: %.2f.",preco*1.45);
	else
		printf("O produto sera vendido por: %.2f.",preco*1.3);
}

//25)	Faça um programa que leia nome, nota 1 e nota 2 de um aluno. Em seguida calcule a média e informe se o aluno está aprovado reprovado ou em prova final. A média maior ou igual a 7 é aprovação menor que 3 a reprovação e demais casos o aluno está em prova final.
float nota1,nota2;
main(){
	printf("Diga as duas notas.\n");
	scanf("%f%f",&nota1,&nota2);
	nota1=(nota1+nota2)/2;
	if(nota1>=7)
		printf("Aprovado, media %.2f.",nota1);
	else
		if(nota1<3)
			printf("Reprovado, media %.2f.",nota1);
		else
			printf("Prova final, media %.2f.",nota1);
}

//26)	Faça um programa que leia um número binário de 4 dígitos e diga quantos dígitos zero existem nesse número.
int b,contador;
main(){
	printf("Diga o numero binario.\n");
	scanf("%d",&b);
	if(b/1000==0)
		contador=contador+1;
	if(((b/100)%10)==0)
		contador=contador+1;
	if(((b/10)%10)==0)
		contador=contador+1;
	if((b%10)==0)
		contador=contador+1;
	printf("Sao %d zeros.",contador);
}