#include <stdio.h>
#include <locale.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

// Protótipos das funções
void cadastrarCarta(const char *carta, char *estado, char id[4], char cidade[50], int *populacao, float *area, float *pib, int *pontosTuristicos);
void mostrarCarta(int cartaNum, char estado, char id[4], char cidade[50], int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder);
void calcularEstatisticas(int populacao, float area, float pib, float *densidadePopulacional, float *pibPerCapita, float *superPoder);
void batalhaDeCartas(int populacao1, float area1, float pib1, int pontosTuristicos1, float densidadePopulacional1, float pibPerCapita1, float superPoder1, int populacao2, float area2, float pib2, int pontosTuristicos2, float densidadePopulacional2, float pibPerCapita2, float superPoder2);

int main()
{
    // Definir locale PT-br
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição das variáveis para a primeira carta
    char primeiraCartaEstado;
    char primeiraCartaID[4];
    char primeiraCartaCidade[50];
    int primeiraCartaPopulacao;
    float primeiraCartaArea;
    float primeiraCartaPib;
    int primeiraCartaPontosTuristicos;
    float primeiraCartaDensidadePopulacional;
    float primeiraCartaPibPerCapita;
    float primeiraCartaSuperPoder;

    // Definição das variáveis para a segunda carta
    char segundaCartaEstado;
    char segundaCartaID[4];
    char segundaCartaCidade[50];
    int segundaCartaPopulacao;
    float segundaCartaArea;
    float segundaCartaPib;
    int segundaCartaPontosTuristicos;
    float segundaCartaDensidadePopulacional;
    float segundaCartaPibPerCapita;
    float segundaCartaSuperPoder;

    // Recebendo os valores
    cadastrarCarta("primeira carta", &primeiraCartaEstado, primeiraCartaID, primeiraCartaCidade, &primeiraCartaPopulacao, &primeiraCartaArea, &primeiraCartaPib, &primeiraCartaPontosTuristicos);
    cadastrarCarta("segunda carta", &segundaCartaEstado, segundaCartaID, segundaCartaCidade, &segundaCartaPopulacao, &segundaCartaArea, &segundaCartaPib, &segundaCartaPontosTuristicos);

    // Calculando as estatísticas de cada carta
    calcularEstatisticas(primeiraCartaPopulacao, primeiraCartaArea, primeiraCartaPib, &primeiraCartaDensidadePopulacional, &primeiraCartaPibPerCapita, &primeiraCartaSuperPoder);
    calcularEstatisticas(segundaCartaPopulacao, segundaCartaArea, segundaCartaPib, &segundaCartaDensidadePopulacional, &segundaCartaPibPerCapita, &segundaCartaSuperPoder);

    // Mostrando as cartas cadastradas
    mostrarCarta(1, primeiraCartaEstado, primeiraCartaID, primeiraCartaCidade, primeiraCartaPopulacao, primeiraCartaArea, primeiraCartaPib, primeiraCartaPontosTuristicos, primeiraCartaDensidadePopulacional, primeiraCartaPibPerCapita, primeiraCartaSuperPoder);
    mostrarCarta(2, segundaCartaEstado, segundaCartaID, segundaCartaCidade, segundaCartaPopulacao, segundaCartaArea, segundaCartaPib, segundaCartaPontosTuristicos, segundaCartaDensidadePopulacional, segundaCartaPibPerCapita, segundaCartaSuperPoder);

    // Comparando as cartas
    batalhaDeCartas(primeiraCartaPopulacao, primeiraCartaArea, primeiraCartaPib, primeiraCartaPontosTuristicos, primeiraCartaDensidadePopulacional, primeiraCartaPibPerCapita, primeiraCartaSuperPoder, segundaCartaPopulacao, segundaCartaArea, segundaCartaPib, segundaCartaPontosTuristicos, segundaCartaDensidadePopulacional, segundaCartaPibPerCapita, segundaCartaSuperPoder);

    return 0;
}

// Função para ler os dados da carta
void cadastrarCarta(const char *carta, char *estado, char id[4], char cidade[50], int *populacao, float *area, float *pib, int *pontosTuristicos)
{
    printf("===== Cadastro da %s =====\n", carta);

    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", id);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade);

    printf("Digite a população: ");
    scanf("%d", populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", pontosTuristicos);
}

// Função para calcular as estatísticas da carta
void calcularEstatisticas(int populacao, float area, float pib, float *densidadePopulacional, float *pibPerCapita, float *superPoder)
{
    // Calculando a densidade populacional
    *densidadePopulacional = (float)populacao / area;

    // Calculando o PIB per capita
    *pibPerCapita = ((float)(pib * 1000000000)) / (float)populacao;

    // Calculando o Super Poder
    float inversoDensidade = 1.0 / (float)*densidadePopulacional;

    *superPoder = (float)populacao +
                  (float)area +
                  (float)pib * 1000000000.0 +
                  (float)*pibPerCapita +
                  inversoDensidade;
}

// Função para imprimir os dados da carta
void mostrarCarta(int cartaNum, char estado, char id[4], char cidade[50], int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder)
{
    printf("\n\n===== Carta %d =====\n", cartaNum);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", id);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);
}

// Função para batalhar as duas cartas, atributo por atributo
void batalhaDeCartas(int populacao1, float area1, float pib1, int pontosTuristicos1, float densidadePopulacional1, float pibPerCapita1, float superPoder1, int populacao2, float area2, float pib2, int pontosTuristicos2, float densidadePopulacional2, float pibPerCapita2, float superPoder2)
{
    printf("\n\n===== Batalha X cartas =====\n");

    // Comparação de população (maior vence)
    printf("População: Carta %d venceu (%d)\n",
           (populacao1 > populacao2) ? 1 : 2,
           (populacao1 > populacao2) ? 1 : 0);

    // Comparação de área (maior vence)
    printf("Área: Carta %d venceu (%d)\n",
           (area1 > area2) ? 1 : 2,
           (area1 > area2) ? 1 : 0);

    // Comparação de PIB (maior vence)
    printf("PIB: Carta %d venceu (%d)\n",
           (pib1 > pib2) ? 1 : 2,
           (pib1 > pib2) ? 1 : 0);

    // Comparação de pontos turísticos (maior vence)
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           (pontosTuristicos1 > pontosTuristicos2) ? 1 : 2,
           (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0);

    // Comparação de densidade populacional (menor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (densidadePopulacional1 < densidadePopulacional2) ? 1 : 2,
           (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0);

    // Comparação de PIB per capita (maior vence)
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (pibPerCapita1 > pibPerCapita2) ? 1 : 2,
           (pibPerCapita1 > pibPerCapita2) ? 1 : 0);

    // Comparação de Super Poder (maior vence)
    printf("Super Poder: Carta %d venceu (%d)\n",
           (superPoder1 > superPoder2) ? 1 : 2,
           (superPoder1 > superPoder2) ? 1 : 0);
}
