// 729.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 18
int Output[SIZE];
int N, H;
int Case;

void readCase(){
	scanf("%d %d", &N, &H);
}

void print(){
	int i;
	for (i = 0; i < N; i++)
		printf("%d", Output[i]);
	printf("\n");
}

void Bin(int level, int count){
	if (count > H)
		return;
	int i;
	if (level == N){
		if (count == H)
			print();
		return;
	}
	
	Output[level] = 0;
	Bin(level + 1, count);

	Output[level] = 1;
	Bin(level + 1, count + 1);

}

void solveCase(){
	Bin(0, 0);
}

void printCase(){

}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &Case);
	while (Case--){
		readCase();
		solveCase();
		printCase();
		if (Case)
			printf("\n");
	}
	return 0;
}