#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[3];
    int codigo;
    long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("\n--- Cadastro de Cidade ---\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);
    
    printf("Estado (sigla, ex: SP): ");
    scanf(" %2s", cidade->estado);

    printf("Código da carta: ");
    scanf("%d", &cidade->codigo);

    printf("População: ");
    scanf("%ld", &cidade->populacao);

    printf("Área (km²): ");
    scanf("%f", &cidade->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &cidade->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

void exibirCidade(Cidade cidade) {
    printf("\n--- Informações da Cidade ---\n");
    printf("Nome: %s (%s)\n", cidade.nome, cidade.estado);
    printf("Código da carta: %d\n", cidade.codigo);
    printf("População: %ld\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos turísticos: %d\n", cidade.pontos_turisticos);
}

void compararCartas(Cidade c1, Cidade c2, int criterio) {
    printf("\n--- Comparação de Cartas ---\n");

    int vencedora = 0; // 1 para c1, 2 para c2, 0 para empate

    switch (criterio) {
        case 1: // População
            if (c1.populacao > c2.populacao) vencedora = 1;
            else if (c1.populacao < c2.populacao) vencedora = 2;
            break;
        case 2: // Área
            if (c1.area > c2.area) vencedora = 1;
            else if (c1.area < c2.area) vencedora = 2;
            break;
        case 3: // PIB
            if (c1.pib > c2.pib) vencedora = 1;
            else if (c1.pib < c2.pib) vencedora = 2;
            break;
        case 4: // Pontos turísticos
            if (c1.pontos_turisticos > c2.pontos_turisticos) vencedora = 1;
            else if (c1.pontos_turisticos < c2.pontos_turisticos) vencedora = 2;
            break;
        default:
            printf("Critério inválido!\n");
            return;
    }

    // Exibir resultado
    if (vencedora == 1) {
        printf("A cidade vencedora é: %s!\n", c1.nome);
    } else if (vencedora == 2) {
        printf("A cidade vencedora é: %s!\n", c2.nome);
    } else {
        printf("Empate entre as cidades!\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int criterio;

    // Cadastro das cidades
    cadastrarCidade(&cidade1);
    cadastrarCidade(&cidade2);

    // Exibir cidades cadastradas
    exibirCidade(cidade1);
    exibirCidade(cidade2);

    // Escolha do critério de comparação
    printf("\nEscolha o critério de comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
    printf("Digite o número correspondente: ");
    scanf("%d", &criterio);

    // Comparação das cartas
    compararCartas(cidade1, cidade2, criterio);

    return 0;
}
