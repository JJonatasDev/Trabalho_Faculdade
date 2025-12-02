#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct que recebe o nome Sala
typedef struct Sala{
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
}Sala;

//função para criar uma sala
Sala* criarsala(char *nomeSala){
    
    Sala *novaSala = (Sala *)malloc(sizeof(Sala));

    if(novaSala == NULL){
        printf("Não foi possivel criar uma sala, faltou material!!!");
        exit(1);
    }
    strcpy(novaSala->nome, nomeSala);

    novaSala->direita = NULL;
    novaSala->esquerda = NULL;


    return novaSala;
}

//função responsável pela navegação pela árvore (Salas)
void explorarSalas(Sala *salaAtual){
    char escolha;


     while(salaAtual != NULL){
            printf("=====================================\n");
            printf("Sua sala atual: %s\n",salaAtual->nome);
            printf("=====================================\n");

            if(salaAtual->direita == NULL && salaAtual->esquerda == NULL){
                printf("Sala atual nao tem mais comodos adjacentes\n");
                printf("Fim da exploracao\n");
                break;
            }
            
            printf("Salas disponiveis: \n");
            if(salaAtual->esquerda != NULL){
                printf("Esquerda: %s\n",salaAtual->esquerda->nome);
                printf("Digite [e] para esquerda\n");

            }
            if(salaAtual->direita != NULL){
                printf("\nDireita: %s\n",salaAtual->direita->nome);
                printf("Digite [d] para direita\n");
            }
            printf("\nDigite [s] para sair\n");

            printf("\nEscolha um caminho possivel: \n");
            scanf("%c",&escolha);

            if(escolha == 'e' || escolha == 'E'){
                if(salaAtual->esquerda != NULL){
                    salaAtual = salaAtual->esquerda;
                }else{
                    printf("\nNao ha mais sala a esquerda!\n");
                }
            } else if(escolha == 'd' || escolha == 'D'){
                if(salaAtual->direita != NULL){
                    salaAtual = salaAtual->direita;
                }else{
                    printf("\nNao ha mais sala a direita!\n");
                }
            } else if(escolha == 's' || escolha == 'S'){
                printf("\nSaindo do jogo\n");
                break;
            }
        }
    }

//corpor principal do programa
int main(){
    printf("=====================================\n");
    printf("    BEM-VINDO AO JOGO\n");
    printf("    DETECTIVE QUEST\n");
    printf("=====================================\n");

    Sala *hall = criarsala("Hall de Entrada");
    Sala *salaEstar = criarsala("Sala de Estar");
    Sala *biblioteca = criarsala("Biblioteca");
    Sala *cozinha = criarsala("Cozinha");
    Sala *jardim = criarsala("Jardim");
    Sala *quarto = criarsala("Quarto");
    Sala *sotao = criarsala("Sotao");


    hall->esquerda = salaEstar;
    hall->direita = biblioteca;

    salaEstar->esquerda = cozinha;
    salaEstar->direita = jardim;

    biblioteca->esquerda = quarto;
    biblioteca->direita = sotao;

    explorarSalas(hall);

    free(hall);
    free(salaEstar);
    free(biblioteca);
    free(cozinha);
    free(jardim);
    free(quarto);
    free(sotao);


    printf("\nJogo encerrado!\n");

    return 0;
}
