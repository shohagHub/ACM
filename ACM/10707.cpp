// 10707.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <algorithm>
using namespace std;

#define SIZE1 105
#define SIZE2 3005
int W, H, n;
int Board1[SIZE1][SIZE1];
int Board2[SIZE1][SIZE1];
int Adj1[SIZE2], Adj2[SIZE2];

void initCaase(){
	int i;
	for (i = 0; i < n; i++){
		Adj1[i] = 0; Adj2[i] = 0;
	}
	int j;
	for (i = 0; i < W; i++)
	for (j = 0; j < H; j++){
		Board1[i][j] = 0;
		Board2[i][j] = 0;
	}

}

void readCase(){
	scanf("%d %d %d", &W, &H, &n);
	int i;
	int xi, yi;
	for (i = 0; i < n; i++){
		scanf("%d %d", &xi, &yi);
		Board1[xi][yi] = 1;
	}
	for (i = 0; i < n; i++){
		scanf("%d %d", &xi, &yi);
		Board2[xi][yi] = 1;
	}

}

void bubbleSort(int length, int a[]){
	int i, j, flag;
	
	for (i = 1; i < length; i++){
		flag = 0;
		for (j = 0; j < length - i; j++){
			if (a[j] < a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void solve(int b[][SIZE1], int Ans[]){
	int i, j, count;
	int L[SIZE1][SIZE1], R[SIZE1][SIZE1], U[SIZE1][SIZE1], D[SIZE1][SIZE1];
	for (i = 0; i < W; i++)
	for (j = H - 1, count = 0; j >= 0; j--)
		count = b[i][j] ? count + b[i][j] : 0, L[i][j] = count;
	for (i = 0; i < W; i++)
	for (j = 0, count = 0; j < H; j++)
		count = b[i][j] ? count + b[i][j] : 0, R[i][j] = count;
	for (j = 0; j < H; j++)
	for (i = 0, count = 0; i < W; i++)
		count = b[i][j] ? count + b[i][j] : 0, D[i][j] = count;
	for (j = 0; j < H; j++)
	for (i = W - 1, count = 0; i >= 0; i--)
		count = b[i][j] ? count + b[i][j] : 0, U[i][j] = count;

	/*Now count the total adjacency of each point*/
	int k = 0;
	for (i = 0; i < W; i++)
	for (j = 0; j < H; j++)
	if (b[i][j] == 1)
		Ans[k++] = L[i][j] + R[i][j] + D[i][j] + U[i][j];

	/*bubbleSort(k, Ans);*/

	sort(Ans, Ans + k);
}

void solveCase(){
	solve(Board1, Adj1);
	solve(Board2, Adj2);
	int i;
	for (i = 0; i < n; i++)
	if (Adj1[i] != Adj2[i])
		break;
	if (i == n)
		printf("YES\n");
	else
		printf("NO\n");
}


int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		readCase();
		solveCase();
		initCaase();
	}
}