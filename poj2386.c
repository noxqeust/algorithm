#include <stdio.h>

#define SIZE 101
int N,M;

char MAP[SIZE][SIZE]={0,};

int solve(int y, int x);
void checker(int y, int x);

void printMap(void)
{
	int i,j;
	printf("fuck %d %d\n",N,M);
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			printf("%c",MAP[i][j]);
		}
		printf("%dnew\n",j);
	}
}

int main(void)
{
	int i,j;
	scanf("%d %d", &N, &M);

	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
			scanf("%c", &MAP[i][j]);
	}
	
	printMap();
	printf("=====\n");
	printf("%d\n",solve(0,0));
	
	return 0;
}

int solve(int y, int x)
{
	int i,j;
	int count=0;
	for(i=y; i<N; i++)
	{
		for(j=x; j<M; j++)
		{
			if(MAP[i][j]=='w')
			{
				count++;
				checker(i,j);
//				printMap();
			}
		}
	}

	return count;
}

void checker(int y, int x)
{
	int i,j;

	MAP[y][x]='.';
	for(i=-1; i<2; i++)
	{
		for(j=-1; j<2; j++)
		{
			if(y+i>=0 && y+i<N && x+j>=0 && x+j<M && MAP[i+y][j+x]=='w')
				checker(i+y, j+x);
		}
	}
	return;
}
