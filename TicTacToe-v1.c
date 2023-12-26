#include <stdio.h>
#include <stdlib.h>



void resetBoard(char board[3][3]){
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
    board[i][j] = ' ';
    }
}
}



void printBoard(char board[3][3]){
  for(int i=0; i<=2; i++){
    if(i!=2){
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    printf("---|---|---\n");
    }
    else{
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    }
  }  
}



void moveX(char board[3][3]){
    int column;
    int row;
    printf("\nPlayer X");
    printf("\nInput column and row:\nColumn: ");
    scanf("%d", &column);
    printf("Row: ");
    scanf("%d", &row);
    if(board[row-1][column-1] == ' '){
        board[row-1][column-1] = 'X';
    }
    else{
        printf("\nPlace is taken! Choose another place!");
        moveX(board);
    }

}



void moveO(char board[3][3]){
    int column;
    int row;
    printf("\nPlayer O");
    printf("\nInput column and row:\nColumn: ");
    scanf("%d", &column);
    printf("Row: ");
    scanf("%d", &row);
    if(board[row-1][column-1] == ' '){
        board[row-1][column-1] = 'O';
    }
    else{
        printf("\nPlace is taken! Choose another place!");
        moveO(board);
    }

}




int checkWin(char board[3][3]){
    

    if((board[0][0] == 'X'|| board[0][0] == 'O') && (board[0][0]==board[0][1]) && (board[0][1]==board[0][2])){
        return 1;
    }
    else if((board[1][0] == 'X'|| board[1][0] == 'O') && (board[1][0]==board[1][1]) && (board[1][1]==board[1][2])){
        return 1;
    }
    else if((board[2][0] == 'X'|| board[2][0] == 'O') && (board[2][0]==board[2][1]) && (board[2][1]==board[2][2])){
        return 1;
    }
    else if((board[0][0] == 'X'|| board[0][0] == 'O') && (board[0][0]==board[1][0]) && (board[1][0]==board[2][0])){
        return 1;
    }
    else if((board[0][1] == 'X'|| board[0][1] == 'O') && (board[0][1]==board[1][1]) && (board[1][1]==board[2][1])){
        return 1;
    }
    else if((board[0][2] == 'X'|| board[0][2] == 'O') && (board[0][2]==board[1][2]) && (board[1][2]==board[2][2])){
        return 1;
    }
    

if((board[0][2] == 'X' || board[0][2] == 'O') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
    return 1;
}
else if((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
    return 1;
}

    int r=1;
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
        if(board[i][j] == ' '){
            r=0;
        }
       
    }
}
if(r==0){
 return 0;
}
else if (r==1){
 return 2;
}
}



int main()
{
  char board[3][3];
  int win = 0;

  resetBoard(board);

  while (win == 0){
     system("cls");
     printBoard(board);
     moveO(board);
     system("cls");
     printBoard(board);
     win = checkWin(board);
     if(win == 1){
        printf("Win!");
        break;}
     else if(win == 2){
        printf("Tie!");
        break;}
     
     moveX(board);
     system("cls");
     printBoard(board);
     win = checkWin(board);
     if(win == 1){
        printf("Win!");
        break;}
     else if (win == 2){
        printf("Tie!");
    break;}
     }
     

 return 0;
}
