// 852DecidingvictoryinGo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#define SIZE 10
int N;
char Board[SIZE][SIZE];
int Case;
int WCount, BCount, Count;
int isB, isW;
char const BLACK = 'X';
char const WHITE = 'O';

void readCase(){
	int i, j;
	WCount = 0;
	BCount = 0;
	for (i = 0; i < 9; i++){
		gets(Board[i]);
		for (j = 0; j < 9; j++){
			if (Board[i][j] == WHITE)
				WCount++;
			else if (Board[i][j] == BLACK)
				BCount++;
		}
	}
	/*printf("%d %d", BCount, WCount);*/
}

typedef struct Point{
	int x, y;
}Point;

Point Queue[SIZE * SIZE];
int dx[4] = {-1, 0, +1, 0};
int dy[4] = { 0, +1, 0, -1 };

void BFS(int x, int y){
	int font, rear, itemCount, i;
	font = rear = itemCount = 0;
	Point p1; p1.x = x; p1.y = y;
	Queue[rear++] = p1;
	itemCount++;
	/*Board[x][y] = '*';*/
	while (itemCount){
		Point p2 = Queue[font++];
		itemCount--;
		if (Board[p2.x][p2.y] == '.'){
			Board[p2.x][p2.y] = '*';
			Count++;
		}
		else{
			if (Board[p2.x][p2.y] == BLACK){
				isB = 1;
			}
			else if (Board[p2.x][p2.y] == WHITE)
				isW = 1;
			continue;
		}
		for (i = 0; i < 4; i++){
			int a, b;
			a = dx[i] + p2.x; b = dy[i] + p2.y;
			if (a >= 0 && a < N && b >= 0 && b < N){
				Point p3; p3.x = a; p3.y = b;
				Queue[rear++] = p3;
				itemCount++;
			}
		}

 	}
}

void dfs(int x, int y){
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	if (Board[x][y] == '.'){
		Board[x][y] = '*';
		Count++;
	}
	else{
		if (Board[x][y] == WHITE)
			isW = 1;
		else if (Board[x][y] == BLACK)
			isB = 1;
		return;
	}
	dfs(x - 1, y); dfs(x + 1, y);
	dfs(x, y - 1); dfs(x, y + 1);
}

void solveCase(){
	N = 9;
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			if (Board[i][j] == '.'){
				Count = 0;
				isB = 0;
				isW = 0;
				dfs(i, j);
				/*BFS(i, j);*/
				if (isB && isW)
					continue;
				if (isB)
					BCount += Count;
				else
					WCount += Count;
			}
		}
}

void printCase(){
	printf("Black %d White %d\n", BCount, WCount);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	gets(Board[0]);
	for (Case = 1; Case <= T; Case++){
		readCase();
		solveCase();
		printCase();
	}
}