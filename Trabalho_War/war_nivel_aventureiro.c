#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// estrutura (struct)
 struct Territorio {
   char nome[30];
   char cor[10];
   int tropas;
 };
 // funcao de ataque e defesa
 void atacar(struct Territorio *atacante, struct Territorio *defensor){
  printf("\n HORA DO DUELO!\n");
  printf("Atacante : %s (%s) - %d tropas\n", atacante -> nome, atacante -> cor, atacante -> tropas);
  printf("Defensor : %s (%s) - %d tropas\n", defensor -> nome, defensor -> cor, defensor -> tropas);

  // declaracao dos dados
  int dado_ataque = (rand() % 6) + 1;
  int dado_defesa = (rand() % 6) + 1;

  if(dado_ataque > dado_defesa){
    printf("O territorio atacante %s sucumbiu o territorio defensor %s\n", atacante -> nome, defensor -> nome);
    defensor -> tropas--;
    printf("O territorio sucumbido %s perdeu 1 tropa\n", defensor -> nome);
    printf("Resultado do dado: Atacante rolou: %d - Defensor rolou: %d\n", dado_ataque,dado_defesa);

    if(defensor -> tropas == 0){
      printf("O atacante dizimou o territorio defensor\n");
      printf("--- TERRITORIO CONQUISTADO ---");

      int metade = atacante -> tropas/2;
      defensor -> tropas = metade;
      strcpy(defensor->cor, atacante->cor);
    }
  } else {
    printf("O territorio defensor persistiu ao ataque e ganhou\n");
    atacante -> tropas--;
    printf("Atacante foi sucumbido perdendo 1 tropa restante apenas %d\n", atacante -> tropas);
    printf("Resultado do dado: Atacante rolou: %d - Defensor rolou: %d\n", dado_ataque,dado_defesa);
  }
 }

// limpar o buffer de entrada
 void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
 }

// código principal
int main() {
  srand(time(NULL));
  struct Territorio *terra = NULL;
  int totalterreno = 0;
  int opcao;
  int max_territorios = 0;


  printf("Quantos territorios deseja cadastrar? ");
  scanf("%d", &max_territorios);
  limpa();

  // alocando memória dinâmica
  terra = (struct Territorio*) calloc(max_territorios, sizeof(struct Territorio));

  // verificando se alocou
  if (terra == NULL){
    printf("Memoria não alocada\n");
    return 1;
  }
  printf("Memoria alocada!!\n");
// mostrando o menu
 do {
  printf("==================================\n");
  printf("             Jogo War\n");
  printf("==================================\n");
  printf("1 - Cadastrar os Territorios\n");
  printf("2 - Mostrar os Territorios ja cadastrados\n");
  printf("3 - Iniciar Jogo\n");
  printf("0 - Sair\n");
  printf("-------------------------------------------------\n");
  printf("Escolha a opcao desejada: ");

  scanf ("%d", &opcao);
  limpa();

//escolhendo as opções
  switch (opcao){
    case 1:
        //cadastro dos territorios
        printf("--- Cadastro dos Territorios ---\n");

        if (totalterreno < max_territorios) {
            printf("Digite o nome do Terreno: ");
            scanf("%29s", terra[totalterreno].nome);

            printf("Digite a cor do Terreno: ");
            scanf("%9s", terra[totalterreno].cor);

            printf("Digite a quantidade de tropas: ");
            scanf("%d", &terra[totalterreno].tropas);

            limpa();
            totalterreno++;

            printf("\n--- Terreno cadastrado com sucesso ---\n");
            printf("\n Precione Enter para continuar");
            getchar();
        } else {
            printf("\nMaximo de terrenos ja cadastrados\n");
            printf("\n Precione Enter para continuar");
            getchar();
        }
        break;

    case 2:
     //exibindo os territorios
     printf("\n--- Mostrando os Terrenos ---\n");
     if (totalterreno == 0) {
        printf("Nenhum terreno cadastrado\n");
     } else{
        for(int i = 0; i < totalterreno; i++){
            printf("==================================\n");
            printf("Terreno %d\n", i + 1);
            printf("Nome %s\n", terra[i].nome);
            printf("Cor %s\n", terra[i].cor);
            printf("Numero de Tropas %d\n", terra[i].tropas);

        }
        printf("==================================\n");
     }
      printf("\n Precione Enter para continuar");
      getchar();
      break;

    case 3:
      if (totalterreno < 2){
        printf("Numero insuficiente de terrotorios, registre pelo menos 2");
        printf("\n Precione Enter para continuar");
            getchar();
            break;
      } else {
        //mostrando o campo de batalha
        printf("\n---------------------------\n");
        printf(" CAMPO DE BATALHA \n");
        printf("----------------------------\n");
        for(int i = 0; i < totalterreno; i++){
          printf("%d. %s (Exercito %s), Tropas: %d\n",i+1,terra[i].nome,terra[i].cor,terra[i].tropas);
        }
        int ataquer;
        int defende;
        
          printf("\n--- FASE DE ATAQUE ---\n");
          printf("Escolha o territorio atacante (1 a 5, ou 0 para sair: ");
          scanf("%d", &ataquer);
          limpa();
          if(ataquer == 0){
            printf("Saindo da batalha...\n");
            break;
          }
          printf("Escolha o territorio defensor (1 a 5, ou 0 para sair)");
          scanf("%d", &defende);
          if(defende == 0){
            printf("Saindo da batalha...\n");
            break;
          }

          //delay
          printf("\n Precione Enter para continuar");
          getchar();

          // chamando a função ataccar
          atacar(&terra[ataquer-1], &terra[defende-1]);
          printf("\n Precione Enter para continuar\n");
          getchar();
          break;

      }
    case 0:

        //opção de sair
        printf("\nSaindo\n");
        break;

    default:
        //segurança contra qualquer opção não valida
        printf("\nOpcao Invalida! Tente novamente.\n");
        printf("\nPrecione Enter para continuar");
        getchar();
        break;
 }


 } while (opcao != 0);

  // liberando a memória
  free(terra);
  printf("\nMemoria liberada!\n");

 return 0;
}
