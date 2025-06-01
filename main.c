// ========================= main.c =========================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "ai.h"

void printTutorial() {
    printf("\n--- Tutorial ---\n");
    printf("1. Kamu bermain sebagai 'X', bot sebagai 'O'\n");
    printf("2. Masukkan angka 1-9 sesuai posisi kotak:\n");
    printf("   1 | 2 | 3\n");
    printf("  ---|---|---\n");
    printf("   4 | 5 | 6\n");
    printf("  ---|---|---\n");
    printf("   7 | 8 | 9\n");
    printf("3. Tujuanmu adalah membuat 3 simbol sejajar\n");
}

void playGame(int level) {
    char board[3][3];
    int move;
    char winner = ' ';

    initBoard(board);

    for (int turn = 0; turn < 9 && winner == ' '; turn++) {
        displayBoard(board);
        if (turn % 2 == 0) {
            // Giliran pemain
            do {
                printf("Masukkan posisi (1-9): ");
                scanf("%d", &move);
            } while (!isMoveValid(board, move));
            makeMove(board, move, 'X');
        } else {
            // Giliran bot
            printf("Bot sedang berpikir...\n");
            if (level == 1)
                move = getEasyMove(board);
            else if (level == 2)
                move = getMediumMove(board, 'O');
            else
                move = getHardMove(board, 'O');
            makeMove(board, move, 'O');
        }
        winner = checkWinner(board);
    }

    displayBoard(board);
    if (winner == 'X') printf("Selamat! Kamu menang!\n");
    else if (winner == 'O') printf("Yah! Bot menang!\n");
    else printf("Permainan seri!\n");
}

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("=== Tic Tac Toe ===\n");
        printf("1. Main - Easy\n");
        printf("2. Main - Medium\n");
        printf("3. Main - Hard\n");
        printf("4. Tutorial\n");
        printf("5. Keluar\n");
        printf("Pilihanmu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: playGame(1); break;
            case 2: playGame(2); break;
            case 3: playGame(3); break;
            case 4: printTutorial(); break;
            case 5: exit(0);
            default: printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include "game.h"
// #include "ai.h"

// void playBotGame(int level) {
//     char board[3][3];
//     initBoard(board);

//     char current = 'X';
//     char winner = ' ';
//     int move;

//     while (winner == ' ') {
//         displayBoard(board);

//         if (current == 'X') {
//             printf("Giliran Kamu (X), masukkan angka 1-9: ");
//             scanf("%d", &move);
//             if (!isMoveValid(board, move)) {
//                 printf("Langkah tidak valid. Coba lagi.\n");
//                 continue;
//             }
//         } else {
//             printf("Bot (O) sedang berpikir...\n");
//             if (level == 1)
//                 move = getEasyMove(board);
//             else if (level == 2)
//                 move = getMediumMove(board, 'O');
//             else
//                 move = getHardMove(board, 'O');
//         }

//         makeMove(board, move, current);
//         winner = checkWinner(board);
//         current = (current == 'X') ? 'O' : 'X';
//     }

//     displayBoard(board);
//     if (winner == 'D')
//         printf("Permainan seri!\n");
//     else
//         printf("Pemenang: %c\n", winner);
// }