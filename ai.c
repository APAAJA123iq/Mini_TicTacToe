#include <stdlib.h>
#include "ai.h"
#include "game.h"

int getEasyMove(char board[3][3]) {
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isMoveValid(board, move));
    return move;
}

int getMediumMove(char board[3][3], char player) {
    // Cek menang dulu
    for (int i = 1; i <= 9; i++) {
        if (isMoveValid(board, i)) {
            makeMove(board, i, player);
            if (checkWinner(board) == player) {
                makeMove(board, i, ' ');
                return i;
            }
            makeMove(board, i, ' ');
        }
    }

    // Acak jika tidak ada langkah menang
    return getEasyMove(board);
}

int getHardMove(char board[3][3], char player) {
    // Tambahkan minimax nanti
    return getMediumMove(board, player); // Placeholder
}