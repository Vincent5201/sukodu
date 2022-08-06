#include <stdio.h>

int choices_num(int grid_p[9][9],int x,int y,int choices[9]){
    for(int i=0;i<9;i++){
        if(grid_p[x][i]!=0){
            choices[grid_p[x][i]-1] = 1;
        }
        if(grid_p[i][y]!=0){
            choices[grid_p[i][y]-1] = 1;
        }
        if(grid_p[x/3*3+i/3][y/3*3+i%3]!=0){
            choices[grid_p[x/3*3+i/3][y/3*3+i%3]-1] = 1;
        }
    }

    int n = 0;
    for(int i=0;i<9;i++){
        if(choices[i] == 0){
            n++;
        }
    }

    return n;
}

int choose_one(int choices[9],int n){
    int ans = 0,c = 1;
    for(int i=0;i<9;i++){
        if(choices[i] == 0 && c == n){
            ans = i+1;
            break;
        }else if(choices[i] == 0 && c != n){
            c++;
        }
    }
    return ans;
}