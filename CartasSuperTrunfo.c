#include <stdio.h>
#include <locale.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

// Protótipos das funções
void cadastrarCarta(const char *carta, char *estado, char id[4], char cidade[50], int *populacao, float *area, float *pib, int *pontosTuristicos);
void mostrarCarta(int cartaNum, char estado, char id[4], char cidade[50], int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita);
void calcularEstatisticas(int populacao, float area, float pib, float *densidadePopulacional, float *pibPerCapita);

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

    // Recebendo os valores
    cadastrarCarta("primeira carta", &primeiraCartaEstado, primeiraCartaID, primeiraCartaCidade, &primeiraCartaPopulacao, &primeiraCartaArea, &primeiraCartaPib, &primeiraCartaPontosTuristicos);
    cadastrarCarta("segunda carta", &segundaCartaEstado, segundaCartaID, segundaCartaCidade, &segundaCartaPopulacao, &segundaCartaArea, &segundaCartaPib, &segundaCartaPontosTuristicos);

    // Calculando as estatísticas de cada carta
    calcularEstatisticas(primeiraCartaPopulacao, primeiraCartaArea, primeiraCartaPib, &primeiraCartaDensidadePopulacional, &primeiraCartaPibPerCapita);
    calcularEstatisticas(segundaCartaPopulacao, segundaCartaArea, segundaCartaPib, &segundaCartaDensidadePopulacional, &segundaCartaPibPerCapita);

    // Mostrando as cartas cadastradas
    mostrarCarta(1, primeiraCartaEstado, primeiraCartaID, primeiraCartaCidade, primeiraCartaPopulacao, primeiraCartaArea, primeiraCartaPib, primeiraCartaPontosTuristicos, primeiraCartaDensidadePopulacional, primeiraCartaPibPerCapita);
    mostrarCarta(2, segundaCartaEstado, segundaCartaID, segundaCartaCidade, segundaCartaPopulacao, segundaCartaArea, segundaCartaPib, segundaCartaPontosTuristicos, segundaCartaDensidadePopulacional, segundaCartaPibPerCapita);

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
void calcularEstatisticas(int populacao, float area, float pib, float *densidadePopulacional, float *pibPerCapita)
{
    // Calculando a densidade populacional
    *densidadePopulacional = (float)populacao / area;

    // Calculando o PIB per capita
    *pibPerCapita = ((float)(pib * 1000000000)) / (float)populacao;
}

// Função para imprimir os dados da carta
void mostrarCarta(int cartaNum, char estado, char id[4], char cidade[50], int populacao, float area, float pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita)
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
}
