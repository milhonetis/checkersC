#ifndef BOARD_H
#define BOARD_H

// Macro and global variable definition
#define COLUMNS 17
#define LINES 17

#define THEIR_PIECES 6
#define OWN_PIECES 11

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
