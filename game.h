#ifndef GAME_H
#define GAME_H

void initBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int isMoveValid(char board[3][3], int move);
void makeMove(char board[3][3], int move, char symbol);
char checkWinner(char board[3][3]);

#endif