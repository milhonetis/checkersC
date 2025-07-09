#include <stdio.h>
#include <ctype.h>
#include "board.h"

int main(void)
{
    // Start board
    char board[LINES][COLUMNS]={0};
    char gameMode;
    int win = 0;

    // Player types;
    static char playerTypeW = 'w';
    static char playerTypeB = 'b';

    printf("Welcome to Checkers!\n");
    printf("Press w for white (goes first) and b for black (goes second):\t");
    scanf("%c", &gameMode);

    // Check wether character is on par with requirements
    while(tolower(gameMode) != 'b' && tolower(gameMode) != 'w') 
    {
        printf("You chose an imcompatible type of color!\nPlease try again!\n(w/W or b/B):\t");
        scanf(" %c", &gameMode);
    }

    drawBoard(board);

    // Initialize the board with pieces
    fillBoard(board, tolower(gameMode));

    // Print the board
    printBoard(board);

    // Play a move while game not ending
    while(!win)
    {
        int linefrom, lineto, colfrom, colto;
    
        printf("%c choses a move from (seperate it by spaces):\t", gameMode);
        scanf("%d", &linefrom);
        scanf("%d", &colfrom);
        printf("\n%c choses a move to (seperate it by spaces):\t", gameMode);
        scanf("%d", &lineto);
        scanf("%d", &colto);
        while(makeAMove(board, linefrom, colfrom, lineto, colto, gameMode) != SUCCESS)
        {
            printf("Move was invalid!! Please chose a valid move!\n");
            printf("%c choses a move from (seperate it by spaces):\t", gameMode);
            scanf("%d", &linefrom);
            scanf("%d", &colfrom);
            printf("\n%c choses a move to (seperate it by spaces):\t", gameMode);
            scanf("%d", &lineto);
            scanf("%d", &colto);
        }
        printBoard(board);
        if(gameMode == playerTypeW)
            gameMode = playerTypeB;
        else gameMode = playerTypeW;

    }

    return 0;
}
