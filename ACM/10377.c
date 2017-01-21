//
//  10377.c
//  10377
//
//  Created by Nazia Afroz on 10/11/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#define SIZE 61
int Row, Column;
int Case;
char Maze[SIZE][SIZE];
int X, Y;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int direction;

void readCase(){
    scanf("%d %d ",&Row, &Column);
    int i;
    for(i = 0; i < Row; i++)
        gets(Maze[i]);
    scanf("%d %d", &X, &Y);
    X--;
    Y--;
    
}

int isValid(int r, int c){
    
    if(r < 0)
        return 0;
    if(r == Row)
        return  0;
    if(c < 0)
        return 0;
    if(c == Column)
        return 0;
    if(Maze[r][c] == '*')
        return 0;
    return 1;
    
}

void solve(char ch)
{
    switch(ch) {
        case 'L': direction = (direction + 3) % 4;
            break;
        case 'R': direction = (direction + 1) % 4;
            break;
        case 'F':
            if(isValid(X + dx[direction], Y + dy[direction])){
                X += dx[direction];
                Y += dy[direction];
            }
            break;
    }
}

void solveCase(){
    char ch;
    direction = 0;
    do{
        ch = getchar();
        solve(ch);
        
    }
    while (ch != 'Q');
}

void printCase(){
    printf("%d %d %c\n", ++X, ++Y, "NESW"[direction]);
    if(Case)
        printf("\n");
    
}

int main(){
    /*freopen("input.txt", "r", stdin);*/
    scanf("%d", &Case);
    while (Case--){
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}