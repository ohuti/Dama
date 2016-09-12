#include <stdio.h>
#include <stdlib.h>
#define N 8

//Inicia Tabuleiro definindo espaços vazios e peças.
char **intitialize();

//imprime Matriz
void printM(char **M);

void movePeca(char **M, int a, int b, int c, int d);

//define regras do jogo, como: evitar usar casas fora do tabuleiro, como a peça pode andar e comer.
void step();

/*
Verifica se o jogo pode ou não continuar
caso as peças acabem ou não possam mais se mover.
*/
//void status();


/*Função que aplica a lógica do jogo, que alterna a rodada de cada jogador e
que imprime o tabuleiro atualizado a cada rodada.
*/
void game();

int main(void){

	int S;

	printf("Bem vindo a Dama\n");
	printf("Peças podem comer para trás? Se sim digite 1, se não digite 0\n");
	scanf("%d", &S);
	printf("Nota: o jogo funciona a base de coordenadas, selecione primeiro o numero, depois a letra\n");

	if(S == 0){
		game();
	}/*else
		game1();*/

	return 0;
}

char **intitialize(){
	char **M;
	int i, j, k, l;

	//definindo tamanho do tabuleiro

	M = (char**)calloc(N, sizeof(char*));
	for(i=0; i<N; i++)
		M[i] = (char*)calloc(N, sizeof(char));

    /*
    posicionando as peças
	X = pretas,
	O = brancas,
	*/

	//lista de coordenadas
	
	//peças pretas (X)
	for(i=0; i<3; i+=2)
		for(j=1; j<N; j+=2)
			M[i][j] = 'X';
	
	for(j=0; j<N; j+=2)
		M[1][j] = 'X';

	//peças brancas (O)
	for(i=5; i<N; i+=2)
		for(j=0; j<N; j+=2)
			M[i][j] = 'O';
	for(j=1; j<N; j+=2)
		M[6][j] = 'O';

	//espaços vazios entre as peças pretas
	for(i=0; i<3; i+=2)
		for(j=0; j<N; j+=2)
			M[i][j] = ' ';
	for(j=1; j<N; j+=2)
		M[1][j] = ' ';

	//espaços vazios entre as peças brancas
	for(i=5; i<N; i+=2)
		for(j=1; j<N; j+=2)
			M[i][j] = ' ';
	for(j=0; j<N; j+=2)
		M[6][j] = ' ';

	//demais espaços vazios
	for(i=3; i<5; i++)
		for(j=0; j<N; j++)
			M[i][j] = ' ';


	return M;

}

void printM(char **M){
	
	int i, j;

	printf("  1  2  3  4  5  6  7  8\n");
	for(i=0;i<N;i++){
		printf("%d",i+1);
		for(j=0; j<N; j++){
            printf("[%c]",M[i][j]);
        }

    	printf("\n");

	}

    
}


void step(){

	//escolhe a peça que irá se mover e escolhe a casa para onde a peça vai andar.
	

}

void movePeca(char **M, int a, int b, int c, int d){


	M[c][d] = M[a][b];
	M[a][b] = ' ';

}

void game(){
	char **M;
	char **tabuleiro;
	char jogador = 'O';
	//escolhe a peça
	int i, j;
	//escolhe a casa
	int lin, col;

	intitialize();
	
	tabuleiro = intitialize();

	int jogoAtivo = -1;

	//loop jogo
	while(jogoAtivo == -1){
		printM(tabuleiro);
		printf("jogador %c digite linha e coluna selecionar peça: ", jogador);
		scanf("%d %d", &i, &j);
		printf("escolha casa para a qual a peça devera se mover: ");
		scanf("%d %d", &lin, &col);
		movePeca(tabuleiro,i-1, j-1, lin-1, col-1);

	
		//alternando jogadores.
		if(jogador == 'O')
            jogador = 'X';
        else
            jogador = 'O';
	
	}
}









