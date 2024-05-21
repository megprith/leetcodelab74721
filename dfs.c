#include <stdio.h>
#include <stdlib.h>

int visited[5] = {0, 0, 0, 0, 0};
int list[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {0, 0, 0, 1, 0}
};

void dfs(int i){
    printf("%d ", i);
    visited[i] = 1;
    for(int j = 0; j < 5; j++){
        if(list[i][j] == 1 && visited[j] == 0) {
            dfs(j);
        }
    }
}

int main(){
    dfs(0);
    return 0;
}
