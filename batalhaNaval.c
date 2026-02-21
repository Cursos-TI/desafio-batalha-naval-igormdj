#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    // Definição das coordenadas dos navios
    // Navio horizontal: linha 2, coluna 3
    int navioHorizontal_linha = 2;
    int navioHorizontal_coluna = 3;
    
    // Navio vertical: linha 5, coluna 7
    int navioVertical_linha = 5;
    int navioVertical_coluna = 7;
    
    // Variável para controle de validação
    bool posicaoValida = true;
    
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // Verifica se o navio horizontal cabe no tabuleiro
    if (navioHorizontal_coluna + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO) {
        printf("ERRO: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        posicaoValida = false;
    } else {
        // Verifica se o navio horizontal não colide com outros navios
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navioHorizontal_linha][navioHorizontal_coluna + i] != AGUA) {
                printf("ERRO: Navio horizontal colide com outro navio!\n");
                posicaoValida = false;
                break;
            }
        }
    }
    
    // VALIDAÇÃO DO NAVIO VERTICAL
    // Verifica se o navio vertical cabe no tabuleiro
    if (navioVertical_linha + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO) {
        printf("ERRO: Navio vertical ultrapassa os limites do tabuleiro!\n");
        posicaoValida = false;
    } else {
        // Verifica se o navio vertical não colide com outros navios
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navioVertical_linha + i][navioVertical_coluna] != AGUA) {
                printf("ERRO: Navio vertical colide com outro navio!\n");
                posicaoValida = false;
                break;
            }
        }
    }
    
    // Se todas as validações passarem, posiciona os navios
    if (posicaoValida) {
        // Posiciona navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioHorizontal_linha][navioHorizontal_coluna + i] = NAVIO;
        }
        
        // Posiciona navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioVertical_linha + i][navioVertical_coluna] = NAVIO;
        }
        
        // EXIBIÇÃO DO TABULEIRO
        printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
        printf("    "); // Espaço para alinhamento
        
        // Imprime números das colunas para referência
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", j);
        }
        printf("\n");
        
        // Imprime linha separadora
        printf("    ");
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("---");
        }
        printf("\n");
        
        // Imprime o tabuleiro linha por linha
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            // Imprime número da linha
            printf("%2d |", i);
            
            // Imprime cada coluna da linha atual
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%2d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
        // Legenda
        printf("\nLegenda:\n");
        printf("  %d = Agua\n", AGUA);
        printf("  %d = Navio\n", NAVIO);
        
        // Informações sobre os navios
        printf("\n=== POSIÇÃO DOS NAVIOS ===\n");
        printf("Navio Horizontal: linha %d, colunas %d a %d\n", 
               navioHorizontal_linha, 
               navioHorizontal_coluna, 
               navioHorizontal_coluna + TAMANHO_NAVIO - 1);
        printf("Navio Vertical: coluna %d, linhas %d a %d\n", 
               navioVertical_coluna,
               navioVertical_linha, 
               navioVertical_linha + TAMANHO_NAVIO - 1);
               
    } else {
        printf("\nNao foi possivel posicionar os navios devido a erros de validacao.\n");
    }
    
    return 0;
}