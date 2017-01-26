#include <stdio.h>
#define SIZE 10005
int Domino[SIZE][SIZE];
int Visited[SIZE];
int Case, Count;
int N, M, L;

void initCase(){
	Count = 0;
	int i, j;
	for (i = 0; i <= N; i++){
		Visited[i] = 0;
		for (j = 0; j <= N; j++){
			Domino[i][j] = 0;
		}
	}
}

void readCase(){
	scanf("%d %d %d", &N, &M, &L);
	int i, a, b;
	for (i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		Domino[a][b] = 1;
	}
	
}

int Queue[SIZE * SIZE];

void BFS(int x){
	int front, rear, itemCount, i;
	front = rear = itemCount = 0;
	Queue[rear++] = x;
	Visited[x] = 1;
	itemCount++;
	while (itemCount){
		int item = Queue[front++];
		Count++;
		/*Visited[item] = 1;*/
		itemCount--;
		for (i = 1; i <= N; i++){
			if (Domino[item][i] && !Visited[i]){
				Queue[rear++] = i;
				Visited[i] = 1;
				itemCount++;
			}
		}
	}
}

void dfs(int x){
	int i;
	Count++;
	/*printf("%d ", x);*/
	Visited[x] = 1;
	for (i = 1; i <= N; i++){
		if (Domino[x][i] && !Visited[i])
			dfs(i);
	}
}

void solveCase(){
	
	int i;
	int a;
	Count = 0;
	for (i = 0; i < L; i++){
		scanf("%d", &a);
		if (!Visited[a]){
			/*printf("For %d\n", a);*/
			/*dfs(a);*/
			BFS(a);
			/*printf("End %d\n", a);*/
		}
			
	}
}

void printCase(){
	printf("%d\n", Count);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++){
		readCase();
		solveCase();
		printCase();
		initCase();
	}
	return 0;
}