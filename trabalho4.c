#include <stdio.h>
#include <stdlib.h>

#define BOARD_ROWS 10
#define BOARD_COLS 10
#define SKILL_SIZE 5   // tamanho fixo das matrizes de habilidade (5x5)
#define WATER 0
#define SHIP 3
#define AFFECTED 5

/* 
 Programa: Visualização de áreas de efeito (Cone, Cruz, Octaedro)
 - As matrizes de habilidade (5x5) são construídas dinamicamente usando loops aninhados
   e condicionais.
 - As habilidades são sobrepostas ao tabuleiro. A checagem de limites previne
   escrita fora do tabuleiro.
 - Exibe o tabuleiro final no console com printf.
*/

/* Funções para construir as matrizes de habilidade (valores 0/1) */

/* Cone apontando para baixo:
   Topo da matriz (linha 0) é o ponto de origem; o cone se expande para baixo.
   Regra usada: na linha r (0..SKILL_SIZE-1), os colunas com |c-mid| <= r recebem 1.
*/
void build_cone(int cone[SKILL_SIZE][SKILL_SIZE]) {
    int mid = SKILL_SIZE / 2;
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) {
            // Condicional que cria a forma de "cone/triângulo" apontando para baixo
            if (abs(c - mid) <= r) {
                cone[r][c] = 1;
            } else {
                cone[r][c] = 0;
            }
        }
    }
}

/* Cruz (plus): ponto de origem no centro da matriz.
   Regra: linha do meio inteira = 1 ; coluna do meio inteira = 1.
*/
void build_cross(int cross[SKILL_SIZE][SKILL_SIZE]) {
    int mid = SKILL_SIZE / 2;
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) {
            if (r == mid || c == mid) {
                cross[r][c] = 1;
            } else {
                cross[r][c] = 0;
            }
        }
    }
}

/* Octaedro (vista frontal — losango): ponto de origem no centro.
   Regra (diamond): |r-mid| + |c-mid| <= mid -> 1
*/
void build_octahedron(int octa[SKILL_SIZE][SKILL_SIZE]) {
    int mid = SKILL_SIZE / 2;
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) {
            if (abs(r - mid) + abs(c - mid) <= mid) {
                octa[r][c] = 1;
            } else {
                octa[r][c] = 0;
            }
        }
    }
}

/* Sobrepõe uma matriz de habilidade (valores 0/1) ao tabuleiro.
   Parametros:
    - board: matriz BOARD_ROWS x BOARD_COLS (modificada in-place)
    - skill: matriz SKILL_SIZE x SKILL_SIZE contendo 0/1
    - origin_row, origin_col: coordenada no tabuleiro que serve como ponto de origem
    - origin_is_top: se 1 => a origem corresponde à linha 0 da skill (usado no Cone).
                     se 0 => a origem corresponde ao centro da skill (usado em Cruz/Octaedro).
*/
void overlay_skill(int board[BOARD_ROWS][BOARD_COLS],
                   int skill[SKILL_SIZE][SKILL_SIZE],
                   int origin_row, int origin_col,
                   int origin_is_top)
{
    int mid = SKILL_SIZE / 2;

    for (int sr = 0; sr < SKILL_SIZE; ++sr) {
        for (int sc = 0; sc < SKILL_SIZE; ++sc) {
            if (skill[sr][sc] == 0) continue; // Não afeta se o valor da skill for 0

            int tr, tc; // target row/col no tabuleiro

            if (origin_is_top) {
                // A linha 0 da matriz skill corresponde à origem no tabuleiro.
                // Ajuste horizontal para o centro da skill: target_col = origin_col + (sc - mid)
                tr = origin_row + sr;
                tc = origin_col + (sc - mid);
            } else {
                // A origem no tabuleiro corresponde ao centro da matriz skill.
                tr = origin_row + (sr - mid);
                tc = origin_col + (sc - mid);
            }

            // Condicional para garantir limites do tabuleiro (não escrever fora)
            if (tr >= 0 && tr < BOARD_ROWS && tc >= 0 && tc < BOARD_COLS) {
                // Marca como AFFECTED (5). Conforme especificação, usamos um valor
                // diferente de 0 e 3 para indicar área afetada.
                board[tr][tc] = AFFECTED;
            }
        }
    }
}

/* Exibe o tabuleiro (valores numéricos):
   0 = água, 3 = navio, 5 = área afetada
*/
void print_board(int board[BOARD_ROWS][BOARD_COLS]) {
    printf("Tabuleiro (0=agua, 3=navio, 5=area afetada):\n\n");
    for (int r = 0; r < BOARD_ROWS; ++r) {
        for (int c = 0; c < BOARD_COLS; ++c) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    // Inicializa tabuleiro com água (0)
    int board[BOARD_ROWS][BOARD_COLS];
    for (int r = 0; r < BOARD_ROWS; ++r)
        for (int c = 0; c < BOARD_COLS; ++c)
            board[r][c] = WATER;

    // Coloca alguns navios (valor 3) -- exemplo estático conforme as simplificações
    // (As posições são ilustrativas)
    board[2][2] = SHIP;
    board[2][3] = SHIP;
    board[2][4] = SHIP;
    board[7][1] = SHIP;
    board[7][2] = SHIP;
    board[7][3] = SHIP;
    board[0][9] = SHIP;

    // Matrizes de habilidade (5x5)
    int cone[SKILL_SIZE][SKILL_SIZE];
    int cross[SKILL_SIZE][SKILL_SIZE];
    int octa[SKILL_SIZE][SKILL_SIZE];

    // Construir dinamicamente as matrizes usando funções (que usam loops e condicionais)
    build_cone(cone);
    build_cross(cross);
    build_octahedron(octa);

    // Definir pontos de origem NO TABULEIRO para cada habilidade (fixos no código)
    // Notas:
    // - Para o Cone, a origem corresponde ao topo do cone (linha 0 da matriz). 
    //   Ao chamar overlay_skill passamos origin_is_top = 1.
    // - Para a Cruz e o Octaedro, a origem corresponde ao centro da matriz (origin_is_top = 0).
    //
    // Coordenadas escolhidas (0-based):
    int cone_origin_row = 1, cone_origin_col = 4;   // o topo do cone ficará em (1,4)
    int cross_origin_row = 5, cross_origin_col = 7; // centro da cruz em (5,7)
    int octa_origin_row  = 4, octa_origin_col  = 4; // centro do octaedro em (4,4)

    // Sobrepõe todas as habilidades **de uma vez** (a pedido)
    overlay_skill(board, cone, cone_origin_row, cone_origin_col, 1); // cone origin é topo
    overlay_skill(board, cross, cross_origin_row, cross_origin_col, 0); // cruz origin é centro
    overlay_skill(board, octa,  octa_origin_row,  octa_origin_col,  0); // octaedro origin é centro

    // Exibe o tabuleiro final
    print_board(board);

    // (Opcional) Exibir também as matrizes de habilidade geradas (para debug/visualização)
    printf("\nMatriz - Cone (1=afetado):\n");
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) printf("%d ", cone[r][c]);
        printf("\n");
    }

    printf("\nMatriz - Cruz (1=afetado):\n");
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) printf("%d ", cross[r][c]);
        printf("\n");
    }

    printf("\nMatriz - Octaedro (1=afetado):\n");
    for (int r = 0; r < SKILL_SIZE; ++r) {
        for (int c = 0; c < SKILL_SIZE; ++c) printf("%d ", octa[r][c]);
        printf("\n");
    }

    return 0;
}
