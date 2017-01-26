// 871CountingCellsinaBlob.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#define SIZE 26
int R, C;
int Case;
int Count, Max;
char Blob[SIZE][SIZE];

void columnCount(){
	int i;
	for (C = 0; Blob[0][C]; C++);
}

void readCase(){
	R = 0;
	/*gets(Blob[0]);*/
	while (gets(Blob[R]) && Blob[R][0]){
		R++;
	}

	columnCount();
}

void dfs(int x, int y){
	if (x < 0 || x >= R || y < 0 || y >= C || Blob[x][y] == '0')
		return;
	Blob[x][y] = '0';
	Count++;
	dfs(x - 1, y); dfs(x - 1, y + 1); dfs(x, y + 1); dfs(x + 1, y + 1);
	dfs(x + 1, y); dfs(x + 1, y - 1); dfs(x, y - 1); dfs(x - 1, y - 1);
}

void solveCase(){
	int i, j;
	Max = 0;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			if (Blob[i][j] == '1'){
				Count = 0;
				dfs(i, j);
				if (Count > Max)
					Max = Count;
			}
}

void printCase(){
	printf("%d\n", Max);
	if (Case)
		printf("\n");
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int T;
	scanf("%d ", &Case);

	while(Case--){
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}