#include <stdio.h>

int main(){
    //Declarando as variaveis
    int bispo = 1;
    int rainha = 0;

    //Titulo
    printf("---Jogo de Xadrez---\n");


    //Código de movimentação das peças

    //Movimentação da Torre
    printf("Torre está na casa A1 e irá mover-se para a casa G1\n");
    for (int torre = 1; torre < 6; torre++) {
        printf("Direita\n");
        if (torre == 5){
            printf("Torre está na casa G1\n");
        }
    }
    //Movimentação do Bispo
    printf("Bispo está na casa C1 e irá mover-se para a casa H6\n");
    while (bispo < 6) {
        printf("Diretia e Esquerda\n");
        if (bispo == 5) {
            printf("Bispo está na casa H6\n");
        }
        bispo++;
    }
    //Movimentação da Rainha
    printf("Rainha está na casa H1 e irá mover-se para a casa A1\n");
    do {
        printf("Esquerda\n");
        rainha++;
        if (rainha == 8){
        printf("Rainha está na casa A1\n");
    }
    } while (rainha < 8);
    return 0;
}