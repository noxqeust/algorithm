#include <stdio.h>

#define SIZE 98765432 

int number[8];
int number2[8];
char visited[SIZE];

int queue[SIZE];
int head;
int tail;

int ans;
int change(int *arr, int n, int a, int k);
int atoi(int *number, int n);
void itoa(int temp, int n, int *arr);
int sorting(int n);

int main(void)
{
	int i,j,N, K, temp, sort,find;

	scanf("%d %d", &N, &K);

	for(i=0; i<N; i++)
	{
		scanf("%d", &number[i]);
		number2[i]=number[i];
	}
	sort=sorting(N);
	temp=atoi(number, N);

	queue[tail++]=temp;
	visited[temp]=1;
	ans=0;
	find=0;
	while(head!=tail)
	{
		temp=queue[head++];
		itoa(temp, N, number);
		if(temp==sort)
		{
			printf("%d\n",ans);
			find=1;
			break;
		}

		for(i=0; i<N; i++)
		{
			if(i+(K-1)<N)
			{
				for(j=0; j<N; j++)
					number2[j]=number[j];
				
				temp=change(number2,N, i, K);
				if(visited[temp]==0)
				{
					visited[temp]=1;
					queue[tail++]=temp;
				}
			}
			else
				break;
		}
		ans++;
	}
	if(find==0)
		printf("-1\n");
	return 0;
}

int change(int *arr, int n, int a, int k)
{
	int i,j,temp;
	j=a+k-1;
	for(i=0; i<k/2; i++, j--)
	{
		temp=arr[a];
		arr[a++]=arr[j];
		arr[j--]=temp;	
	}
	return temp=atoi(arr,n);
}

int atoi(int *number, int n)
{
	int i,temp;

	temp=number[0];
	for(i=1; i<n; i++)
	{
		temp*=10;
		temp+=number[i];
	}
	return temp;
}

void itoa(int temp, int n, int *arr)
{
	int i;
	for(i=n-1; i>=0; i--)
	{
		arr[i]=temp%10;
		temp/=10;	
	}
}

int sorting(int n)
{
	switch(n)
	{
		case 2:
			return 12;
		case 3:
			return 123;
		case 4:
			return 1234;
		case 5:
			return 12345;
		case 6:
			return 123456;
		case 7:
			return 1234567;
		case 8:
			return 12345678;
		default:
			return 0;
	}

}
