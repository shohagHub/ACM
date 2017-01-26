// 785GridColouring.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#define SIZE1 35
#define SIZE2 85
int R, C;
char Grid[SIZE1][SIZE2];
int Visited[SIZE1][SIZE2];
char countour;
char currentChar;

void initCase(){
	int i, j;
	for (i = 0; i < SIZE1; i++)
		for (j = 0; j < SIZE2; j++){
			Grid[i][j] = '\0';
			Visited[i][j] = 0;
		}
}

void countColumn(){
	for (C = 0; Grid[0][C]; C++);
}

void findContoutChar(){
	int i;
	for (i = 0; Grid[0][i]; i++){
		if (Grid[0][i] != ' ' && Grid[0][i] != '_'){
			countour = Grid[0][i];
			break;
		}
	}
}

void dfs(int x, int y){
	if (x < 0 || x >= R || y < 0 || y >= SIZE2 || Grid[x][y] == countour || 1 == Visited[x][y])
		return;
	if (Grid[x][y] == '\0')
		return;
	Grid[x][y] = currentChar;
	Visited[x][y] = 1;
	dfs(x - 1, y); dfs(x, y + 1);
	dfs(x + 1, y); dfs(x, y - 1);
}

void solveCase(){
	findContoutChar();
	int i, j;
	for (i = 0; i < R; i++){
		for (j = 0; Grid[i][j]; j++)
			if (Grid[i][j] != ' ' && Grid[i][j] != '_' && Grid[i][j] != countour && !Visited[i][j]){
				currentChar = Grid[i][j];
				dfs(i, j);
			}
	}
}

void printCase(){
	int i, j;
	for (i = 0; i <= R; i++){
		for (j = 0; Grid[i][j]; j++)
			printf("%c", Grid[i][j]);
		printf("\n");
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (1){
		initCase();
		R = 0;
		while (1){
			if (!gets(Grid[R]))
				return 0;
			if (Grid[R][0] == '_')
				break;
			R++;
		}
		countColumn();
		solveCase();
		printCase();
	}
	return 0;
}
