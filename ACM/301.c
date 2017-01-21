//
//  301.c
//  301
//
//  Created by Nazia Afroz on 1/7/17.
//  Copyright © 2017 Nazia Afroz. All rights reserved.
//

#include <stdio.h>

#define SIZE 23
#define SIZE2 8

int N, B, NoOfOrders;
int Src[SIZE], Dest[SIZE], Passengers[SIZE];
int Capacity[SIZE2];
void readCase(){
    int i;
    for(i = 0; i < NoOfOrders; i++)
        scanf("%d %d %d", &Src[i], &Dest[i], &Passengers[i]);
    
}


void addPassenger(int index){
    int j;
    for(j = Src[index]; j < Dest[index]; j++)
        Capacity[j] += Passengers[index];
}

void removePassenger(int index){
    int j = 0;
    for(j = Src[index]; j < Dest[index]; j++)
        Capacity[j] -= Passengers[index];
}

int isValid(){
    int i;
    for(i = 0; i < B; i++)
        if(Capacity[i] > N)
            return 0;
    return 1;
            
}


int Max;
void solve(int level, int price){
    if(price > Max)
        Max = price;
    if(level == NoOfOrders){
        return;
    }
    addPassenger(level);
    if(isValid())
        solve(level + 1, price + (Dest[level] - Src[level]) * Passengers[level]);
    removePassenger(level);
    solve(level + 1, price);
}

void solveCase(){
    Max = 0;
    solve(0, 0);
}

void printCase(){
    printf("%d\n", Max);
}

int main(){
    freopen("input.txt", "r", stdin);
    while(3 == scanf("%d %d %d", &N, &B, &NoOfOrders)){
        if(N == 0 && B == 0 && NoOfOrders == 0)
            break;
        readCase();
        solveCase();
        printCase();
        
    }
    return 0;
}
