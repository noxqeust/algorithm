#include <stdio.h>

#define SIZE 1000001

int fail[SIZE];
char pattern[SIZE];

int kmp(const char *str, int len)
{
	int i,j,max;
	
	for(i=1,j=0; i<len; i++)
	{
		while(j>0&&str[i]!=str[j])
			j=fail[j-1];
		if(str[i]==str[j])
		{
			fail[i]=++j;
		}
	}

	return fail[len-1];
}

int main(void)
{
	int i,N, len, max;
	max=0;

	scanf("%d", &N);
	getchar();
	gets(pattern);
	
	max=kmp(pattern, N);
	
	printf("%d\n", N-max);

	return 0;
}
