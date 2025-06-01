// ========================= ai.c =========================
#include <stdlib.h>
// Meng-include library standar C yang menyediakan fungsi-fungsi umum, salah satunya rand() yang digunakan untuk menghasilkan angka acak.
#include "ai.h"
// Meng-include file header ai.h yang kemungkinan berisi deklarasi fungsi-fungsi AI (kecerdasan buatan) seperti getEasyMove, getMediumMove, dan getHardMove.
#include "game.h"
//Meng-include file header game.h yang kemungkinan berisi deklarasi fungsi-fungsi untuk mengatur logika permainan, seperti isMoveValid, makeMove, dan checkWinner.


int getEasyMove(char board[3][3]) {
// Mendefinisikan fungsi getEasyMove yang mengembalikan angka int. Fungsi ini menerima parameter papan permainan Tic Tac Toe dalam bentuk array 2D berukuran 3x3 berisi karakter.
    int move;/*Mendeklarasikan variabel move untuk menyimpan angka posisi langkah yang akan dipilih.*/
    do {/*Melakukan perulangan do-while:*/
        move = rand() % 9 + 1;/*Menghasilkan angka acak dari 1 sampai 9 (rand() % 9 + 1).*/
    } while (!isMoveValid(board, move));/*Memeriksa apakah langkah move valid (posisi kosong di papan) menggunakan fungsi isMoveValid.
                                        Jika tidak valid, ulangi lagi sampai mendapatkan langkah yang valid.*/
    return move;/*Mengembalikan nilai move yang sudah valid sebagai langkah mudah yang dipilih secara acak.*/
}

int getMediumMove(char board[3][3], char player) {
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
    return getEasyMove(board);
}

int getHardMove(char board[3][3], char player) {
    // Placeholder: masih pakai strategi medium
    return getMediumMove(board, player);
}