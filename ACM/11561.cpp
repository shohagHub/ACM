// 11561GettingGold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 50

int W, H;
char Game[SIZE][SIZE];
int Gold;
int Visited[SIZE][SIZE];

void initCase(){
	int i, j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			Visited[i][j] = 0;
}

void readCase(){
	int i;
	for (i = 0; i < H; i++)
		scanf("%s", &Game[i]);
}




typedef struct Point{
	int x, y;
}Point;

Point Queue[SIZE * SIZE];
int Font, Rear, itemCount;

int canMove(Point p1)
{
	int upMove, downMove, leftMove, rightMove;
	upMove = downMove = rightMove = leftMove = 1;
	if (p1.x - 1 >= 0)
		if (Game[p1.x - 1][p1.y] == 'T')
			upMove = 0;
	if (p1.x + 1 < H)
		if (Game[p1.x + 1][p1.y] == 'T')
			downMove = 0;
	if (p1.y - 1 >= 0)
		if (Game[p1.x][p1.y - 1] == 'T')
			leftMove = 0;
	if (p1.y + 1 < W)
		if (Game[p1.x][p1.y + 1] == 'T')
			rightMove = 0;

	return upMove && leftMove && downMove && rightMove;
}

void BFS(int x, int y){
	Font = 0;
	Rear = 0;
	itemCount = 0;
	Point p;
	p.x = x; p.y = y;
	Queue[Rear++] = p;
	itemCount++;
	Visited[x][y] = 1;
	Point p1;
	while (itemCount){
		p1 = Queue[Font++];
		itemCount--;
		x = p1.x; y = p1.y;
		if (Game[p1.x][p1.y] == 'G')
			Gold++;
		if (!canMove(p1))
			continue;
		Point p2;
		if (x - 1 > 0 && !Visited[x - 1][y] && Game[x - 1][y] != '#'){
			Visited[x - 1][y] = 1;
			p2.x = x - 1;
			p2.y = y;
			Queue[Rear++] = p2;
			itemCount++;
		}
		if (x + 1 < H && !Visited[x + 1][y] && Game[x + 1][y] != '#'){
			Visited[x + 1][y] = 1;
			p2.x = x + 1;
			p2.y = y;
			Queue[Rear++] = p2;
			itemCount++;
		}
		if (y - 1 > 0 && !Visited[x][y - 1] && Game[x][y - 1] != '#'){
			Visited[x][y - 1] = 1;
			p2.x = x;
			p2.y = y - 1;
			Queue[Rear++] = p2;
			itemCount++;
		}
		if (y + 1 < W && !Visited[x][y + 1] && Game[x][y + 1] != '#'){
			Visited[x][y + 1] = 1;
			p2.x = x;
			p2.y = y + 1;
			Queue[Rear++] = p2;
			itemCount++;
		}


	}

}

void solveCase(){
	Gold = 0;
	int i, j;
	for (i = 1; i < H; i++)
		for (j = 0; j < W; j++)
			if (Game[i][j] == 'P'){
				Game[i][j] = '.';
				BFS(i, j);
			}
}

void printCase(){
	printf("%d\n", Gold);
}

int main(){
	freopen("input.txt", "r", stdin);
	while (2 == scanf("%d %d", &W, &H)){
		initCase();
		readCase();
		solveCase();
		printCase();
	}
}