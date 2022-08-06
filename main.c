#include <stdio.h>
#include <stdbool.h>
#include "choices.h"
#include "tools.h"

bool solve(int grid_p[9][9],int l);
void fill(int grid_p[9][9]);

int main(void) {
    int grid[9][9];
    char ch;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &ch);
            if (ch == '.' || ch == '0') {    
                grid[i][j] = 0;
            }
            else {      
                grid[i][j] = ch - '0';
            }
            getchar();
        }
    }
    if(solve(grid,0)){
        printf("done\n");
        print(grid);
    }else{
        printf("cannot solve\n");
        print(grid);
    }
    
    return 0;
}

bool solve(int grid_p[9][9],int l) {
    fill(grid_p);
    if(full(grid_p) && check(grid_p)){
        return true;
    }
    if(l>3){
        return false;
    }
    int n = 2;
    while (n < 3)
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int choices[9] = {0,0,0,0,0,0,0,0,0};
                if(grid_p[i][j] == 0 && choices_num(grid_p,i,j,choices) == n){
                    for(int k=1;k<=n;k++){
                        int tmp[9][9];
                        copy(grid_p,tmp);
                        tmp[i][j] = choose_one(choices,k);
                        if(solve(tmp,l+1)){
                            copy(tmp,grid_p);
                            return true;
                        }
                    }
                }
            }
        }
        n++;
    }
    return false;
}

void fill(int grid_p[9][9]){
    int change;
    do{
        change=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int choices[] = {0,0,0,0,0,0,0,0,0}; 
                if(grid_p[i][j] == 0 && choices_num(grid_p,i,j,choices) == 1){
                    
                    grid_p[i][j] = choose_one(choices,1);
                    change++;
                }
            }
        }
    }while(change!=0);
}



/*
測資
. . 6 . 2 . . . . 
7 . . 6 . . 4 . . 
2 . . . . . . 6 3 
. . . 3 . 5 6 . . 
. . 5 . . . . 2 . 
. 8 . . . 6 . . . 
. 2 . . . 3 . . 5 
. . . 7 9 . 2 . . 
9 . 1 . . . . . 6

ans
1 3 6 4 2 9 8 5 7 
7 5 8 6 3 1 4 9 2 
2 9 4 5 8 7 1 6 3 
4 7 2 3 1 5 6 8 9 
6 1 5 9 7 8 3 2 4 
3 8 9 2 4 6 5 7 1 
8 2 7 1 6 3 9 4 5 
5 6 3 7 9 4 2 1 8 
9 4 1 8 5 2 7 3 6 */
