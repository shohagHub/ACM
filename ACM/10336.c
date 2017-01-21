//
//  10336.c
//  10336
//
//  Created by Nazia Afroz on 1/20/17.
//  Copyright © 2017 Nazia Afroz. All rights reserved.
//

#include <stdio.h>


#define SIZE 505
int H, W;
int Case;
char Map[SIZE][SIZE];
int Visited[SIZE][SIZE];
int Count[200];
int Length;

typedef struct Solution{
    char ch;
    int rank;
}Solution;

Solution Sol[30];
Solution B[30];

typedef struct{
    int x, y;
}Point;

Point Queue[SIZE * SIZE];

void initCase(){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++)
            Visited[i][j] = 0;
    }
    for(i = 0; i < 201; i++)
        Count[i] = 0;
}


void readCase(){
    scanf("%d %d", &H, &W);
    int i;
    for(i = 0; i < H; i++){
        scanf("%s", Map[i]);
    }
}

int dx[4] = {-1, 0,+1, 0};
int dy[4] = {0, +1, 0, -1};

void BFS(int x, int y){
    int font, rear, itemCount, i;
    font = rear = itemCount = 0;
    Point p1; p1.x = x; p1.y = y;
    Queue[rear++] = p1;
    Visited[x][y] = 1;
    itemCount++;
    while (itemCount) {
        Point p2 = Queue[font++];
        itemCount--;
        for(i = 0; i < 4; i++){
            int a, b;
            a = p2.x + dx[i]; b = p2.y + dy[i];
            if(a >= 0 && a < H && b >= 0 && b < W && !Visited[a][b] && Map[a][b] == Map[x][y]){
                Point p3;
                p3.x = a;
                p3.y = b;
                Visited[a][b] = 1;
                Queue[rear++] = p3;
                itemCount++;
            }
        }
    }
}


void bubbleSort(){
    int i, k, flag;
    for(k = 1; k < Length; k++){
        flag = 0;
        for(i = 0; i < Length - k; i++){
            if(Sol[i].rank < Sol[i + 1].rank){
                Solution temp;
                temp = Sol[i];
                Sol[i] = Sol[i + 1];
                Sol[i + 1] = temp;
                flag = 1;
            }
            else if(Sol[i].rank == Sol[i + 1].rank){
                if(Sol[i].ch > Sol[i + 1].ch){
                    Solution temp;
                    temp = Sol[i];
                    Sol[i] = Sol[i + 1];
                    Sol[i + 1]= temp;
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            break;
    }
}

void solveCase(){
    int i, j;
    for(i = 0; i < H; i++)
        for(j = 0; j < W; j++){
            if(!Visited[i][j]){
                BFS(i, j);
                Count[Map[i][j]]++;
            }
        }
    
    Length = 0;
    for(i = 'a'; i <= 'z'; i++){
        if(Count[i]){
            Sol[Length].ch = i;
            Sol[Length].rank = Count[i];
            Length++;
        }
    }
    
    bubbleSort();
    
}

void printCase(){
    printf("World #%d\n", Case);
    int i;
    for(i = 0; i < Length; i++)
    {
        printf("%c: %d\n", Sol[i].ch, Sol[i].rank);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(Case = 1; Case <= T; Case++){
        initCase();
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
