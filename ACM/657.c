// TheDieIsCast.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 51
int Case;
int W, H;
char Picture[SIZE][SIZE];
int Visited[SIZE][SIZE];
int Output[SIZE * SIZE];
int count;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void initCase(){
	int i, j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			Visited[i][j] = 0;
	count = 0;

}

void readCase(){
	int i;
	for (i = 0; i < H; i++)
		scanf("%s", Picture[i]);
}
int isValidCross(int row, int column){
	if (Picture[row][column] == '*' || Picture[row][column] == '.')
		return 0;
	if (row < 0)
		return 0;
	if (row == H)
		return 0;
	if (column < 0) return 0;
	if (column == W) return 0;
	return 1;
}
void visitCross(int x, int y){

	Picture[x][y] = '*';
	int i;
	for (i = 0; i < 4; i++)
		if (isValidCross(x + dx[i], y + dy[i]))
			visitCross(x + dx[i], y + dy[i]);

}

int isValidStar(int row, int column){
	if (Visited[row][column] || Picture[row][column] == '.')
		return 0;
	if (row < 0)
		return 0;
	if (row == H)
		return 0;
	if (column < 0)
		return 0;
	if (column == W)
		return 0;
	return 1;
}

void visitStar(int x, int y){
	Visited[x][y] = 1;
	if (Picture[x][y] == 'X'){
		Output[count]++;
		visitCross(x, y);
	}
	int i;
	for (i = 0; i < 4; i++){
		if (isValidStar(x + dx[i], y + dy[i]))
			visitStar(x + dx[i], y + dy[i]);
	}
}



void solveCase(){
	int i, j;
	for (i = 0, count = 0; i < H; i++){
		for (j = 0; j < W; j++){
			Output[count] = 0;
			if (Picture[i][j] == '.')
				Visited[i][j] = 1;
			else if (0 == Visited[i][j])
				visitStar(i, j);
			if (Output[count]) count++;
			
		}
	}
	/*printf("%d", Output[0]);*/
}

void sortResult(){
	int i, j;
	for (i = 0; i < count; i++)
		for (j = 1; j < count; j++)
			if (Output[j] < Output[j - 1]){
				int temp = Output[j];
				Output[j] = Output[j - 1];
				Output[j - 1] = temp;
			}
}

void printCase(){
	printf("Throw %d\n", Case);
	int i;
	if (Output[0])
		printf("%d", Output[0]);
	for (i = 1; i < count; i++){
		printf(" %d", Output[i]);
	}
	printf("\n\n");
}

int main(){
	freopen("input.txt", "r", stdin);
	Case = 0;
	while (2 == scanf("%d %d", &W, &H) && W && H)
	{
		Case++;
		initCase();
		readCase();
		solveCase();
		sortResult();
		printCase();
	}
	return 0;
}