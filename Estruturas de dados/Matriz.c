//Estruturas de dados homogêneos - Matriz

//1.	Faça um programa que leia uma matriz 100x100, de números inteiros, e mostre qual é o maior e o menor elemento dessa matriz.
#define X 100
#define Y 100
int matriz[X][Y],tempox,tempoy,maior,menor;

main(){
	for(tempox=0;tempox<X;tempox++)
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Insira o proximo numero.\n");
			scanf("%d",&matriz[tempox][tempoy]);
			if(tempox==0&&tempoy==0)
				maior=matriz[tempox][tempoy];
				menor=matriz[tempox][tempoy];
			if(matriz[tempox][tempoy]>maior)
				maior=matriz[tempox][tempoy];
			if(matriz[tempox][tempoy]<menor)
				menor=matriz[tempox][tempoy];
		}
	printf("%d e o maior numero citado e %d e o menor.",maior,menor);
}

//2.	Faça um programa que preencha os elementos de uma matriz 5x5, de números inteiros, e em seguida calcule a soma de todos os elementos da 3ª linha com os elementos da 5ª linha, o produto dos elementos da 4ª coluna, o somatório dos elementos do diagonal principal e o somatório dos elementos da diagonal secundária.
#define X 5
#define Y 5
int matriz[X][Y],tempox,tempoy,soma,produto,diagp,diags;

main(){
	soma=0;
	produto=1;
	diagp=0;
	diags=0;
	for(tempox=0;tempox<X;tempox++){
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Diga o proximo numero.\n");
			scanf("%d",&matriz[tempox][tempoy]);
			if(tempox==2||tempox==4)
				soma+=matriz[tempox][tempoy];
			if(tempoy==3)
				produto*=matriz[tempox][tempoy];
			if(tempox==tempoy)
				diagp+=matriz[tempox][tempoy];
			if(tempoy==(X-1-tempox))
				diags+=matriz[tempox][tempoy];
		}
	}
	printf("A soma dos numeros da 3 e 5 linhas e %d, o produto dos da 4 e %d, a soma da diagonal principal e %d e da secundaria e %d.",soma,produto,diagp,diags);
}

//3.	Faça um programa que preencha os elementos de uma matriz 50x50 e em seguida calcule a soma dessas duas matrizes em uma outra matriz e mostre o resultado dessa matriz soma na tela.
#define X 2
#define Y 2
int tempox,tempoy,matriz1[X][Y],matriz2[X][Y],soma[X][Y];

main(){
	for(tempox=0;tempox<X;tempox++)
		for(tempoy=0;tempoy<Y;tempoy++){
			soma[tempox][tempoy]=0;
		}
	for(tempox=0;tempox<X;tempox++)
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Insira o proximo numero.\n");
			scanf("%d",&matriz1[tempox][tempoy]);
			soma[tempox][tempoy]+=matriz1[tempox][tempoy];
		}
	for(tempox=0;tempox<X;tempox++)
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Insira o proximo numero.\n");
			scanf("%d",&matriz2[tempox][tempoy]);
			soma[tempox][tempoy]+=matriz2[tempox][tempoy];
		}
	for(tempox=0;tempox<X;tempox++){
		for(tempoy=0;tempoy<Y;tempoy++)
			printf("%d, ",soma[tempox][tempoy]);
		printf("\n");
	}
}

//4.	Na teoria de sistemas, define-se como elemento minimax de uma matriz o menor elemento da linha onde se encontra o maior elemento da matriz. Faça um programa que leia uma matriz 100x100 de números inteiros e encontre seu elemento minimax, mostrando também a sua posição.
#define X 100
#define Y 100
int matriz[X][Y],tempox,tempoy,maior,minimax,linhamaior;

main(){
	for(tempox=0;tempox<X;tempox++)
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Diga o proximo numero.\n");
			scanf("%d",&matriz[tempox][tempoy]);
			if(tempox==0&&tempoy==0)
				maior=matriz[tempox][tempoy];
			if(matriz[tempox][tempoy]>maior){
				maior=matriz[tempox][tempoy];
				minimax=matriz[tempox][tempoy];
				linhamaior=tempox;
			}
		}
	for(tempoy=0;tempoy<Y;tempoy++)
		if(matriz[linhamaior][tempoy]<minimax)
			minimax=matriz[linhamaior][tempoy];
	printf("%d e o minimax.",minimax);
}

//5.	Faça um programa que leia uma matriz 50x50, e imprima o número de linhas e o número de colunas nulas da matriz. Exemplo: matriz 4x4 essa matriz possui 2 linhas nulas e 1 coluna nula.
#define X 50
#define Y 50
int matriz[X][Y],tempox,tempoy,linhas,colunas,zeros;

