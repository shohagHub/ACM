// 11085.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#define SIZE 11
int Case;
int Position[SIZE];
int Visited[SIZE][SIZE];
int Min;
int X, Y;

void initVisited(){
	int i, j;
	for (i = 1; i < SIZE; i++)
		for (j = 1; j < SIZE; j++)
			Visited[i][j] = 0;
}

void readCase(){
	int i;
	for (i = 2; i < 9; i++)
		scanf("%d", &Position[i]);
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

int absDif(int a, int b){
	if (a > b)
		return a - b;
	return b - a;
	
}

void solve(int level, int move){
	int column;
	if (level == 9){
		if (move < Min)
			Min = move;
		return;
	}
	for (column = 1; column < 9; column++){
		if (isValid(level, column)){
			Visited[level][column] = 1;
			if (Position[level] == column)
				solve(level + 1, move);
			else
				solve(level + 1, move + 1);
			Visited[level][column] = 0;
		}
		/*if (X == level && Y == column)
			solve(level + 1, move);*/
	}
}

void solveCase(){
	Min = 100;
	int i;
	solve(1, 0);
	/*for (i = 1; i < 9; i++){
		initVisited();
		Visited[Position[i]][i] = 1;
		X = Position[i]; Y = i;
		
	}*/
}

void printCase(){
	printf("Case %d: %d\n", Case, Min);
}

int main(){
	freopen("input.txt", "r", stdin);
	Case = 0;
	while (1 == scanf("%d", &Position[1])){
		Case++;
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
