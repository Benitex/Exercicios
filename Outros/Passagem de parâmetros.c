//Passagem de parâmetros

//1.	Faça o passo a passo e diga o que aparecerá na tela.
//a)
int x,y,z;

void imprime1(int *z, int *x, int y);
void imprime2(int *y, int z, int *x);

main(){
	x=1;
	y=3;
	z=2;
	imprime1(&y(3), &z(2), x(1));
	printf("1, 6, 9 \n", x, y, z);
	imprime2(&x(1), y(6), &z(9));
	printf("10, 6, 12 \n", x, y, z);
}

void imprime1(int *z(3),int *x(2),int y(1)){
	*z(6)+=*z(3);
	*x(9)+=y(1)+*z(6);
	y(15)=*x(9)+*z(6);
	printf("15, 6, 9 \n", y, *z, *x);
}

void imprime2(int *y(1),int z(6),int *x(9)){
	*y(10)+=*x(9);
	z(10)=*x(9)+1;
	*x(12)=z(10)+2;
	printf("10, 12, 10 \n", z, *x, *y);
}
/*
Tela:
15, 6, 9
1, 6, 9
10, 12, 10
10, 6, 12
*/

//b)
int x,y,z;

void imprime1(int *z, int x);
void imprime2(int y, int *x);

main(){
	x=1;
	y=3;
	z=2;
	imprime1(&x(1), z(2));
	printf("2, 9, 2 \n", x, y, z);
	imprime2(x(2), &y(9));
	printf("2, 66, 10 \n", x, y, z);
}

void imprime1(int *z(1)(11), int x(2)(10)){
	*z(2)(22)+=*z(1)(11);
	x(7)(44)+=y(3)(12)+*z(2)(22);
	y(9)(66)=x(7)(44)+*z(2)(22);
	printf("9(66), 2(22), 7(44) \n", y, *z, x);
}

void imprime2(int y(2), int *x(9)){
	y(11)+=*x(9);
	z(10)=*x(9)+1;
	*x(12)=z(10)+2;
	printf("10, 12, 11 \n", z, *x, y);
	imprime1(&y(11), z(10));
	printf("10, 66, 22 \n", z, *x, y);
}
/*
Tela:
9 2 7
2 9 2
10 12 11
66 22 44
10 66 22
2 66 10 
*/

//a)	
int x,y,z;

void imprime2(int y, int *x);

main(){
	x=1;
	y=3;
	z=2;
	imprime2(x(1), &y(3));
	printf("\t1\t6\t4\n", x, y, z);
}

void imprime2(int y(1), int *x(3)){
	void imprime1(int *z(4), int x(4)){
		*z(8)+=*z(4);
		x(20)+=y(8)+*z(8);
		y(28)=x(16)+*z(8);
		printf("\t28\t28\t20\n", y, *z, x);
	}
	y(4)+=*x(3);
	z(4)=*x(3)+1;
	*x(6)=z(4)+2;
	printf("\t4\t6\t4\n", z, *x, y);
	imprime1(&y(4), z(4));
	printf("\t4\t6\t28\n", z, *x, y);
}
/*
Tela:
4   6  4
20 8  16
4   6  8 
1   6  4
*/

/*2.	Faça um programa que leia um conjunto de linhas, contendo, cada uma, o número de um empregado, a hora de início (hora, minuto e segundo) e a hora do término (hora, minuto e segundo) de uma determinada tarefa. A última linha conterá o número do empregado igual a zero. Calcule para cada empregado, a duração da tarefa que ele executou. Escreva para cada empregado, o seu número e a duração da sua tarefa em horas, minutos e segundos.
Obs.: Usar uma função do tipo int que receba como parâmetros horas, minutos e segundos e retorne o total de segundos. Usar uma função do tipo void que receba como parâmetro o total de segundos e retorne em horas, minutos e segundos.
int empregado,horaini,horafim,minutoini,minutofim,segundoini,segundofim;*/

int conversao(int horas, int minutos, int segundos);
void trabalho(int segundos);

main(){
	empregado=1;
	printf("Para finalizar, basta digitar 0 no numero do empregado.\n");
	while(empregado!=0){
		printf("Diga o numero do empregado, a hora de inicio e termino da tarefa.\n");
		scanf("%d%d%d%d%d%d%d",&empregado,&horaini,&minutoini,&segundoini,&horafim,&minutofim,&segundofim);
		horafim-=horaini;
		minutofim-=minutoini;
		segundofim-=segundoini;
		if(empregado==0)
			printf("Obrigado por usar meu programa :).");
		else
			trabalho(conversao(horafim,minutofim,segundofim));
	}
}

int conversao(int horas, int minutos, int segundos){
	segundos+=horas*3600;
	segundos+=minutos*60;
	return segundos;
}

void trabalho(int segundos){
	int horasr,minutosr,segundosr;
	segundosr=segundos;
	horasr=segundosr/3600;
	minutosr=(segundosr%3600)/60;
	segundosr=(segundosr%3600)%60;
	printf("O empregado %d trabalhou por %d horas, %d minutos e %d segundos.\n\n",empregado,horasr,minutosr,segundosr);
}
 