main(){
	for(tempox=0;tempox<X;tempox++){
		zeros=0;
		for(tempoy=0;tempoy<Y;tempoy++){
			printf("Insira o proximo valor.\n");
			scanf("%d",&matriz[tempox][tempoy]);
			if(matriz[tempox][tempoy]==0)
				zeros++;
			if(zeros==Y)
				linhas++;
		}
	}
	for(tempoy=0;tempoy<Y;tempoy++){
		zeros=0;
		for(tempox=0;tempox<X;tempox++){
			if(matriz[tempox][tempoy]==0)
				zeros++;
			if(zeros==X)
				colunas++;
		}
	}
	printf("%d colunas e %d linhas sao nulas.",colunas,linhas);
}

//6.	Um quadrado mágico, é uma matriz quadrada, cuja soma de cada linha, coluna ou diagonal é a mesma. Faça um programa que leia uma matriz 50x50, e diga se essa matriz é um quadrado mágico. Exemplo de um quadrado mágico 4x4. A soma de qualquer linha, coluna ou diagonal da sempre 34.
#define TAM 50
int matriz[TAM][TAM],slinha[TAM],scoluna[TAM],sdp,sds,tempoy,tempox,falso;

main(){
	for(tempox=0;tempox<TAM;tempox++){
		slinha[tempox]=0;
		scoluna[tempox]=0;
	}
	for(tempoy=0;tempoy<TAM;tempoy++)
		for(tempox=0;tempox<TAM;tempox++){
			printf("Insira o proximo numero.\n");
			scanf("%d",&matriz[tempoy][tempox]);
			slinha[tempox]+=matriz[tempoy][tempox];
			scoluna[tempoy]+=matriz[tempoy][tempox];
			if(tempox==tempoy)
				sdp+=matriz[tempoy][tempox];
			if(tempox==(TAM-1-tempoy))
				sds+=matriz[tempoy][tempox];
		}
	for(tempox=1;tempox<TAM;tempox++){
		if(slinha[tempox]!=slinha[tempox-1])
			falso++;
		if(scoluna[tempox]!=scoluna[tempox-1])
			falso++;
	}
	if(sdp!=sds){
		falso++;
		printf("%d e diferente de %d.",sdp,sds);
	}
	if(falso>0)
		printf("Nao e um quadrado magico.");
	else
		printf("E um quadrado magico.");
}

//7.	Uma imagem colorida RGB (Red Green Blue) é composta por 3 matrizes, uma para o canal Red, uma para o canal Green e outra para o canal Blue, que podem assumir valores de 0 a 255. Uma imagem com tons de cinza pode ser obtida através da média aritmética das matrizes RGB. Faça um programa que leia uma imagem colorida de tamanho 500x700, ou seja as matrizes RGB e calcule a sua respectiva matriz em tons de cinza.
#define X 500
#define Y 700
int red[Y][X],green[Y][X],blue[Y][X],gray[Y][X],tempox,tempoy;

main(){
	for(tempoy=0;tempoy<Y;tempoy++)
		for(tempox=0;tempox<X;tempox++){
			printf("Diga o valor RGB do pixel na posicao[%d][%d].\n",tempoy,tempox);
			scanf("%d%d%d",&red[tempoy][tempox],&green[tempoy][tempox],&blue[tempoy][tempox]);
			while(red[tempoy][tempox]<0||red[tempoy][tempox]>255||green[tempoy][tempox]<0||green[tempoy][tempox]>255||blue[tempoy][tempox]<0||blue[tempoy][tempox]>255){
				printf("Digite valores entre 0 e 255 para posicao[%d][%d]",tempoy,tempox);
				scanf("%d%d%d",&red[tempoy][tempox],&green[tempoy][tempox],&blue[tempoy][tempox]);	
			}
			gray[tempoy][tempox]=red[tempoy][tempox]+green[tempoy][tempox]+blue[tempoy][tempox];
		}
	printf("Sua matriz em tons de cinza é:\n");
	for(tempoy=0;tempoy<Y;tempoy++){
		for(tempox=0;tempox<X;tempox++)
			printf("%d ",gray[tempoy][tempox]/3);
		printf("\n");
	}
}
 
//8.	Faça um programa que leia uma imagem em tons de cinza de tamanho 500x700 e calcule o seu histograma. O histograma calcula a quantidade de cada tom de pixel na imagem (frequência de pixels em uma imagem). Cada pixel pode assumir um valor entre 0 a 255.
#define X 2
#define Y 2
int gray[Y][X],numero[256],tempox,tempoy;

main(){
	for(tempox=0;tempox<X;tempox++)
		numero[tempox]=0;
	for(tempoy=0;tempoy<Y;tempoy++)
		for(tempox=0;tempox<X;tempox++){
			printf("Diga o proximo valor.\n");
			scanf("%d",&gray[tempoy][tempox]);
			while(gray[tempoy][tempox]>255||gray[tempoy][tempox]<0){
				printf("Diga um valor valido.\n");
				scanf("%d",gray[tempoy][tempox]);
			}
			numero[gray[tempoy][tempox]]++;
		}
	for(tempox=0;tempox<255;tempox++)
		if(numero[tempox]>0)
			printf("%d apareceu %d vezes.\n",tempox,numero[tempox]);
}