// // game.c
// #include <stdio.h>
// #include "game.h"

// void initBoard(char board[3][3]) {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             board[i][j] = ' ';
//         }
//     }
// }

// void displayBoard(char board[3][3]) {
//     printf("\n");
//     for (int i = 0; i < 3; i++) {
//         printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//         if (i < 2) printf("---|---|---\n");
//     }
//     printf("\n");
// }

// int isMoveValid(char board[3][3], int move) {
//     if (move < 1 || move > 9) return 0;
//     int row = (move - 1) / 3;
//     int col = (move - 1) % 3;
//     return board[row][col] == ' ';
// }

// void makeMove(char board[3][3], int move, char symbol) {
//     int row = (move - 1) / 3;
//     int col = (move - 1) % 3;
//     board[row][col] = symbol;
// }

// char checkWinner(char board[3][3]) {
//     for (int i = 0; i < 3; i++) {
//         if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
//             return board[i][0];
//         if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//             return board[0][i];
//     }
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
//         return board[0][0];
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
//         return board[0][2];

//     int empty = 0;
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (board[i][j] == ' ') empty = 1;
//         }
//     }
// return empty ? ' ' : 'D'; // D for Draw
// }
// ========================= game.c =========================
#include <stdio.h>
#include "game.h"

void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isMoveValid(char board[3][3], int move) {
    if (move < 1 || move > 9) return 0;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] == ' ';
}

void makeMove(char board[3][3], int move, char symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

char checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // Cek seri
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return ' ';  // Belum selesai

    return 'D';  // Draw
}