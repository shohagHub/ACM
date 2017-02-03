// 776MonkeysinaRegularForest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define SIZE 1001
char Forest[SIZE][SIZE];
int Digit[SIZE][SIZE];
int Output[SIZE][SIZE];
int inputFlag = 1;
int RowCount;
int IndexNumber[SIZE];
int ColumnCount;
int ColumnDigit[SIZE];

void initOutput(){
	int i, j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			Output[i][j] = 0;

	for (i = 0; i < SIZE; i++)
		ColumnDigit[i] = 0;
}

void makeDigit(){
	int i, j, k;
	for (i = 0; i < RowCount; i++){
		k = 0;
		for (j = 0; Forest[i][j]; j++){
			if (Forest[i][j] != ' ')
				Digit[i][k++] = Forest[i][j] - 'A';
		}
	}
	ColumnCount = k;
}

void readCase(){
	int i;
	i = 0;
	while (gets(Forest[i])){
		if (Forest[i][0] == '%'){
			inputFlag = 1;
			break;
		}
		i++;
	}
	RowCount = i;
	makeDigit();
}

int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dy[8] = {0, +1, +1, +1, 0, -1, -1, -1};

int currentDigit;

int isValid(int x, int y){
	if (x < 0 || x == RowCount)
		return 0;
	if (y < 0 || y == ColumnCount)
		return 0;
	if (Output[x][y] != 0 || Digit[x][y] != currentDigit)
		return 0;
	return 1;
}

void floodFill(int x, int y, int no){
	int i;
	Output[x][y] = no;
	for (i = 0; i < 8; i++)
		if (isValid(x + dx[i], y + dy[i]))
			floodFill(x + dx[i], y + dy[i], no);
}

int getDigit(int no){
	int d = 1;
	while (no /= 10)
		d++;
	return d;
}

void solve(){
	int i, j;
	int lastNo = 0;
	for (i = 0; i < RowCount; i++)
		for (j = 0; j < ColumnCount; j++){

			if (Output[i][j] == 0){
				/*if (IndexNumber[Digit[i][j]] == 0){*/
					Output[i][j] = ++lastNo;
					/*IndexNumber[Digit[i][j]] = Output[i][j];*/
					currentDigit = Digit[i][j];
					/*int d = getDigit(lastNo);
					if (d > ColumnDigit[j])
						ColumnDigit[j] = d;*/
					floodFill(i, j, lastNo);
				/*}*/
			}
		}
}

void solveCase(){
	solve();
}

void spacing(){
	int i, j;
	int Max = 0;
	int d;
	for (j = 0; j < ColumnCount; j++){
		Max = 0;
		for (i = 0; i < RowCount; i++){
			if (Output[i][j] > Max)
				Max = Output[i][j];
		}
		d = getDigit(Max);
		ColumnDigit[j] = d;
	}
}

void printCase(){
	spacing();
	int i, j;
	for (i = 0; i < RowCount; i++){
		for (j = 0; j < ColumnCount; j++){
			if (ColumnDigit[j] < 2)
				printf("%d", Output[i][j]);
			else if (ColumnDigit[j] == 2)
				printf("%2d", Output[i][j]);
			else if (ColumnDigit[j] == 3)
				printf("%3d", Output[i][j]);
			else if (ColumnDigit[j] == 4)
				printf("%4d", Output[i][j]);

			if (j != ColumnCount - 1)
				printf(" ");
		}

		printf("\n");
	}
	printf("%%\n");
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int i;
	i = 0;
	while (inputFlag)
	{
		inputFlag = 0;
		initOutput();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}