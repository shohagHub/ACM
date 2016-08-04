//
//  677.c
//  ACM
//
//  Created by Nazia Afroz on 8/3/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#define SIZE 11
int V, walkOfLength;
int Graph[SIZE][SIZE];
int used[SIZE];
int output[SIZE];
void solve677(int i){
    if (i == walkOfLength + 1) {
        int j;
        for (j = 0; j <= walkOfLength; j++) {
            printf("%d, ", output[i]);
        }
        printf("\n");
        return;
    }
    int j;
    for (j = 2; j <= V; j++) {
        if (Graph[i][j] == 1 && !used[j]) {
            used[j] = 1;
            output[i] = j;
            solve677(i + 1);
//            used
        }
    }
    
}
int main(){
    freopen("/Users/naziaafroz/Desktop/ACM/ACM/677.txt", "r", stdin);
    while (2 == scanf("%d %d", &V, &walkOfLength)) {
        int i, j;
        for (i = 1; i <= V; i++)
            for (j = 1; j <= V; j++)
                scanf("%d", &Graph[i][j]);
        output[0] = 1;
        solve677(1);
    }
//    printf("677");
    return 0;
}