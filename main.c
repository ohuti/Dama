#include <stdio.h>
#include <stdlib.h>
#define N 9

//Inicia Tabuleiro definindo espaços vazios e peças.
char **intitialize();

//imprime Matriz
void printM(char **M);

//define regras do jogo, como: evitar usar casas fora do tabuleiro, como a peça pode andar e comer.
void step();

/*
Verifica se o jogo pode ou não continuar
caso as peças acabem ou não possam mais se mover.
*/
//void status();

//Movimentação das peças.
//void movPeca(int a, int b, int c, int d);


/*Função que aplica a lógica do jogo, que alterna a rodada de cada jogador e
que imprime o tabuleiro atualizado a cada rodada.
*/
void game();

int main(void){

	int S;

	printf("Bem vindo a Dama\n");
	printf("Peças podem comer para trás? Se sim digite 1, se não digite 0\n");
	scanf("%d", &S);

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
	M[0][0] = ' ';
	M[1][0] = '1';
	M[2][0] = '2';
	M[3][0] = '3';
	M[4][0] = '4';
	M[5][0] = '5';
	M[6][0] = '6';
	M[7][0] = '7';
	M[8][0] = '8';

	M[0][1] = '1';
	M[0][2] = '2';
	M[0][3] = '3';
	M[0][4] = '4';
	M[0][5] = '5';
	M[0][6] = '6';
	M[0][7] = '7';
	M[0][8] = '8';

	//peças pretas (X)
	for(i=1; i<4; i+=2)
		for(j=1; j<N; j+=2)
			M[i][j] = 'X';
	for(j=2; j<N; j+=2)
		M[2][j] = 'X';

	//peças brancas (O)
	for(i=6; i<N; i+=2)
		for(j=2; j<N; j+=2)
			M[i][j] = 'O';
	for(j=1; j<N; j+=2)
		M[7][j] = 'O';

	//espaços vazios entre as peças pretas
	for(i=1; i<4; i+=2)
		for(j=2; j<N; j+=2)
			M[i][j] = ' ';
	for(j=1; j<N; j+=2)
		M[2][j] = ' ';

	//espaços vazios entre as peças brancas
	for(i=6; i<N; i+=2)
		for(j=1; j<N; j+=2)
			M[i][j] = ' ';
	for(j=2; j<N; j+=2)
		M[7][j] = ' ';

	//demais espaços vazios
	for(i=4; i<6; i++)
		for(j=1; j<N; j++)
			M[i][j] = ' ';


	return M;

}

void printM(char **M){
	
	int i, j;

	for(i=0;i<N;i++){
		for(j=0; j<N; j++){
            printf("[%c]",M[i][j]);
        }

    	printf("\n");

	}

    
}


void step(){

	//escolhe a peça que irá se mover e escolhe a casa para onde a peça vai andar.
	

}

/*void movPeca(int a, int b, int c, int d){
	char **M;

	M[a][b] = M[c][d];
	M[a][b] = ' ';

}*/

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
		M[lin][col] = M[i][j];

		//movPeca(linha, coluna, lin, col);
	
		//alternando jogadores.
		if(jogador == 'O')
            jogador = 'X';
        else
            jogador = 'O';
	
	}
}









