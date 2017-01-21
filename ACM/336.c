// 336Node.cpp : Defines the entry point for the console application.
//
#include <stdio.h>

#define SIZE 40
int NC;
int Adj[SIZE][SIZE];
int Node[SIZE];
int N;
int Root;
int TTL;
int Case;
int Ans;
int Visited[SIZE];

typedef struct{
	int index;
	int ttl;
}Point;

int find(int node){
	int i;
	for (i = 0; i < N; i++)
		if (Node[i] == node)
			return i;
	return -1;
}

void initCase(){
	int i;
	for (i = 0; i < SIZE; i++)
		Visited[i] = 0;
}

void initAdj(){
    int i, j;
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            Adj[i][j] = 0;
}

void readCase(){
	N = 0;
	int i, j, k;
	int a, b;
	j = k = 0; 
	int f;
	int lastIndex = 0;
	for (i = 0; i < NC; i++){
		
		scanf("%d %d", &a, &b);
		if (i == 0){
            if(a == b)
                N++;
            else{
                N = N + 2;
                k++;
            }
			    
			Node[j] = a;
			Node[k] = b;
			Adj[j][k] = 1;
			Adj[k][j] = 1;
			lastIndex = k;
		}
		else{
			f = find(a);
			if (-1 != f)
				j = f;
			else
			{
				j = lastIndex + 1;
				lastIndex++;
				N++;
				Node[j] = a;
			}
			f = find(b);
			if (-1 != f)
				k = f;
			else
			{
				k = lastIndex + 1;
				Node[k] = b;
				N++;
				lastIndex++;
			}
			Adj[j][k] = 1;
			Adj[k][j] = 1;
		}
	}
}




void BFS(){
	Point Queue[SIZE * SIZE];

    
	int rootIndex = find(Root);
    if(rootIndex == -1)
        return;
	Visited[rootIndex] = 1;
	Point P;
	P.index = rootIndex;
	P.ttl = TTL;
	int front, rear, itemCount;
	front = 0;
	rear = 0;
	itemCount = 0;
	Queue[rear++] = P;
	itemCount++;
    Ans++;
	int i;
	Point node, p1;
	while (itemCount)
	{
		node = Queue[front++];
		if (node.ttl == 0){
			itemCount--;
			continue;
		}
			
		itemCount--;
		for (i = 0; i < N; i++){
			if (Adj[node.index][i] && 0 == Visited[i]){
				Visited[i] = 1;
				Ans++;
				p1.index = i;
				p1.ttl = node.ttl - 1;
				Queue[rear++] = p1;
				itemCount++;
			}
		}
	}

}

void solveCase(){
	while (scanf("%d %d", &Root, &TTL) == 2){
        if(Root == 0 && TTL == 0)
            break;
        initCase();
        Ans = 0;
		Case++;
        if(NC == 1 && N == 1)
            Ans = N;
        else
            BFS();
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case, N - Ans, Root, TTL);
	}
}

void printCase(){
	
}

int main(){
	/*freopen("input.txt", "r", stdin);*/
	Case = 0;
	while (scanf("%d", &NC) == 1 && NC){
        initAdj();
		readCase();
		solveCase();
	}
}
