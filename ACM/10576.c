//
//  10576.c
//  10576
//
//  Created by Nazia Afroz on 10/4/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#define UVA 1
#define UVA_D 1
#define SIZE 13
int S, D;
int Path[SIZE];

int Max;

void readCase(){
    
}

void print(){
    int i;
    for(i = 0; i < 12; i++)
        printf("%d ", Path[i]);
    printf("\n");
}

void solve(int level, int total, int lastFive){
    
    if(level == 12){
#ifndef UVA_D
        print();
#endif
        if(total > Max)
            Max = total;
        return;
    }
    if(level < 4){
        Path[level] = S;
        solve(level + 1, total + S, lastFive + S);
        Path[level] = -D;
        solve(level + 1, total - D, lastFive - D);
    }
    else if(level == 4){
        if(lastFive + S < 0){
            Path[level] = S;
            solve(level + 1, total + S, lastFive + S);
        }
        if(lastFive - D < 0){
            Path[level] = -D;
            solve(level + 1, total - D, lastFive - D);
        }
    }
    else if(level >= 5){
        if(lastFive + S - Path[level - 5] < 0){
            Path[level] = S;
            solve(level + 1, total + S, lastFive + S - Path[level - 5]);
        }
        if(lastFive - D -Path[level - 5] < 0){
            Path[level] = -D;
            solve(level + 1, total - D, lastFive - D - Path[level - 5]);
        }
    }
    
}
void solveCase(){
    Max = -D * 12;
    solve(0, 0, 0);
    
}

void printCase(){
    if(Max > 0){
        printf("%d\n", Max);
    }
    else
        printf("Deficit\n");
}


int main(){
#ifndef UVA
    freopen("udebug.txt", "r", stdin);
#endif
    while (2 == scanf("%d %d", &S, &D)) {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}