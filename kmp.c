#include <stdio.h>

#define SIZE 1000001

int fail[SIZE];
int idx[SIZE];
char str1[SIZE];
char str2[SIZE];

int N;

int strlen1(const char* str)
{
	int i=0;
	while(str[i]!='\0')
		i++;

	return i;
}

void kmp(const char* pattern, int len)
{
	int i,j;

	for(i=1,j=0; i<len; i++)
	{
		while(j>0 && pattern[i]!=pattern[j])
			j=fail[j-1];
			
		if(pattern[i]==pattern[j])
			fail[i]=++j;

	}
}

int main(void)
{
	int j,i, answer, N,M;

	answer=0;
	gets(str1);
	gets(str2);
	kmp(str2, strlen1(str2));

	N=strlen1(str1);
	M=strlen1(str2);


	answer=0;
	for(i=0,j=0; i<N; i++)
	{
		while(j>0 && str1[i]!=str2[j])
			j=fail[j-1];
		
		if(str1[i]==str2[j])
			j++;

		if(j==M)
		{
			idx[answer]=i-j+2;
			answer++;
			j=fail[j-1];
		}
	}

	printf("%d\n", answer);
	for(i=0; i<answer; i++)
		printf("%d\n", idx[i]);

	return 0;
}
