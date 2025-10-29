#include <stdio.h>
#include <string.h>

// Estrutura das cartas
struct Carta {
    char nome[50];
    float populacao;
    float area;
    float pib;
    float densidade;
};

// Função para exibir menu e escolher atributo
int escolherAtributo(int atributoIndisponivel) {
    int opcao;
    do {
        printf("\nEscolha um atributo para comparar:\n");
        if (atributoIndisponivel != 1) printf("1 - População\n");
        if (atributoIndisponivel != 2) printf("2 - Área\n");
        if (atributoIndisponivel != 3) printf("3 - PIB\n");
        if (atributoIndisponivel != 4) printf("4 - Densidade Demográfica\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        // Validação de entrada
        if (opcao < 1 || opcao > 4 || opcao == atributoIndisponivel) {
            printf("Opção inválida! Escolha novamente.\n");
            opcao = 0;
        }
    } while (opcao == 0);
    return opcao;
}

// Função para comparar um único atributo
int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    float v1, v2;

    switch (atributo) {
        case 1: v1 = c1.populacao; v2 = c2.populacao; break;
        case 2: v1 = c1.area; v2 = c2.area; break;
        case 3: v1 = c1.pib; v2 = c2.pib; break;
        case 4: v1 = c1.densidade; v2 = c2.densidade; break;
        default: return 0;
    }

    // Densidade é o único que vence com o menor valor
    if (atributo == 4)
        return (v1 < v2) ? 1 : (v1 > v2 ? 2 : 0);
    else
        return (v1 > v2) ? 1 : (v1 < v2 ? 2 : 0);
}

int main() {
    struct Carta carta1 = {"Brasil", 213.0, 8516.0, 22000.0, 25.0};
    struct Carta carta2 = {"Japão", 125.0, 377.0, 50500.0, 347.0};

    int atributo1, atributo2;
    float soma1 = 0, soma2 = 0;
    int resultado1, resultado2;

    printf("=== SUPER TRUNFO: DESAFIO FINAL ===\n");
    printf("\nCarta 1: %s", carta1.nome);
    printf("\nCarta 2: %s\n", carta2.nome);

    // Escolha do primeiro atributo
    atributo1 = escolherAtributo(0);

    // Escolha do segundo atributo (sem repetir o primeiro)
    atributo2 = escolherAtributo(atributo1);

    // Comparação dos dois atributos
    resultado1 = compararAtributo(carta1, carta2, atributo1);
    resultado2 = compararAtributo(carta1, carta2, atributo2);

    // Somando os valores dos atributos (sempre soma, mesmo que densidade seja invertida)
    switch (atributo1) {
        case 1: soma1 += carta1.populacao; soma2 += carta2.populacao; break;
        case 2: soma1 += carta1.area; soma2 += carta2.area; break;
        case 3: soma1 += carta1.pib; soma2 += carta2.pib; break;
        case 4: soma1 += carta1.densidade; soma2 += carta2.densidade; break;
    }
    switch (atributo2) {
        case 1: soma1 += carta1.populacao; soma2 += carta2.populacao; break;
        case 2: soma1 += carta1.area; soma2 += carta2.area; break;
        case 3: soma1 += carta1.pib; soma2 += carta2.pib; break;
        case 4: soma1 += carta1.densidade; soma2 += carta2.densidade; break;
    }

    // Exibição clara dos resultados
    printf("\n\n=== RESULTADO ===\n");
    printf("%s x %s\n", carta1.nome, carta2.nome);

    printf("\nAtributos escolhidos:\n");

    // Mostrar os dois atributos escolhidos e seus valores
    for (int i = 1; i <= 2; i++) {
        int a = (i == 1) ? atributo1 : atributo2;
        printf("- ");
        switch (a) {
            case 1:
                printf("População: %.2f vs %.2f\n", carta1.populacao, carta2.populacao);
                break;
            case 2:
                printf("Área: %.2f vs %.2f\n", carta1.area, carta2.area);
                break;
            case 3:
                printf("PIB: %.2f vs %.2f\n", carta1.pib, carta2.pib);
                break;
            case 4:
                printf("Densidade Demográfica: %.2f vs %.2f\n", carta1.densidade, carta2.densidade);
                break;
        }
    }

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    // Resultado final com ternário
    printf("\nResultado Final: ");
    printf("%s\n", (soma1 > soma2) ? carta1.nome :
                   (soma1 < soma2) ? carta2.nome : "Empate!");

    return 0;
}
