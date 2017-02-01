// 750.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 10
#define SIZE2 50
int Board[SIZE2][SIZE2];
int Visited[SIZE][SIZE];
int Output[SIZE];
int Case;
int X, Y;

void initVisited(){
	int i, j;
	for (i = 1; i < SIZE; i++){
		for (j = 1; j < SIZE; j++){
			Visited[i][j] = 0;
		}
	}
	for (i = 1; i < SIZE2; i++)
		for (j = 1; j < SIZE2; j++)
			Board[i][j] = 0;
	
}

void readCase(){
	int x, y;
	scanf("%d %d", &x, &y);
	int temp;
	temp = x;
	x = y;
	y = temp;
	Visited[x][y] = 1;
	Board[x][y] = 1;
	Output[x] = y;
	X = x; Y = y;
}

int isValid(int x, int y){
	if (1 == Visited[x][y])
		return 0;
	int valid = 1;

	int i, j;
	/*UP*/
	for (i = x; i > 0; i--)
		if (Visited[i][y])
			return 0;
	/*Down*/
	for (i = x; i < 9; i++)
		if (Visited[i][y])
			return 0;
	/*Left*/
	for (j = y; j > 0; j--)
		if (Visited[x][j])
			return 0;
	/*Right*/
	for (j = y; j < 9; j++)
		if (Visited[x][j])
			return 0;

	/*left up*/
	i = x; j = y;
	for (; i > 0 && j > 0; i--, j--)
		if (Visited[i][j])
			return 0;
	/*Right up*/
	for (i = x, j = y; i > 0 && j < 9; i--, j++)
		if (Visited[i][j])
			return 0;

	/*Right down*/
	for (i = x, j = y; i < 9 && j < 9; i++, j++)
		if (Visited[i][j])
			return 0;
	/*Left down*/
	for (i = x, j = y; i < 9 && j > 0; i++, j--)
		if (Visited[i][j])
			return 0;
	return 1;
}

/*#define DEBUG*/
int index;
void copyOutput(){
#ifdef DEBUG
	int i;
	for (i = 1; i < 9; i++)
		printf("%d", Output[i]);
	printf("\n");
#endif // DEBUG
	int j;
	for (j = 1; j < 9; j++)
		Board[index][j] = Output[j];
	
}

void solve(int row){
	int column;
	if (row == 9){
		index++;
		copyOutput();
		return;
	}
	for (column = 1; column < 9; column++){
		if (isValid(row, column)){
			Visited[row][column] = 1;
			Output[row] = column;
			solve(row + 1);
			Visited[row][column] = 0;
		}
		if (row == X && Y == column)
			solve(row + 1);
	}
}

void solveCase(){
	index = 0;
	solve(1);
}

void printCase(){
	printf("SOLN       COLUMN\n");
	printf(" #     ");
	int i, j;
	for (i = 1; i < 9; i++)
		printf(" %d", i);
	printf("\n\n");
	for (i = 1; i <= index; i++){
		printf("%2d     ", i);
		for (j = 1; j < 9; j++)
			printf(" %d", Board[i][j]);
		printf("\n");
	}

	if (Case)
		printf("\n");
		
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &Case);
	while(Case--){
		readCase();
		solveCase();
		printCase();
		initVisited();
	}
	return 0;
}
