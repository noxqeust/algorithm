#include <stdio.h>

#define 167777216;

int N, int password, int state;

int head;
int tail;
int queue[SIZE];

int visit[20];

int main(void)
{
	int i,end,pick,find,count;

	find=0;
	count=0;

	scanf("%d", &N);
	scanf("%d", &state);
	scanf("%d", &password);

	queue[tail++]=state;
	while(tail!=head)
	{
		for(i=head, end=tail; i<end; i++)
		{
			pick=queue[head++];
			if(pick==password)
			{
				find=1;
				break;
			}


		}
		if(find==1)
		{
			printf("%d\n", count);
		}
		
		count++;
	}	

	return 0;
}
