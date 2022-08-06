#include <stdio.h>
#include <stdbool.h>

void copy(int a[9][9],int b[9][9]){
    for(int p=0;p<9;p++){
        for(int q=0;q<9;q++){
            b[p][q] = a[p][q];
        }
    }
    return;
}

bool full(int grid_p[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid_p[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void print(int grid_p[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid_p[i][j]);
        }
        printf("\n");
    }
}

bool check(int grid_p[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<8;j++){
            for(int x=j+1;x<9;x++){
                if(grid_p[i][j]!=0 && grid_p[i][j] == grid_p[i][x]){
                   return false;
                }
                if(grid_p[j][i]!=0 && grid_p[j][i] == grid_p[x][i]){
                    return false;
                }
            }

        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int p=0;p<8;p++){
                for(int q=p+1;q<9;q++){
                    if(grid_p[3*i+p/3][3*j+p%3]!=0 && grid_p[3*i+p/3][3*j+p%3] == grid_p[3*i+q/3][3*j+q%3]){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}