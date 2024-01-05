//Estrutura de Dados Homogêneos – Vetor

//1.	Dado um vetor de 100 elementos, determine o maior e o menor elemento do vetor
#define T 100
int tempo;
float maior,menor,x[T];
main(){
	for(tempo=0;tempo<T;tempo++){
		printf("Diga o %d° numero.\n",tempo+1);
		scanf("%f",&x[tempo]);
		if(tempo==0){
			maior=x[tempo];
			menor=x[tempo];
		}
		else{
			if(x[tempo]>maior)
				maior=x[tempo];
			if(x[tempo]<menor)
				menor=x[tempo];
		}
	}
	printf("%.2f e o menor numero e %.2f e o maior.",menor,maior);
}
 
//2.	Dado um vetor de 100 elementos, determine a diferença entre a soma dos elementos de índice par e a soma dos elementos de índice ímpar.
#define TAM 100
int tempo,valor[TAM],pares,impares,diferenca;
main(){
	pares=0;
	impares=0;
	diferenca=0;
	for(tempo=0;tempo<TAM;tempo++){
		printf("insira o %d valor.\n",tempo+1);
		scanf("%d",&valor[tempo]);
		if(valor[tempo]%2)
			impares+=valor[tempo];
		else
			pares+=valor[tempo];
	}
	if(pares>impares)
		diferenca=pares-impares;
	else
		diferenca=impares-pares;
	printf("A diferenca entre os pares e impares e %d.",diferenca);
}
 
//3.	Dado um vetor com 20 elementos, gerar outro vetor que contenha somente números múltiplos de 3 encontrados no primeiro vetor.
#define TAM 20
int tempo,valor[TAM],m[TAM],tempom;
main(){
	tempom=0;
	for(tempo=0;tempo<TAM;tempo++){
		printf("Entre com o valor.\n");
		scanf("%d",&valor[tempo]);
		if((valor[tempo]%3)==0){
			m[tempom]=valor[tempo];
			tempom++;
		}
	}
	for(tempo=0;tempo<tempom;tempo++)
		printf("%d, ",m[tempo]);
}
 
//4.	Existem 20 candidatos à presidência, com códigos que variam de 1 até 20. Codificou-se 21 para votos brancos e 22 para votos nulos. Cada voto vem em um cartão (contendo só um voto) e o último cartão vem com o número 0 (zero). Faça um programa que auxilie a operação dos votos, imprimindo a quantidade de votos de cada candidato, o número de votos em branco, o número de votos nulos e o total de votantes. Imprima também o(s) candidato(s) que venceram a eleição e o número de votos do(s) vencedor(es).
#define TAM 23
int vencedor,votosvencedor,candidato[TAM],gados,tempo,empate;
main(){
	gados=-1;
	for(tempo=0;tempo<TAM;tempo++)
		candidato[tempo]=0;
	tempo=0;
	empate=0;
	printf("Escreva o numero 0 para encerrar a votacao.\n");
	while(candidato[0]==0){
		printf("Diga o numero do seu candidato.\n");
		scanf("%d",&tempo);
		if(tempo>=0&&tempo<23){
			candidato[tempo]++;
			gados++;
		}
		else
			printf("ENTRE COM UM VALOR VALIDO.\n");
	}
	for(tempo=0;tempo<TAM-2;tempo++){
		if(tempo==0){
			votosvencedor=candidato[tempo];
			vencedor=0;
		}
		else
			if(candidato[tempo]==votosvencedor){
				empate++;
			}
			else
				if(candidato[tempo]>votosvencedor){
					vencedor=tempo;
					votosvencedor=candidato[tempo];
				}
	}
	if(empate==0)
		printf("%d gados votaram, o proximo ditador sera o cadidato numero %d, que ganhou com %d votos. Agora diremos a quantidade de votos de cada um e, em seguida os votos brancos e nulos.\n",gados,vencedor,votosvencedor);
	else{
		printf("Houve um empate nas eleicoes, os seguintes candidatos empataram, com %d votos:\n",votosvencedor);
		for(tempo=1;tempo<TAM-2;tempo++){
			if(candidato[tempo]==votosvencedor)
				printf("%d\n",tempo);
		}
	}
	for(tempo=1;tempo<TAM;tempo++){
		if(tempo==21)
			printf("Houveram %d votos brancos.\n",candidato[tempo]);
		else
			if(tempo==22)
				printf("Houveram %d votos nulos.\n",candidato[tempo]);
			else
				printf("O candidato %d teve %d votos.\n",tempo,candidato[tempo]);
	}
}

//5.	Um palíndromo é uma sequência de caracteres cuja leitura é idêntica se feita da direita para a esquerda e vice versa. Exemplo: osso e ovo são palíndromos. Nas expressões mais extensas os espaços são ignorados. Ex.: subi no onibus. Faça um programa que leia uma sequência de caracteres terminada pelo caractere ponto final, mostre-a e diga se é palíndroma ou não. Obs.: a sequência não possui mais que 50 caracteres. Só será permitida a utilização de um único vetor.
int inicio, fim,tamanho,tempo,p;
char letra[50],letra_analisada;
main(){
	tamanho=0;
	printf("Diga uma frase e termine com ponto final.\n");
	scanf("%c",&letra_analisada);
	while(letra_analisada!='.'){
		if(letra_analisada!=' '){
			letra[tamanho]=letra_analisada;
			tamanho++;
		}
		scanf("%c",&letra_analisada);
	}
	tempo=1;
	inicio=0;
	fim=tamanho-1;
	while(tempo<=(tamanho/2)){
		printf("%c e %c\n",letra[inicio],letra[fim]);
		if(letra[inicio]!=letra[fim])
			p++;
		inicio++;
		fim--;
		tempo++;
	}
	if(p>0)
		printf("A frase nao e palindroma.");
	else
		printf("A frase e palindroma.");
}