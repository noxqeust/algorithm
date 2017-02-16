#include <stdio.h>

#define SIZE 100000

int arr[SIZE];
int rmq[SIZE*4];

int update(int index, int value, int node, int node_s, int node_e);
int query(int node, int node_s, int node_e ,int start, int end);
int init(int node, int start, int end);

void printTree(int n)
{
	int i;
	for(i=1; i<16; i++)
		printf("%d ", rmq[i]);
	printf("\n");
}

int main(void)
{
	int a,b,c,i;
	int N,M,K;	
	
	scanf("%d %d %d", &N, &M, &K);
	
	for(i=0; i<N; i++)
		scanf("%d", &arr[i]);

	init(1, 0, N-1);

	for(i=0; i<K+M; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a==1)
			update(b-1,c,1,0,N-1);
		else
			printf("%d\n",query(1, 0, N-1, b-1, c-1));
	}
	return 0;
}

int init(int node, int start, int end)
{
	int a=0,b=0;
	int mid;
	printf("start=%d end=%d value=%d node=%d\n",start, end, arr[end],node);

	if(start==end)
	{
		return rmq[node]=arr[start];
	}
	mid=(start+end)/2;
	a=init(node*2, start, mid);
	b=init(node*2+1, mid+1, end);
	return rmq[node]=a+b;
}

int query(int node, int node_s, int node_e ,int start, int end)
{
	int mid;

	if(start > node_e || end < node_s)
		return 0;

	if(start<=node_s && end>=node_e)
		return rmq[node];

	mid=(node_s+node_e)/2;
	return query(node*2, node_s, mid, start, end)+query(node*2+1, mid+1, node_e, start, end);
}

int update(int index, int value, int node, int node_s, int node_e)
{
	int mid;

	if(index<node_s || index>node_e)
		return rmq[node];

	if(node_s==node_e)
		return rmq[node]=value;

	mid=(node_s+node_e)/2;

	return rmq[node]=update(index, value, node*2, node_s, mid)+update(index, value, node*2+1, mid+1, node_e);
}
