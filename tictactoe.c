#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "ai.h"

void playBotGame(int level) {
    char board[3][3];
    initBoard(board);

    char current = 'X';
    char winner = ' ';
    int move;

    while (winner == ' ') {
        displayBoard(board);

        if (current == 'X') {
            printf("Giliran Kamu (X), masukkan angka 1-9: ");
            scanf("%d", &move);
            if (!isMoveValid(board, move)) {
                printf("Langkah tidak valid. Coba lagi.\n");
                continue;
            }
        } else {
            printf("Bot (O) sedang berpikir...\n");
            if (level == 1)
                move = getEasyMove(board);
            else if (level == 2)
                move = getMediumMove(board, 'O');
            else
                move = getHardMove(board, 'O');
        }

        makeMove(board, move, current);
        winner = checkWinner(board);
        current = (current == 'X') ? 'O' : 'X';
    }

    displayBoard(board);
    if (winner == 'D')
        printf("Permainan seri!\n");
    else
        printf("Pemenang: %c\n", winner);
}