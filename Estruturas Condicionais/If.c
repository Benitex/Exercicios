//Estruturas Condicionais - if
//Parte 1

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
//22)	Faça um programa que leia 3 números e diga se eles podem ou não formar um triângulo, caso afirmativo, diga se o triângulo é equilátero, isósceles ou escaleno.
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

//Parte 2

//1)	Dado três valores A, B e C, faça um programa que verifique se com esses valores é possível fazer um triângulo, e se for possível, diga se o triângulo retângulo = 90°, triângulo obtusângulo >90° ou triângulo acutângulo <90°.
float A,B,C,maior,menor,meio;
main(){
	printf("Diga tres numeros para formar os lados do triangulo.\n");
	scanf("%f%f%f",&A,&B,&C);
	if((A>=(B+C))||(B>=(A+B))||(C>=(A+B)))
		printf("Nao e possivel formar um triangulo com esses lados.");
	else{
		maior=A;
		menor=A;
		meio=A;
		if((A!=B)&&(A!=C)&&(C!=B))
			if(B>maior)
				maior=B;
			if(C>maior)
				maior=C;
			if(B<menor)
				menor=B;
			if(C<menor)
				menor=C;
			if((A!=maior)&&(A!=menor))
				meio=A;
			if((B!=maior)&&(B!=menor))
				meio=B;
			if((C!=maior)&&(C!=menor))
				meio=C;
		if((A==B)&&(A!=C))
			if(C<A)
				menor=C;
			else
				maior=C;
		if((B==C)&&(B!=A))
			if(B>A){
				maior=B;
				meio=C;
			}
			else{
				meio=C;
				menor=B;
			}
		if((C==A)&&(C!=B))
			if(B<A)
				menor=B;
			else
				maior=B;
		if((maior*maior)==((menor*menor)+(meio*meio)))
			printf("Triangulo retangulo %.2f %.2f %.2f.",maior,meio,menor);
		else
			if((maior*maior)<((menor*menor)+(meio*meio)))
				printf("Triangulo acutangulo %.2f %.2f %.2f.",maior,meio,menor);
			else
				printf("Triangulo obtusangulo %.2f %.2f %.2f.",maior,meio,menor);
	}
}

