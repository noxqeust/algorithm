#include <stdio.h>

#define MAX 106

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int pos[MAX];

int L,N;

void solve(void);

int main(void)
{
	int i;

	scanf("%d %d", &L, &N);
	for(i=0; i<N; i++)
		scanf("%d", &pos[i]);
	
	solve();

	return 0;

}

void solve()
{
	int i,maxT=0, minT=0;
	for(i=0; i<N; i++)
	{
		minT=max(minT,min(pos[i], L-pos[i]));
	}

	for(i=0; i<N; i++)
	{
		maxT=max(maxT,max(pos[i], L-pos[i]));
	}
	
	printf("%d %d\n", minT, maxT);
}
