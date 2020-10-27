/*
Name:   Assignment_1.c
Date:   July 6, 2019
Purpose:  This program creates a tic-tac-toe game.  It allows the user to print the board, change the board, check if the board is valid, and tell if there
          are any winning cells for Player X or Player O.
Author: Salwa Mohamed
*/

#include <stdio.h>

//creates a board with 1-9 as cells
void InitializeBoard(int m, int n , char board[][n]){
    int c =1;
    for(int i =0; i<m; i++){
        for(int j=0; j< n; j++){
            board[i][j] = c+'0';
            c++;
        }
    }
}

//prints formatted board to the user
void PrintBoard(int m, int n, char board[][n])
{
    for(int i =0; i<m; i++) {
        printf("   |   |\n");
        for (int j = 0; j < n; j++) {
            if(j>0)
                printf("|");
            printf(" %c ", board[i][j]);
        }
        if(i!=2)
            printf("\n___|___|___\n");
    }
    printf("\n   |   |");
}

//allows user to modify board with Xs or Os
void CreateBoard(int m, int n, char board[][n])
{
    int choice=0;
    char XorO, temp;

    //while user does not enter -1 as a choice, take a cell from a user and change it to a X or an O
    while(choice!=-1) {
        PrintBoard(3, 3, board);

        printf("\nEnter the number of the cell where you want to insert X or O or enter -1 to exit \n");
        scanf("%d", &choice);

        //changes the int value of choice into a char value
        temp = choice + '0';

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == temp) {
                    do {
                        printf("\nType X or O\n");
                        scanf(" %c", &XorO);
                    } while (XorO != 'O' && XorO != 'X');
                    board[i][j] = XorO;
                }
            }
        }
    }
}

//check if a board is valid or not
int IsValidBoard(int m, int n, char board[][n]) {
    int Xs = 0, Os = 0;

    //gets number of Xs and number of Os from board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X')
                Xs++;
            else if (board[i][j] == 'O')
                Os++;
        }
    }

    if (Xs > Os) {
        if (Xs - Os == 1 || Xs - Os == 0)
            return 1;
    }

    else if (Xs < Os){
        if (Os - Xs == 1 || Os - Xs == 0)
            return 1;
    }

    else if(Xs==Os)
        return 1;

    else
        return 0;

}

//list the winning cells for player X and/or player O
void ListWinningCells(int m, int n, char board[][n])
{
    int Xs=0, Os=0, emptySpot;

    //checks for potential win in rows
    for(int i=0;i<m;i++)
    {
        Xs=0;
        Os=0;

        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='X')
                Xs++;
            else if(board[i][j]=='O')
                Os++;
            else
                emptySpot=board[i][j]-'0';
        }
        if(Xs==2&&Os==0)
            printf("\nCell %d is winning cell for Player X", emptySpot);
        else if(Os==2&&Xs==0)
            printf("\nCell %d is winning cell for Player O", emptySpot);


    }

    //checks for potential win in columns
    for(int i=0;i<m;i++)
    {
        Xs=0;
        Os=0;

        for(int j=0;j<n;j++)
        {
            if(board[j][i]=='X')
                Xs++;
            else if(board[j][i]=='O')
                Os++;
            else
                emptySpot=board[j][i]-'0';
        }
        if(Xs==2&&Os==0)
            printf("\nCell %d is winning cell for Player X", emptySpot);
        else if(Os==2&&Xs==0)
            printf("\nCell %d is winning cell for Player O", emptySpot);
    }

    Xs = 0;
    Os = 0;

    for(int i=0;i<m;i++) {
        if (board[i][i] == 'X')
            Xs++;
        else if (board[i][i] == 'O')
            Os++;
        else
            emptySpot = board[i][i] - '0';
    }

    //checks for potential win in main diagonal
    if(Xs==2&&Os==0)
        printf("\nCell %d is winning cell for Player X", emptySpot);
    else if(Os==2&&Xs==0)
        printf("\nCell %d is winning cell for Player O", emptySpot);

    Xs = 0;
    Os = 0;

    for(int i=0, j=n-1;i<n;i++,j--)
    {
        if (board[i][j] == 'X')
            Xs++;
        else if (board[i][j] == 'O')
            Os++;
        else
            emptySpot = board[i][j] - '0';
    }

    //checks for potential win in opposite diagonal
    if(Xs==2&&Os==0)
        printf("\nCell %d is winning cell for Player X", emptySpot);
    else if(Os==2&&Xs==0)
        printf("\nCell %d is winning cell for Player O", emptySpot);

}

int main(void)
{
    char board[3][3], choice='a';

    //calls function InitializeBoard to initialize board
    InitializeBoard(3, 3, board);

    //keeps getting option user wants and executing it as long as the user does not press e to exit
    while(choice!='e')
    {
        printf("\n\npress 'p' to print the tic-tac-toe board");
        printf("\npress 'c' to create a tic-tac-toe board with X and O cells");
        printf("\npress 't' to test if a tic-tac-toe board is valid or invalid board");
        printf("\npress 'w' to predict winning cell for player X or O");
        printf("\npress 'e' to exit\n");
        scanf(" %c", &choice);

        if(choice=='p')
            PrintBoard(3, 3, board);

        else if(choice=='c')
            CreateBoard(3, 3, board);

        else if(choice=='t'){
            if(IsValidBoard(3, 3, board)==1)
                printf("\nThis is a valid board.");
            else
                printf("\nThis is not a valid board.");
        }

        else if(choice=='w'){
            if(IsValidBoard(3, 3, board)==1)
                ListWinningCells(3, 3, board);
            else
                printf("\nSince this is not a valid board, winning cells cannot be predicted.");
        }
    }

    return 0;
}