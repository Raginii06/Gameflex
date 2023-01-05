#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int checkwin();
void board();
int fillSudoku(int puzzle[][9], int row, int col);
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void main(){
char name[50];
int ch;
int play;
do{
printf("****************************************\n");
printf("\n");
printf(" WELCOME TO GAMEFLEX \n");
printf("\n");
printf("****************************************\n");
printf("\n");
printf("\n");
printf("ENTER YOU NAME ::");
printf("\n");
printf("\n");
scanf("%s",&name);
printf("\n");
printf("***\n");
printf("\n");
printf("ENTER YOUR CHOICE OF GAME\n");
printf("\n");
printf(" 1. GUESS THE NUMBER \n");
printf("\n");
printf(" 2. TIC TAC TOE \n");
printf("\n");
printf(" 3. HANGMAN \n");
printf("\n");
printf(" 4. SUDOKU \n");
printf("\n");
printf(" 5. FACTS PRO \n");
printf("\n");
printf("****\n");
printf("MY CHOICE IS : ");
scanf("%d",&ch);
if(ch==1)
{
printf("*************\n");
printf("WELCOME TO GUESS THE NUMBER %s\n",name);
printf("*************\n");
int i=8,rval,val,flag=1;
rval=rand()%100 +1;
// Generates a random number in the range 0 to 99
printf("RULES:\n1. Only 8 chances to guess the randomly generated number.");
printf("\n2. You can WIN the game when the number guessed is same as the randomly generated number.");
printf("\n3. Hints will be provided during the PLAY.");
printf("\n\n$$$ Good Luck. Start Guessing $$$");
for (i=1; i<=8; i++)
{
printf("\n\nGUESS %d ? ",i);
scanf("%d",&val);
if (val > rval)
printf("Your value is GREATER THAN the randomly generated number");
else if (val < rval)
printf("Your value is LESSER THAN the randomly generated number");
else
{
flag=1;
break;
}
}
if (flag)
printf("\n\n** You are the WINNER. No. of tries = %d **",i);
else
printf("\n\n** You are the LOSER. **");
printf("*\n");
}
else if(ch==2)
{
printf("**************\n");
printf(" WELCOME TO TIC TAC TOE %s\n",name);
printf("**************\n");
//char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player = 1, i, choice;
char mark;
do
{
board();
player = (player % 2) ? 1 : 2;
printf("Player %d, enter a number: ", player);
scanf("%d", &choice);
mark = (player == 1) ? 'X' : 'O';
if (choice == 1 && square[1] == '1')
square[1] = mark;
else if (choice == 2 && square[2] == '2')
square[2] = mark;
else if (choice == 3 && square[3] == '3')
square[3] = mark;
else if (choice == 4 && square[4] == '4')
square[4] = mark;
else if (choice == 5 && square[5] == '5')
square[5] = mark;
else if (choice == 6 && square[6] == '6')
square[6] = mark;
else if (choice == 7 && square[7] == '7')
square[7] = mark;
else if (choice == 8 && square[8] == '8')
square[8] = mark;
else if (choice == 9 && square[9] == '9')
square[9] = mark;
else
{
printf("Invalid move ");
player--;
getch();
}
i = checkwin();
player++;
}
while (i == - 1);
board();
if (i == 1)
printf("==>\aPlayer %d win ", --player);
else
printf("==>\aGame draw");
}
else if(ch==3)
{
printf("************\n");
printf(" WELCOME TO HANGMAN %s\n",name);
printf("*************\n");
// Get word to guess
printf("***");
printf("\n");
printf("\t Be aware you can be hanged!!.");
printf("\n");
printf("****");
printf("\n");
printf("\n");
printf("\t Rules : ");
printf("\n");
printf("\t - no maximum limit for errors is given");
printf("\n");
printf("\n\t - All alphabet are in lower case.");
printf("\n");
printf("\n");
printf("***");
printf("\n");
printf(" enjoy the game\n");
printf("****\n");
char *options[10] = {"masks","sanatizer","social distancing","engineering","students","india","cafeteria","america","australia","england"};
char answer[128];
srand(time(NULL));
int i=rand()%10;
i=rand()%10;
strcpy(answer,options[i]);
fflush(stdout);
int N = strlen(answer);
int mask[N];
for (int i=0; i < N; ++i)
{
mask[i] = 0;
}
// Loop over each round of guessing
int gameover = 0;
while (! gameover)
{
// Print word with *s for unguessed letters
printf("The word is : ");
for(int j=0; j < N; ++j) {
if (mask[j])
{
printf("%c", answer[j]);
}
else
{
printf("*");
}
}
printf("\n");
// Get player's next guess
char guess;
printf("Letter? ");
fflush(stdout);
scanf(" %c", &guess);
// Mark true all mask positions corresponding to guess
for(int k=0; k < N; ++k)
{
if (answer[k] == guess)
{
mask[k] = 1;
}
}
// Determine whether the player has won!
gameover = 1;
for(int m = 0; m < N; ++m)
{
if (!mask[m])
{
gameover = 0;
break;
}
}
}
// Print victory message!
printf("Victory! The word is \"%s\".\n", answer);
}
else if(ch==4)
{
printf("**********\n");
printf(" WELCOME TO SUDOKU %s\n",name);
printf("**********\n");
int i, j;
int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
{1, 9, 0, 4, 7, 0, 6, 0, 8},
{0, 5, 2, 8, 1, 9, 4, 0, 7},
{2, 0, 0, 0, 4, 8, 0, 0, 0},
{0, 0, 9, 0, 0, 0, 5, 0, 0},
{0, 0, 0, 7, 5, 0, 0, 0, 9},
{9, 0, 7, 3, 6, 4, 1, 8, 0},
{5, 0, 6, 0, 8, 1, 0, 7, 4},
{0, 8, 0, 0, 0, 0, 0, 0, 0}};
if(fillSudoku(puzzle, 0, 0))
{
printf("\n+-----+-----+-----+\n");
for(i=1; i<10; ++i)
{
for(j=1; j<10; ++j)
printf("|%d", puzzle[i-1][j-1]);
printf("|\n");
if (i%3 == 0) printf("+-----+-----+-----+\n");
}
}
else
printf("\n\nNO SOLUTION\n\n");
}
else if(ch==5)
{
printf("**************\n");
printf(" WELCOME TO FACT PRO \n");
printf("*************\n");
//read any text file from current directory
char const* const fileName = "facts2.txt";
FILE* file = fopen(fileName, "r");
if(!file){
printf("\n Unable to open : %s ", fileName);
}
char line[500];
while (fgets(line, sizeof(line), file))
{
printf("%s", line);
}
fclose(file);
//return 0;
}
else
{
printf("**\n");
printf(" YOU ENTERED A WRONG CHOICE \n");
printf("**\n");
}
printf("\n***");
printf(" \n THANKS FOR PLAYING \n");
printf("\n***");
printf("\nDO YOU WANT TO CONTINUE PLAYING? IF YES THEN ENTER 1 ELSE ENTER 0\n");
scanf("%d",&play);
}
while(play==1);
}
int checkwin()
{
//char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
if (square[1] == square[2] && square[2] == square[3])
return 1;
else if (square[4] == square[5] && square[5] == square[6])
return 1;
else if (square[7] == square[8] && square[8] == square[9])
return 1;
else if (square[1] == square[4] && square[4] == square[7])
return 1;
else if (square[2] == square[5] && square[5] == square[8])
return 1;
else if (square[3] == square[6] && square[6] == square[9])
return 1;
else if (square[1] == square[5] && square[5] == square[9])
return 1;
else if (square[3] == square[5] && square[5] == square[7])
return 1;
else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
square[4] != '4' && square[5] != '5' && square[6] != '6' &&
square[7] != '7' && square[8] != '8' && square[9] != '9')
return 0;
else
return - 1;
}
void board()
{
system("cls");
printf("\n\n\tTic Tac Toe\n\n");
printf("Player 1 (X) - Player 2 (O)\n\n\n");
printf(" | | \n");
printf(" %c | %c | %c \n", square[1], square[2], square[3]);
printf("__|_|__\n");
printf(" | | \n");
printf(" %c | %c | %c \n", square[4], square[5], square[6]);
printf("__|_|__\n");
printf(" | | \n");
printf(" %c | %c | %c \n", square[7], square[8], square[9]);
printf(" | | \n\n");
}
int isAvailable(int puzzle[][9], int row, int col, int num)
{
int rowStart = (row/3) * 3;
int colStart = (col/3) * 3;
int i, j;
for(i=0; i<9; ++i)
{
if (puzzle[row][i] == num) return 0;
if (puzzle[i][col] == num) return 0;
if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
}
return 1;
}
int fillSudoku(int puzzle[][9], int row, int col)
{
int i;
if(row<9 && col<9)
{
if(puzzle[row][col] != 0)
{
if((col+1)<9) return fillSudoku(puzzle, row, col+1);
else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
else return 1;
}
else
{
for(i=0; i<9; ++i)
{
if(isAvailable(puzzle, row, col, i+1))
{
puzzle[row][col] = i+1;
if((col+1)<9)
{
if(fillSudoku(puzzle, row, col +1)) return 1;
else puzzle[row][col] = 0;
}
else if((row+1)<9)
{
if(fillSudoku(puzzle, row+1, 0)) return 1;
else puzzle[row][col] = 0;
}
else return 1;
}
}
}
return 0;
}
else return 1;
}

