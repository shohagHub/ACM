#include <stdio.h>
#define SIZE 51
int X, Y, Case;
char Map[SIZE][SIZE];
int Output[2500][101];
char current;
int Count, Max;

void initCase(){
	int i, j;
	for (i = 0; i <= Max; i++)
		for (j = 'A'; j <= 'Z'; j++)
			Output[i][j] = 0;
}

void readCase(){
	int i, j;
	
	gets(Map[0]);
	for (i = 0; i < X; i++)
		gets(Map[i]);
}

void dfs(int x, int y){
	if (x < 0 || x >= X || y < 0 || y >= Y)
		return;
	if (Map[x][y] != current)
		return;
	Map[x][y] = '.';
	Count++;
	dfs(x - 1, y); dfs(x + 1, y);
	dfs(x, y - 1); dfs(x, y + 1);
}

void solveCase(){
	Max = 0;
	int i, j;
	for (i = 0; i < X; i++){
		for (j = 0; j < Y; j++){
			if (Map[i][j] != '.'){
				current = Map[i][j];
				Count = 0;
				dfs(i, j);
				Output[Count][current]++;
				if (Count > Max)
					Max = Count;
			}
		}
	}
}

void printCase(){
	printf("Problem %d:\n", Case);
	int i, j, k;
	for (i = Max; i > 0; i--){
		for (j = 'A'; j <= 'Z'; j++)
			if (Output[i][j] != 0){
				for (k = 0; k < Output[i][j]; k++)
					printf("%c %d\n", j, i);
			}
	}
	/*printf("\n");*/
}

int main(){
	Case = 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (2 == scanf("%d %d", &X, &Y)){
		if (X == 0 && Y == 0)
			break;
		Case++;
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
