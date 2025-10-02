#include <stdio.h>

int main(){
    int tamanhotabu = 10;
    int tamanhonavio = 3;

    //Declarando a matriz do tabuleiro
    int tabuleiro[10][10];
    
    //Inicando o tabuleiro com água
        for (int linha = 0; linha < tamanhotabu; linha++) {
            for (int coluna = 0; coluna < tamanhotabu; coluna++){
                tabuleiro[linha][coluna] = 0;
            }
        }

    //Posição do navio na horizontal (linha 2, colunas 4, 5, 6)
    int navio1linha = 2;
    int navio1coluna = 4;
    for (int i = 0; i < tamanhonavio; i++) {
        tabuleiro[navio1linha][navio1coluna + i] = 3;
    }

    //Posição do navio na vertival (linha 5, 6, 7, coluna 2)
    int navio2linha = 5;
    int navio2coluna = 2;

    for (int i = 0; i < tamanhonavio; i++){
        tabuleiro[navio2linha + i][navio2coluna] = 3;
    }

    //Exibindo o tabuleiro
    printf("  A B C D E F J H I J\n");
    for (int linha = 0; linha < tamanhotabu; linha++) {
        printf("%d ", linha + 1);
        for (int coluna = 0; coluna < tamanhotabu; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    return 0;

}
