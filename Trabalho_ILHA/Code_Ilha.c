#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct para criação de cada item
typedef struct{
    char nome[30];  // nome do item ["AK","GELO"]
    char tipo[10];  // tipo do item ["CURA","MUNICAO","ARMA"]
    int quantidade; // quantidade do item ["1","10"]
} Item;

// Constante que define a quantidade maxima de itens na mochila
#define max_itens 10

// Quantidade atual dos itens na mochila
int ItensAtuais = 0;

// Vetor para armazenar os itens na mochila
Item mochila[max_itens];

// Funcao de pausa
void enter(){
    printf("Precione Enter para continuar\n");
    getchar();
}

// Funcao para listar os itens da mochila
void listaitem(){
    if(ItensAtuais == 0){
        printf("VOCE AINDA NAO PEGOU NENHUM LOOT\n");
        enter();
        return;
    }

     printf("--------------------------------------------------\n");
     printf("%-20s %-15s %s\n","NOME","TIPO","QUANTIDADE");

     for(int i = 0; i < ItensAtuais;i++){
        printf("%-20s %-15s %d\n",mochila[i].nome,mochila[i].tipo,mochila[i].quantidade);

 }
     printf("--------------------------------------------------\n");
     printf("   ITENS NO INVENTARIO %d/%d\n",ItensAtuais,max_itens);
     printf("--------------------------------------------------\n");
     enter();
}
// Funcao para exibir o menu do jogo
void exibimenu(){
    printf("----------------------------------------\n");
    printf("                BERMUDA\n");
    printf("----------------------------------------\n");
    printf("1 - PEGAR UM LOOT DO CHAO\n");
    printf("2 - DROPAR UM LOOT NO CHAO\n");
    printf("3 - ABRIR A MOCHILA\n");
    printf("4 - BUSCAR UM LOOT\n");
    printf("5 - SAIR DO JOGO\n");
    printf("----------------------------------------\n");
    printf("   ITENS NO INVENTARIO %d/%d\n",ItensAtuais,max_itens);
    printf("----------------------------------------\n");
}

// Funcao para remover o buffer do teclado
void limpabuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para alocar um item na mochila
void adicionaitem(){
    if(ItensAtuais >= max_itens){
        printf("MOCHILA CHEIA, ACHE UMA DE LVL 3");
        enter();
        return;
    }
    
    Item novoLoot;

    printf("================================\n");
    printf("    VOCE ACABA DE PEGAR UM LOOT\n");
    printf("================================\n");

    printf("DIGITE O NOME DO LOOT: ");
    fgets(novoLoot.nome, sizeof(novoLoot.nome) ,stdin);
    novoLoot.nome[strcspn(novoLoot.nome , "\n")] = '\0';

    printf("DIGITE O TIPO DO LOOT: ");
    fgets(novoLoot.tipo, sizeof(novoLoot.tipo), stdin);
    novoLoot.tipo[strcspn(novoLoot.tipo, "\n")] = '\0';

    printf("DIGITE A QUANTIDADE DO LOOT: ");
    scanf("%d", &novoLoot.quantidade);
    limpabuffer();

    if(novoLoot.quantidade <= 0){
        printf("QUANTIDADE INVALIDA");
        enter();
        return;
    }
    mochila[ItensAtuais] = novoLoot;
    ItensAtuais++;
    
    printf("ITEM '%s' PEGO COM SUCESSO!\n", novoLoot.nome);
    enter();
    listaitem();
}

// Funcao para remover um item da mochila
void removeitem(){
    if(ItensAtuais == 0){
        printf("VOCE NAO PASSUI LOOT NO MOMENTO, VAI PROCURAR EM OUTRO LUGAR\n");
        enter();
        return;
    }

    char nomeremove[30];
    int i,looten = 0,slot = -1;
    printf("==============================================\n");
    printf("            DROPAR UM LOOT\n");
    printf("==============================================\n");
    printf("DIGITE O NOME DO LOOT QUE VC DESEJA DROPAR: \n");
    fgets(nomeremove, sizeof(nomeremove), stdin);
    nomeremove[strcspn(nomeremove, "\n")] = '\0';

    for(i = 0; i < ItensAtuais;i++){
        if(strcmp(mochila[i].nome, nomeremove) == 0){
            looten = 1;
            slot = i;
            break;
        }
    }
    if(looten){
        for(i = slot; i < ItensAtuais - 1;i++){
            mochila[i] = mochila[i + 1];
        }
        ItensAtuais--;
        printf("O LOOT %s FOI DROPADO\n",nomeremove);
        enter();
    } else{
        printf("VOCE NAO PEGOU O LOOT '%s', LOGO NAO HA O QUE DROPAR\n",nomeremove);
        enter();
    }   
}

// Funcao para buscar um item de acordo com o seu nome

void buscaritem(){
    if(ItensAtuais == 0){
        printf("VOCE NAO PASSUI LOOT NO MOMENTO, VAI PROCURAR EM OUTRO LUGAR\n");
        enter();
        return;
    }
    int loot = 0;
    char nomebusca[30];
    printf("==============================================\n");
    printf("            BUSCAR UM LOOT\n");
    printf("==============================================\n");
    printf("DIGITE O NOME DO LOOT QUE VC DESEJA BUSCAR: \n");
    fgets(nomebusca, sizeof(nomebusca), stdin);
    nomebusca[strcspn(nomebusca, "\n")] = '\0';

    for(int i = 0; i < ItensAtuais;i++){
        if(strcmp(mochila[i].nome,nomebusca) == 0){
            printf("O LOOT %s FOI ENCONTRADO\n",mochila[i].nome);
            printf("TIPO DO LOOT: %s\n",mochila[i].tipo);
            printf("QUANTIDADE DO LOOT: %d\n",mochila[i].quantidade);
            printf("Posicao:    %d\n", i + 1);
            loot = 1;
            enter();
            return;
        }
    }
    if(loot != 1){
        printf("O LOOT %s NAO EXISTE",nomebusca);
        enter();
        return;
    }
}

// Corpo principal do jogo
int main(){
    int opcao;
    do{
        exibimenu();
        printf("Escolha uma das opcoes jogador: ");
        scanf("%d",&opcao);
        limpabuffer();

        printf("\n");
        switch (opcao)  {
         case 1:
           adicionaitem();
            break;
         case 2:
            removeitem();
            break;
         case 3:
           listaitem();
            break;
         case 4:
            buscaritem();
            break;
         case 5:
            printf("SAINDO DO JOGO! OBRIGADO POR JOGAR!!!!");
            break;
         default:
            printf("DIGITE UMA OPCAO VALIDA!\n");
            enter();
        }
    }while(opcao != 5);
 return 0;
}
