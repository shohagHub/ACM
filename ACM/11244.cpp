// 11244CountingStars.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#define SIZE 101
int R, C;
char Sky[SIZE][SIZE];

void readCase(){
	int i;
	for (i = 0; i < R; i++){
		scanf("%s", Sky[i]);
	}
	/*printf(" ");*/

}

int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dy[8] = {0, +1, +1, +1, 0, -1, -1, -1};
int starCount;
int isValid(int x, int y){
	if (x < 0 || x == R)
		return 0;
	if (y < 0 || y == C)
		return 0;
	if (Sky[x][y] == '.')
		return 0;
	return 1;
}

int isStar(int x, int y){
	
	int i;
	for (i = 0; i < 8; i++)
		if (isValid(x + dx[i], y + dy[i]))
			return 0;
	return 1;
}

void solveCase(){
	starCount = 0;
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++){
			if (Sky[i][j] == '*')
				if (isStar(i, j))
					starCount++;
		}
}

void printCase(){
	printf("%d\n", starCount);
}

int main(){
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &R, &C) == 2){
		if (R == 0 && C == 0)
			return 0;
		readCase();
		solveCase();
		printCase();
	}
}
