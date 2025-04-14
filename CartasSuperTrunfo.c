#include <stdio.h>
#include <locale.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
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

    // Definição das variáveis para a segunda carta
    char segundaCartaEstado;
    char segundaCartaID[4];
    char segundaCartaCidade[50];
    int segundaCartaPopulacao;
    float segundaCartaArea;
    float segundaCartaPib;
    int segundaCartaPontosTuristicos;

    // Cadastro da primeira carta
    printf("===== Cadastro da primeira carta =====\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &primeiraCartaEstado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", primeiraCartaID);

    printf("Digite o nome da cidade: ");
    scanf("%s", primeiraCartaCidade);

    printf("Digite a população: ");
    scanf("%d", &primeiraCartaPopulacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &primeiraCartaArea);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &primeiraCartaPib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &primeiraCartaPontosTuristicos);


    // Cadastro da segunda carta
    printf("\n===== Cadastro da segunda carta =====\n");
    printf("\nDigite o estado (letra de A a H): ");
    scanf(" %c", &segundaCartaEstado);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", segundaCartaID);

    printf("Digite o nome da cidade: ");
    scanf(" %s]", segundaCartaCidade);

    printf("Digite a população: ");
    scanf("%d", &segundaCartaPopulacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &segundaCartaArea);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &segundaCartaPib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &segundaCartaPontosTuristicos);


    // Exibição das informações da primeira carta
    printf("\n\n===== Carta 1 =====\n");
    printf("Código (ID): %s\n", primeiraCartaID);
    printf("Estado: %c\n", primeiraCartaEstado);
    printf("Nome da Cidade: %s\n", primeiraCartaCidade);
    printf("População: %d\n", primeiraCartaPopulacao);
    printf("Área: %.2f km²\n", primeiraCartaArea);
    printf("PIB: R$ %.2f bilhões\n", primeiraCartaPib);
    printf("Número de Pontos Turísticos: %d\n", primeiraCartaPontosTuristicos);


    // Exibição das informações da segunda carta
    printf("\n===== Carta 2 =====\n");
    printf("Estado: %c\n", segundaCartaEstado);
    printf("Código: %s\n", segundaCartaID);
    printf("Nome da Cidade: %s\n", segundaCartaCidade);
    printf("População: %d\n", segundaCartaPopulacao);
    printf("Área: %.2f km²\n", segundaCartaArea);
    printf("PIB: R$ %.2f bilhões\n", segundaCartaPib);
    printf("Número de Pontos Turísticos: %d\n", segundaCartaPontosTuristicos);

    return 0;
}
