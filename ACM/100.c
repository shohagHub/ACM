#include <stdio.h>
int i,j;
int maximum;


void maximumCalculation(int count){
	/*printf("\n count = %d\n ", count);*/
	if(count > maximum)
		maximum = count;
}

void solve(int n, int count){
	/*if(count == 0)
		printf("%d", n);
	else
		printf(" %d", n);*/
	count++;
	if(n == 1){
	/*printf("\n");*/
		maximumCalculation(count);
		return;
	}
	if(n % 2 == 0){
		solve(n/2, count);
	}
	else{
		solve(3*n + 1, count);
	}

}

int main(){
	/*freopen("100udebug.txt", "r", stdin);*/
	while(scanf("%d%d", &i, &j) == 2){
		maximum = 0;
		int k;
		if(i < j)
			for(k = i;k <= j; k++){
				/*printf("%d\n", i);*/
				solve(k, 0);
			}
		else
			for(k = j; k <= i; k++)
				solve(k, 0);
		printf("%d %d %d\n",i, j, maximum);


	}
	return 0;
}
