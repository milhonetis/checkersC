#ifndef BOARD_H
#define BOARD_H

// Macro and global variable definition
#define COLUMNS 17
#define LINES 17
#define FIRST_COL 1
#define FIRST_LINE 1
#define COL_INC 4
#define CELL_INC 2
#define FIRST_CELL_LINE_AND_COL 0
#define VALID_DRAW_SPACE 0
#define INVALID_CELL 0
#define DIAGONAL_MOVE_P1 2
#define DIAGONAL_MOVE_P2 2

#define THEIR_PIECES 6
#define OWN_PIECES 11

#define DIAGONAL 2
#define SUCCESS 1
#define FAIL -1

extern char blackPiece;
extern char whitePiece;

// Function prototype for easy usage
void drawBoard(char (*board)[COLUMNS]);
void printBoard(char (*board)[COLUMNS]);
char *displayChar(char c);
void fillBoard(char (*board)[COLUMNS], char color);
int makeAMove(char (*board)[COLUMNS], int linefrom, int colfrom, int lineto, int colto, char player);
int validateMove(char (*board)[COLUMNS], int linefrom, int lineto, int colfrom, int colto, char player);

#endif