//2)	Dado três valores A, B e C, faça um programa que verifique se com esses valores é possível fazer um triângulo, e se um triângulo retângulo, determinar e imprimir seus ângulos internos.
float A,B,C;
main(){
	printf("Diga tres numeros para formar os lados do triangulo.\n");
	scanf("%f%f%f",&A,&B,&C);
	if((A>(B+C))||(B>(A+B))||(C>(A+B)))
		printf("Nao e possivel formar um triangulo com esses lados.");
	else{
		if((A>B)&&(A>C)&&(B>C))
			if((A*A)==((B*B)+(C*C)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",B,C,A,B,A,C);
			else
				printf("Nao e triangulo retangulo.");
		if((A>B)&&(A>C)&&(C>B))
			if((A*A)==((B*B)+(C*C)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",B,C,A,C,A,B);
			else
				printf("Nao e triangulo retangulo.");
		if((A>B)&&(A>C)&&(C==B))
			if((A*A)==((B*B)+(C*C)))
				printf("O triangulo tem um angulo de 90° entre %.2f e %.2f, e dois outros angulos de 45°",B,C);
			else
				printf("Nao e triangulo retangulo.");
		if((B>A)&&(B>C)&&(A>C))
			if((B*B)==((A*A)+(C*C)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",A,C,B,A,B,C);
			else
				printf("Nao e triangulo retangulo.");
		if((B>A)&&(B>C)&&(C>A))
			if((B*B)==((A*A)+(C*C)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",A,C,B,C,B,A);
			else
				printf("Nao e triangulo retangulo.");
		if((B>A)&&(B>C)&&(A==C))
			if((B*B)==((A*A)+(C*C)))
				printf("O triangulo tem um angulo de 90° entre %.2f e %.2f, e dois outros angulos de 45°",A,C);	
			else
				printf("Nao e triangulo retangulo.");
		if((C>A)&&(C>B)&&(A>B))
			if((C*C)==((A*A)+(B*B)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",A,B,C,A,C,B);
			else
				printf("Nao e triangulo retangulo.");
		if((C>A)&&(C>B)&&(B>A))
			if((C*C)==((A*A)+(B*B)))
				printf("O angulo entre %.2f e %.2f vale 90°, entre %.2f e %.2f vale 30° e entre %.2f e %.2f vale 60°. ",A,B,C,B,C,A);
			else
				printf("Nao e triangulo retangulo.");
		if((C>A)&&(C>B)&&(A==B))
			if((C*C)==((A*A)+(B*B)))
				printf("O triangulo tem um angulo de 90° entre %.2f e %.2f, e dois outros angulos de 45°",A,B);	
			else
				printf("Nao e triangulo retangulo.");
	}
}

//3)	Faça um programa que leia um número x e calcule e imprima o valor de f(x).
int x;
main(){
	printf("Diga o valor de x.\n");
	scanf("%d",&x);
	if(x<=1)
		printf("f(x)=1");
	else
		if(x<=2)
			printf("f(x)=2");
		else
			if(x<=3)
				printf("f(x)=%d",x*x);
			else
				printf("f(x)=%d",x*x*x);
	
}
4)	Faça um programa que leia um número x e calcule e imprima o valor de f(x).
float x;
main(){
	printf("Diga o valor de x.\n");
	scanf("%f",&x);
	x=((5*x)+3)/(pow((pow(x,2)-16),0.5));
	printf("f(x)=%.2f",x);
}
 
//5)	Faça um programa que a partir da idade e peso do paciente, calcule a dosagem de determinado medicamento e imprima a receita informando quantas gotas do medicamento o paciente deve tomar por dose. Considere que o medicamento em questão possui 500mg por ml, e que cada ml corresponde a 20 gotas.
int idade;
float peso, dosagem;
main(){
	printf("Diga sua idade e seu peso.\n");
	scanf("%d%f",&idade,&peso);
	if((idade>=12)&&(peso>=60))
		printf("40 gotas.");
	else
		if((idade>=12)&&(peso<60))
			printf("35 gotas.");
		else{
			if((peso>=5)&&(peso<=9))
				printf("5 gotas.");
			if((peso>=9.1)&&(peso<=16))
				printf("10 gotas.");
			if((peso>=16.1)&&(peso<=24))
				printf("15 gotas.");
			if((peso>=24.1)&&(peso<=30))
				printf("20 gotas.");
			if(peso>30)
				printf("30 gotas.");	
		}
}
 
//6)	Faça um programa que informe o total de calorias de uma refeição a partir do usuário que irá informar o prato, a sobremesa e a bebida. Veja a tabela a seguir. Mostre todas essas opções na tela. 
int prato, sobremesa, bebida,calorias;
main(){
	printf("Esses sao os pratos, sobremesas e bebidas disponiveis:\n================================================================================\n   Pratos: 1- Vegetariano. 2- Peixe. 3- Frango. 4- Carne.\n   Sobremesa: 1- Abacaxi. 2- Sorvete Diet. 3- Mouse Diet. 4- Mouse chocolate.\n   Bebida: 1- Cha. 2- Suco de laranja. 3- Suco de melao. 4- Refrigerante Diet.\n================================================================================\nEscolha seu pedido, informe a numeracao na ordem Prato, Sobremesa, Bebida e diremos as calorias da refeicao.\n");
	scanf("%d%d%d",&prato,&sobremesa,&bebida);
	if(prato==1)
		calorias=calorias+180;
	if(prato==2)
		calorias=calorias+230;
	if(prato==3)
		calorias=calorias+250;
	if(prato==4)
		calorias=calorias+350;
	if(sobremesa==1)
		calorias=calorias+75;
	if(sobremesa==2)
		calorias=calorias+110;
	if(sobremesa==3)
		calorias=calorias+170;
	if(sobremesa==4)
		calorias=calorias+200;
	if(bebida==1)
		calorias=calorias+20;
	if(bebida==2)
		calorias=calorias+70;
	if(bebida==3)
		calorias=calorias+100;
	if(bebida==4)
		calorias=calorias+65;
	printf("Seu prato tem %d calorias.",calorias);
}

//7)	Faça um programa que leia o número correspondente ao mês atual e os dígitos (somente os quatro números) de uma placa de veículo, e através do número finalizador da placa (algarismo da casa das unidades) determine se o IPVA do veículo já venceu, vence no mês corrente ou ainda irá vencer.
int mes,placa;
main(){
	printf("Diga a o mes atual e a placa do seu veiculo.\n");
	scanf("%d%d",&mes,&placa);
	placa=placa%10;
	if(mes>=11)
		printf("Ja venceu rapa.");
	else{
		if(placa==0){
			if(mes==10)
				printf("E nesse mes, corre.");
			if(mes<=9)
				printf("Ainda falta, ta safe.");
			if(mes>10)
				printf("Ja venceu rapa.");
		}
		else{
			if(mes<placa)
				printf("Ainda falta, ta safe.");
			if(mes==placa)
				printf("E nesse mes, corre.");
			if(mes>placa)
				printf("Ja venceu rapa.");	
		}
	}
}

//8)	Faça um programa que verifique se um ano é bissexto. Anos divisíveis por 4 e não divisíveis por 100 são bissextos. Anos divisíveis por 400 são bissextos.
int ano;
main(){
	printf("Diga qual e o ano.\n");
	scanf("%d",&ano);
	if(((ano%400)==0)||(((ano%4)==0)&&((ano%100)!=0)))
		printf("E um ano bissexto.");
	else
		printf("Nao e um ano bissexto.");
}

//9)	Faça um programa que leia uma data no formato dd – mm – aaaa. E em seguida escreva qual será o próximo dia, mês e ano.
int dia,mes,ano;
main(){
	printf("Diga qual e o dia, mes e ano, repectivamente.\n");
	scanf("%d%d%d",&dia,&mes,&ano);
	if((dia==31)&&(mes==12)){
		dia=1;
		mes=1;
		ano=ano+1;
	}
	else
		if((dia==28)&&(mes==2)&&(((ano%400)==0)||(((ano%4)==0)&&(ano%100)!=0))){
			dia=29;
		}
		else
			if(((dia==28)&&(mes==2)&&(!(((ano%400)==0)||(((ano%4)==0)&&(ano%100)!=0))))){
				dia=1;
				mes=3;
			}
			else{
				if(((dia==31)&&((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)))||((dia==30)&&((mes==4)||(mes==6)||(mes==9)||(mes==11)))){
					dia=1;
					mes=mes+1;
				}
				else
					dia=dia+1;
			}
	if((ano<1)||(mes>12)||(mes<1)||(dia>31)||(dia<1)||((dia==29)&&(mes==2)&&(!(((ano%400)==0)||(((ano%4)==0)&&(ano%100)!=0))))||((dia>=30)&&(mes==2))||((dia==31)&&((mes==4)||(mes==6)||(mes==9)||(mes==11))))
		printf("Essa data nao existe seu pamonha.");
	else
		printf("Amanha e dia %d do mes %d do ano de %d.\n",dia,mes,ano);
}
 
//10)	Faça um programa que leia dois números binários de 3 dígitos e efetue a soma desses dois números binários.
int n1,n2,resultado,s;
main(){
	printf("Diga os numeros binarios de tres digitos que serao somados.\n");
	scanf("%d%d",&n1,&n2);
	if(((n1%10)+(n2%10))==2){
		resultado=0;
		s=1;
	}
	else
		if(((n1%10)+(n2%10))==1){
			resultado=1;
			s=0;
		}
		else{
			resultado=0;
			s=0;
		}
	if((((n1/10)%10)+((n2/10)%10)+s)==3){
		resultado=resultado+10;
		s=1;
	}
	else
		if((((n1/10)%10)+((n2/10)%10)+s)==2)
			s=1;
		else
			if((((n1/10)%10)+((n2/10)%10)+s)==1){
				resultado=resultado+10;
				s=0;
			}
			else{
				s=0;
			}
	if(((n1/100)+(n2/100)+s)==3)
		resultado=resultado+1100;
	else
		if(((n1/100)+(n2/100)+s)==2)
			resultado=resultado+1000;
		else
			if(((n1/100)+(n2/100)+s)==1)
				resultado=resultado+100;
	if((n1>1000)||(n2>100))
		printf("Esse numero tem mais de 3 casas decimais.");
	else	
		printf("%d e o resultado da soma",resultado);
}