#include <stdio.h>
unsigned long long memo[100][100];

unsigned long long traveller(int height, int width){
    if( memo[height][width] != -1){
        return memo[height][width];
    }
if(height == 0 || width ==0){
    return 0;
}
if(height == 1 || width == 1){
    return 1;
}
 memo[height][width] = traveller(height-1, width) + traveller(height, width-1);
return memo[height][width];
}

int main() {
    
    for(int i=0 ;i<100;i++){
        for (int j=0; j<100;j++){
        memo[i][j] = -1;
        }
    }

int height;
int width;
printf("\nProgram will calculate how many uniqe ways you can have when travelling from left top corner \nto right bottom corner of grid height * width big, when moving only down or right.");
printf("\n\nInput height:");
scanf("%d", &height);
printf("Input width:");
scanf("%d", &width);
unsigned long long iloscDrog;
iloscDrog = traveller(height, width);
printf("Possible ways to take:%llu", iloscDrog);

}
