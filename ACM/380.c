//
//  380.c
//  ACM
//
//  Created by Nazia Afroz on 7/28/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>

#define SIZE 101
int testCase;
int source[SIZE], starTime[SIZE], duration[SIZE], target[SIZE];
int callTime[SIZE], extension[SIZE], used[SIZE];
int noOfLines, noOfCalls;


void reset(){
    int i;
    for (i = 0; i < SIZE; i++) {
        used[i] = 0;
    }
}


void resetAll(){
    reset();
    int i;
    for (i = 0; i < SIZE; i++) {
        source[i] = 0; starTime[i] = 0; duration[i] = 0;
        target[i] = 0;
        callTime[i] = 0; extension[i] = 0;
    }
}

int solve(int t, int no){
    int i;
    for ( i = 0; i < noOfLines; i++) {
        if (no == source[i]) {

            if(t >= starTime[i] && t <= starTime[i] + duration[i]){
                if (used[i] == 1) {
                    return 9999;
                }
                used[i] = 1;
                return solve(t, target[i]);
            }
        }
    }
    return no;
}

int main(int argc, const char * argv[]) {
   /*freopen("/Users/naziaafroz/Desktop/ACM/ACM/380_2.txt", "r", stdin);*/
    int i;
    scanf("%d", &testCase);
    int system = 0;
    printf("CALL FORWARDING OUTPUT\n");
    while (testCase--) {
        i = 0;
        resetAll();
        system++;
        while (scanf("%d", &source[i])) {
            if (source[i] == 0) {
                break;
            }
            scanf("%d%d%d", &starTime[i], &duration[i], &target[i]);
            i++;
        }
        noOfLines = i;
        i = 0;
        while (scanf("%d", &callTime[i]) == 1) {
            if (callTime[i] == 9000) {
                break;
            }
            scanf("%d", &extension[i]);
            i++;
            
        }
        noOfCalls = i;
        printf("SYSTEM %d\n", system);
        
        
        int result;
        for (i = 0; i < noOfCalls; i++) {
            result = solve(callTime[i], extension[i]);
            printf("AT %04d CALL TO %04d RINGS %04d\n", callTime[i], extension[i], result);
            reset();
        }
        
    }
    printf("END OF OUTPUT\n");
   
    
    return 0;
}
