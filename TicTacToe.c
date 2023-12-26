#include <stdio.h>
#include <stdlib.h>



void resetPlanszy(char plansza[3][3]){
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
    plansza[i][j] = ' ';
    }
}
}



void drukPlanszy(char plansza[3][3]){
  for(int i=0; i<=2; i++){
    if(i!=2){
    printf(" %c | %c | %c \n", plansza[i][0], plansza[i][1], plansza[i][2]);
    printf("---|---|---\n");
    }
    else{
        printf(" %c | %c | %c \n", plansza[i][0], plansza[i][1], plansza[i][2]);
    }
  }  
}



void ruchX(char plansza[3][3]){
    int kolumna;
    int rzad;
    printf("\nGracz X");
    printf("\nPodaj kolumne i rzad:\nKolumna: ");
    scanf("%d", &kolumna);
    printf("Rzad: ");
    scanf("%d", &rzad);
    if(plansza[rzad-1][kolumna-1] == ' '){
        plansza[rzad-1][kolumna-1] = 'X';
    }
    else{
        printf("\nPole jest zajete! Wybierz inne pole!");
        ruchX(plansza);
    }

}



void ruchO(char plansza[3][3]){
    int kolumna;
    int rzad;
    printf("\nGracz O");
    printf("\nPodaj kolumne i rzad:\nKolumna: ");
    scanf("%d", &kolumna);
    printf("Rzad: ");
    scanf("%d", &rzad);
    if(plansza[rzad-1][kolumna-1] == ' '){
        plansza[rzad-1][kolumna-1] = 'O';
    }
    else{
        printf("\nPole jest zajete! Wybierz inne pole!");
        ruchO(plansza);
    }

}




int sprawdzWin(char plansza[3][3]){
    //sprawdza czy gra została wygrana w rzędach lub kolumnach

    if((plansza[0][0] == 'X'|| plansza[0][0] == 'O') && (plansza[0][0]==plansza[0][1]) && (plansza[0][1]==plansza[0][2])){
        return 1;
    }
    else if((plansza[1][0] == 'X'|| plansza[1][0] == 'O') && (plansza[1][0]==plansza[1][1]) && (plansza[1][1]==plansza[1][2])){
        return 1;
    }
    else if((plansza[2][0] == 'X'|| plansza[2][0] == 'O') && (plansza[2][0]==plansza[2][1]) && (plansza[2][1]==plansza[2][2])){
        return 1;
    }
    else if((plansza[0][0] == 'X'|| plansza[0][0] == 'O') && (plansza[0][0]==plansza[1][0]) && (plansza[1][0]==plansza[2][0])){
        return 1;
    }
    else if((plansza[0][1] == 'X'|| plansza[0][1] == 'O') && (plansza[0][1]==plansza[1][1]) && (plansza[1][1]==plansza[2][1])){
        return 1;
    }
    else if((plansza[0][2] == 'X'|| plansza[0][2] == 'O') && (plansza[0][2]==plansza[1][2]) && (plansza[1][2]==plansza[2][2])){
        return 1;
    }
    
//sprawdza czy gra została wygrana po przekątnych
if((plansza[0][2] == 'X' || plansza[0][2] == 'O') && (plansza[0][2] == plansza[1][1]) && (plansza[1][1] == plansza[2][0])){
    return 1;
}
else if((plansza[0][0] == 'X' || plansza[0][0] == 'O') && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2])){
    return 1;
}
//sprawdza czy w grze doszło do remisu
    int r=1;
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
        if(plansza[i][j] == ' '){
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
  char plansza[3][3];
  int win = 0;

  resetPlanszy(plansza);

  while (win == 0){
     system("cls");
     drukPlanszy(plansza);
     ruchO(plansza);
     system("cls");
     drukPlanszy(plansza);
     win = sprawdzWin(plansza);
     if(win == 1){
        printf("Wygrana!");
        break;}
     else if(win == 2){
        printf("Remis!");
        break;}
     
     ruchX(plansza);
     system("cls");
     drukPlanszy(plansza);
     win = sprawdzWin(plansza);
     if(win == 1){
        printf("Wygrana!");
        break;}
     else if (win == 2){
        printf("Remis!");
    break;}
     }
     

 return 0;
}
