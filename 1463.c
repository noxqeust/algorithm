#include <stdio.h>

#define SIZE 1000000

int dp[SIZE];

int MIN2(int a, int b)
{
	int min=0x7ffff;
	if(a<min)
		min=a;
	if(b<min)
		min=b;

	return min;
}

int main(void)
{
	int i,N;
	scanf("%d", &N);
	
	dp[1]=0;
	for(i=2; i<=N; i++)
	{
		dp[i]=1+dp[i-1];
		if(i%2==0)
			dp[i]=MIN2(dp[i], dp[i/2]+1);
		if(i%3==0)
			dp[i]=MIN2(dp[i], dp[i/3]+1);
	}


	printf("%d\n", dp[N]);

	return 0;
}
