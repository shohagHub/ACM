//
//  539.c
//  ACM
//
//  Created by Nazia Afroz on 7/29/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//
/*
 output:
 
 
 */
#include <stdio.h>
#define SIZE539 101

int noOfEdges, noOfnodes;
int nodes1[SIZE539], nodes2[SIZE539];
int visited539[SIZE539][SIZE539];
int maximum359;


int solve359(int nodeValue, int distance){
    /*printf("%d ", nodeValue);*/
    
    int i;
    for (i = 0; i < noOfEdges; i++) {
        
        if (nodes1[i] == nodeValue && !visited539[i][i]){
            visited539[i][i] = 1;
            int distance2 = solve359(nodes2[i], distance + 1);
            visited539[i][i] = 0;
            if (distance2 > maximum359)
                maximum359 = distance2;
            /*return distance2;*/
        }
        else if (nodes2[i] == nodeValue && !visited539[i][i]){
            visited539[i][i] = 1;
            int distance2 = solve359(nodes1[i], distance + 1);
            visited539[i][i] = 0;
            if (distance2 > maximum359)
                maximum359 = distance2;
            /*return distance2;*/
        }
    }
    
    if (distance > maximum359)
    {
        maximum359 = distance;
    }
    /*printf("\n");*/
    return distance;
}

void resetVisited539(){
    int i, j;
    for (i = 0; i < SIZE539; i++)
        for (j = 0; j < SIZE539; j++)
            visited539[i][j] = 0;
}
void reset539(){
    maximum359 = 0;
    resetVisited539();
    int i;
    for (i = 0; i < SIZE539; i++){
        nodes1[i] = -1; nodes2[i] = -1;
        
    }
    
}
int main(){
	/*printf("539\n");*/
	freopen("/Users/naziaafroz/Desktop/ACM/ACM/539.txt", "r", stdin);
	reset539();
	while (scanf("%d%d", &noOfnodes, &noOfEdges) == 2 && noOfEdges && noOfnodes)
	{

		int i;
		for (i = 0; i < noOfEdges; i++){
			scanf("%d%d", &nodes1[i], &nodes2[i]);
			/*index1[nodes1[i]] = i;*/
		}

		int result;
		for (i = 0; i < noOfEdges; i++){
			result = solve359(nodes1[i], 0);
			result = solve359(nodes2[i], 0);
			
			resetVisited539();
		}
		printf("%d\n", maximum359);
		
		reset539();
	}
	return 0;
}