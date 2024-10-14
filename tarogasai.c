#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 6
#define COLUNAS 6
#define MINAS 3
#define JOGADAS_MAX 5


void imprimirCampo(char campo[LINHAS][COLUNAS]) {
    printf("     A   B   C   D   E   F\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("[ %c ] ", campo[i][j]);
        }
        printf("\n");
    }
}


void inicializarCampo(char campo[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            campo[i][j] = ' ';
        }
    }
}


void colocarMinas(char campo[LINHAS][COLUNAS], int minasPos[MINAS][2]) {
    srand(time(NULL));
    int count = 0;
    while (count < MINAS) {
        int linha = rand() % LINHAS;
        int coluna = rand() % COLUNAS;

        if (campo[linha][coluna] != 'X') { 
            campo[linha][coluna] = 'X';
            minasPos[count][0] = linha;
            minasPos[count][1] = coluna;
            count++;
        }
    }
}


int verificarJogada(int linha, int coluna, char campo[LINHAS][COLUNAS]) {
    return campo[linha][coluna] == 'X';
}


int converterColuna(char coluna) {
    return coluna - 'A';
}

int main() {
    char campo[LINHAS][COLUNAS];
    int minasPos[MINAS][2];
    int jogadas = 0;
    int linha, coluna;
    char colunaLetra;

    
    inicializarCampo(campo);
    colocarMinas(campo, minasPos);

    printf("Bem-vindo ao Campo Minado!\n");

    
    while (jogadas < JOGADAS_MAX) {
        imprimirCampo(campo);

        
        printf("\nEscolha uma posição (ex: A1, B2, etc.): ");
        scanf(" %c%d", &colunaLetra, &linha);

        coluna = converterColuna(colunaLetra);
        linha -= 1; 

        
        if (campo[linha][coluna] != ' ') {
            printf("Essa posição já foi escolhida. Tente outra.\n");
            continue;
        }

        
        if (verificarJogada(linha, coluna, campo)) {
            printf("Você pisou em uma mina! Fim de jogo.\n");
            campo[linha][coluna] = 'X'; 
            imprimirCampo(campo);
            break;
        } else {
            campo[linha][coluna] = 'O'; 
            printf("Ufa! Você escapou.\n");
        }

        jogadas++;

        
        if (jogadas == JOGADAS_MAX) {
            printf("Parabéns! Você venceu o jogo!\n");
            imprimirCampo(campo);
        }
    }

    return 0;
}
