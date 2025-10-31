#include <stdio.h>

/*
===========================================
   FUNÇÕES RECURSIVAS PARA AS PEÇAS
===========================================
*/

// --- Torre (movimento vertical) ---
void moverTorre(int casas) {
    if (casas == 0) return; // Condição de parada
    printf("Cima\n");
    moverTorre(casas - 1); // Chamada recursiva
}

// --- Bispo com recursão e loops aninhados ---
void moverBispoRec(int casas) {
    if (casas == 0) return;

    // Movimento diagonal: cima + direita
    printf("Cima\n");
    printf("Direita\n");

    moverBispoRec(casas - 1);
}

void moverBispo(int casas) {
    printf("\nMovimento do Bispo com loops aninhados:\n");
    for (int vertical = 0; vertical < casas; vertical++) {
        for (int horizontal = 0; horizontal < casas; horizontal++) {
            if (vertical == horizontal) { 
                printf("Cima\n");
                printf("Direita\n");
            }
        }
    }

    printf("\nMovimento do Bispo com recursão:\n");
    moverBispoRec(casas);
}

// --- Rainha (movimento misto: vertical + horizontal) ---
void moverRainha(int casas) {
    if (casas == 0) return;

    // Primeiro sobe
    printf("Cima\n");
    moverRainha(casas - 1);
    
    // Depois vai para direita
    printf("Direita\n");
}

/*
===========================================
   CAVALO COM LOOPS COMPLEXOS
===========================================
   Movimento: 2 para cima e 1 para direita
===========================================
*/

void moverCavalo(int passos) {
    printf("\nMovimento do Cavalo:\n");

    int movVertical = 2;
    int movHorizontal = 1;

    for (int i = 0; i < passos; i++) {
        for (int v = 1; v <= movVertical; v++) {
            if (v > movVertical) break; // condição desnecessária, apenas para usar break
            printf("Cima\n");
        }

        for (int h = 1; h <= movHorizontal; h++) {
            if (h % 2 == 0) continue; // usando continue apenas como requisito
            printf("Direita\n");
        }
    }
}

/*
===========================================
               FUNÇÃO PRINCIPAL
===========================================
*/

int main() {

    // Número de casas definidas no código (não recebe do usuário)
    int casasTorre = 4;
    int casasBispo = 3;
    int casasRainha = 4;
    int movimentosCavalo = 2;

    // Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // Separador
    printf("\n-------------------------\n");

    // Bispo
    moverBispo(casasBispo);

    // Separador
    printf("\n-------------------------\n");

    // Rainha
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // Separador
    printf("\n-------------------------\n");

    // Cavalo
    moverCavalo(movimentosCavalo);

    return 0;
}
