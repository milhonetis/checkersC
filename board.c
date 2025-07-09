#include <stdio.h>
#include <ctype.h>
#include "board.h"
#include <string.h>

char blackPiece = '#';
char whitePiece = 'O';
char playerOne;
char playerTwo;

void drawBoard(char (*board)[COLUMNS])
{
    int lineDraw, colDraw;

    // Fill each line with the '-' character and each
    // columns with the '|' character
    for(lineDraw=FIRST_CELL_LINE_AND_COL; lineDraw<LINES; lineDraw++)
    {
        for(colDraw = FIRST_CELL_LINE_AND_COL; colDraw < COLUMNS; colDraw++)
        {
            if(lineDraw % PIECE_PLACE_INC == VALID_DRAW_SPACE)
            {
                board[lineDraw][colDraw] = '-';
            }
            if(colDraw % PIECE_PLACE_INC == VALID_DRAW_SPACE && lineDraw % PIECE_PLACE_INC != VALID_DRAW_SPACE)
            {
                board[lineDraw][colDraw] = '|';
            }
        }
    }
}

void printBoard(char (*board)[COLUMNS])
{
    int lineDraw, colDraw;

    printf("    ");
    for(colDraw = FIRST_CELL_LINE_AND_COL; colDraw < COLUMNS; colDraw++)
    {
        printf("C%-3d", colDraw);
    }
    printf("\n");
    // Iterate through each line and column and print the character

    for(lineDraw = FIRST_CELL_LINE_AND_COL; lineDraw < LINES; lineDraw++)
    {
        printf("L%-3d ", lineDraw);
        for(colDraw = FIRST_CELL_LINE_AND_COL; colDraw < COLUMNS; colDraw++)
        {
            printf("%s", displayChar(board[lineDraw][colDraw]));
        }
        printf("\n");
    }
}

char *displayChar(char piece) {
    switch (piece) {
        case '#': return " # ";
        case 'O': return " O ";
        case '|': return " | ";
        case '-': return "---";
        case ' ': 
        case '\0': return "   ";
        default: return " ? ";
    }
}

void fillBoard(char (*board)[COLUMNS], char color)
{
    int lineDraw, colDraw;
    char myColor, theirColor;

    // Define which color is the first person playing to avoid
    // the need for a second fill function in case they decide to
    // play white or black
    if(color == 'b')
    {
        playerOne = blackPiece;
        playerTwo = whitePiece;
    }
    else
    { 
        playerOne = whitePiece;
        playerTwo = blackPiece;
    }

    // Start filling from the lines that have pieces in a starting game positon.
    // Since the board has bigger dimensions than 8x8 to accomodate for better graphic
    // understaindg, the offsets for each for loop have to differ a bit than the normal
    // incrementations.
    for(lineDraw = FIRST_LINE; lineDraw < THEIR_PIECES; (lineDraw = lineDraw + PIECE_PLACE_INC))
    {
        static int linePut = 0;
        static int alternate = 3;
        for(colDraw = FIRST_COL; colDraw < COLUMNS; (colDraw = colDraw + COL_INC))
        {
            if(linePut % PIECE_PLACE_INC != INVALID_CELL && (colDraw + PIECE_PLACE_INC < COLUMNS))
                board[lineDraw][colDraw + CELL_INC] = playerTwo;
            else
                board[lineDraw][colDraw] = playerTwo;
        }
        linePut++;
    }

    // Start filling from the lines that have pieces in a starting game positon.
    // Since the board has bigger dimensions than 8x8 to accomodate for better graphic
    // understaindg, the offsets for each for loop have to differ a bit than the normal
    // incrementations.
    for(lineDraw = OWN_PIECES; lineDraw < LINES; (lineDraw = lineDraw + 2))
    {
        static int linePut = 0;
        static int alternate = 3;
        for(colDraw = FIRST_COL; colDraw < COLUMNS; (colDraw = colDraw + COL_INC))
        {
            if(linePut % PIECE_PLACE_INC != INVALID_CELL)
                board[lineDraw][colDraw + CELL_INC] = playerOne;
            else 
                board[lineDraw][colDraw] = playerOne;
        }
        linePut++;
    }
}

int makeAMove(char (*board)[COLUMNS], int linefrom, int colfrom, int lineto, int colto, char player)
{
    int validMove = validateMove(board, linefrom, lineto, colfrom, colto, player);
    int result;
    if(validMove)
    {
        // Fill new spot with piece and delete the position where piece was
        // previously
        board[lineto][colto] = board[linefrom][colfrom];
        board[linefrom][colfrom] = '\0';
        result = SUCCESS;
    }
    else result = FAIL;

    return result;
}

int validateMove(char (*board)[COLUMNS], int linefrom, int lineto, int colfrom, int colto, char player)
{
    int isValid = FAIL;
    char playerType;

    if(player == 'w')
        playerType = whitePiece;
    
    else
        playerType = blackPiece;

    // If the player is one, the lines and columns have a higher value in the
    // first stage than the position they end up to according to the drawing table.
    // Oposed to that, if its player two, the lines and columns have a lower value in
    // their final position
    if((board[linefrom][colfrom] == playerType) && playerType == playerOne)
    {
       if(linefrom - lineto == PIECE_PLACE_INC)
            isValid = SUCCESS; 
    }
    else if ((board[linefrom][colfrom] == playerType)  && playerType == playerTwo)
    {
       if(lineto - linefrom == PIECE_PLACE_INC)
            isValid = SUCCESS; 
    }


    return isValid;
}
