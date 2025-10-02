#include <stdio.h>

int main() {
    // Carta 1
    char Estado1;
    char CodigoCarta1[4];
    char NomeCidade1[50];
    int Populacao1;
    float Area1;
    float PIB1;
    int PontosTuristicos1;

    printf("Carta 1:\n");
    printf("Digite uma letra de A a H: ");
    scanf(" %c", &Estado1);

    printf("Digite a letra do estado seguida de 01 a 04 (ex: G03): ");
    scanf("%3s", CodigoCarta1);

    printf("Digite o nome da cidade (sem espaço): ");
    scanf("%49s", NomeCidade1);

    printf("Digite o número da população: ");
    scanf("%d", &Populacao1);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &Area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &PontosTuristicos1);

    // Carta 2
    char Estado2;
    char CodigoCarta2[4];
    char NomeCidade2[50];
    int Populacao2;
    float Area2;
    float PIB2;
    int PontosTuristicos2;

    printf("\nCarta 2:\n");
    printf("Digite uma letra de A a H: ");
    scanf(" %c", &Estado2);

    printf("Digite a letra do estado seguida de 01 a 04 (ex: B03): ");
    scanf("%s", CodigoCarta2);

    printf("Digite o nome da cidade (sem espaço): ");
    scanf("%s", NomeCidade2);

    printf("Digite o número da população: ");
    scanf("%d", &Populacao2);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &Area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &PontosTuristicos2);

    // Exibir resumo das cartas
    printf("\n--- Resumo das Cartas ---\n");
    printf("Carta 1: %s (Estado %c, Código %s, População %d, Área %.2f km², PIB %.2f, Pontos Turísticos %d)\n",
           NomeCidade1, Estado1, CodigoCarta1, Populacao1, Area1, PIB1, PontosTuristicos1);
    printf("Carta 2: %s (Estado %c, Código %s, População %d, Área %.2f km², PIB %.2f, Pontos Turísticos %d)\n",
           NomeCidade2, Estado2, CodigoCarta2, Populacao2, Area2, PIB2, PontosTuristicos2);

    // Batalha das Cartas
    printf("\n--- Resultado da Batalha ---\n");
    if (PontosTuristicos1 > PontosTuristicos2) {
        printf("Carta 1 (%s) venceu com %d pontos turísticos!\n", NomeCidade1, PontosTuristicos1);
    } else {
        if (PontosTuristicos1 < PontosTuristicos2) {
            printf("Carta 2 (%s) venceu com %d pontos turísticos!\n", NomeCidade2, PontosTuristicos2);
        } else {
            printf("Empate! Ambas as cartas têm %d pontos turísticos!\n", PontosTuristicos1);
        }
    }

    return 0;
}