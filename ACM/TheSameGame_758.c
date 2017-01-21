// TheSameGame.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#define SIZE 11
#define SIZE2 16
int Case;
char Game[SIZE][SIZE2];
int R, C;


void printInput(){
    int i, j;
    for (i = 0; i < 10; i++){
        if (i == 0){
            printf("    ");
            for (j = 1; j <= 15; j++)
                printf("%2d  ", j);
        }
        printf("\n%2d ", 10 -i);
        
        for (j = 0; j < 15; j++)
            printf("  %c ", Game[i][j]);
        printf("\n");
    }
}

void readCase(){
    int i;
    i = 0;
    while (gets(Game[i]) && Game[i][0] != '\0'){
        i++;
    }
    /*printInput();
     printf("\n\n\n");*/
}
int Used[SIZE][SIZE2];
int Count;
char Color;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };
int Max;
int MaxI, MaxJ;

void initUsed(){
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE2; j++)
            Used[i][j] = 0;
}

int isValid(int i, int j){
    if (i < 0 || i == R)
        return 0;
    if (j < 0 || j == C)
        return 0;
    if (Used[i][j] == 1 || Game[i][j] != Color)
        return 0;
    return 1;
}

void dfs(int i, int j){
    Used[i][j] = 1;
    Count++;
    int k;
    for (k = 0; k < 4; k++){
        if (isValid(i + dx[k], j + dy[k])){
            dfs(i + dx[k], j + dy[k]);
        }
    }
}

int isValidForShift(int i, int j){
    if (i < 0 || i == R)
        return 0;
    if (j < 0 || j == C)
        return 0;
    if (Game[i][j] != Color)
        return 0;
    return 1;
}

void shiftRow(){
    int i;
    int j;
    int k; int l;
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            if (Game[i][j] == 'D'){
                for (k = i; k > 0; k--){
                    Game[k][j] = Game[k - 1][j];
                    l = k - 1;
                }
                
                Game[l][j] = 'E';
            }
}


int ShiftedColumn[SIZE2];
int shiftCount;

void shiftColumn(){
    int i, j, k;
    for(i = 0; i < shiftCount; i++){
        for(j = ShiftedColumn[i]; j < C; j++){
            for(k = 0; k < R; k++)
                Game[k][j] = Game[k][j + 1];
        }
    }
//    C--;
}

void getShiftColumn(){
    shiftCount = 0;
    int i, j;
    int flag = 1;
    for(j = 14; j >= 0; j--){
        flag = 1;
        for(i = 0; i < 10; i++){
            if(Game[i][j] != 'E' && Game[i][j] != 'D'){
                flag = 0;
                break;
            }
        }
        if(flag){
            ShiftedColumn[shiftCount++] = j;
        }
        
    }
   
}

void dfsAndShift(int x, int y){
    Game[x][y] = 'D';
    int i;
    for (i = 0; i < 4; i++){
        if (isValidForShift(x + dx[i], y + dy[i])){
            dfsAndShift(x + dx[i], y + dy[i]);
        }
    }
    
}

int Move;

void solve(){
    initUsed();
    Move++;
    
    Max = 0;
    char c;
    int i, j;
    for (i = R - 1; i >= 0; i--)
        for (j = 0; j < C && Game[i][j] != 'E'; j++){
            if (0 == Used[i][j]){
                Color = Game[i][j];
                Count = 0;
                dfs(i, j);
                if (Count > Max){
                    Max = Count;
                    MaxI = i;
                    MaxJ = j;
                    c = Game[i][j];
                }
                
            }
        }
    
    if (Max > 1){
        printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", Move, 10 - MaxI, MaxJ + 1, Max, c, (Max - 2) * (Max - 2));
        Color = c;
        dfsAndShift(MaxI, MaxJ);
        printf("%c\n", Game[MaxI][MaxJ]);
        shiftRow();
        printf("Shift row check\n");
        getShiftColumn();
        shiftColumn();
        printf("Shift column check\n");
        solve();
    }
}


void solveCase(){
    
    R = 10; C = 15;
    Move = 0;
    solve();
    
}

void printCase(){
    
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d ", &T);
    for (Case = 1; Case <= T; Case++){
        readCase();
        solveCase();
//        R = 10; C = 15;
//        getShiftColumn();
//        shiftColumn2();
    }
    return 0;
}
