#include <stdio.h>
#define SIZE 3001
int N;
int input[SIZE];
int difference[SIZE];

int absD(int n){
	if(n < 1)
		return n * (-1);
	return n;
}

void reset(){
	int i;
	for(i = 0; i < SIZE; i++)
		difference[i] = 0;
}

int solve(){
	if(N == 1)
		return 1;
	int i, diff;
	for(i = 0; i < N - 1; i++){
		diff = absD(input[i] - input[i + 1]);
		if(diff < 1 || diff >N - 1 || difference[diff])
			return -1;
		difference[diff] = 1;
	}
	return 1;

}

int main(){
	/*freopen("10038.txt", "r", stdin);*/
	while(scanf("%d", &N) == 1){

		int i;
		for(i = 0; i < N; i++){
			scanf("%d", &input[i]);
		}
		if(solve() == 1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
		reset();
	}
	return 0;
}
