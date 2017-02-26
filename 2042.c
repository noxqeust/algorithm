#include <stdio.h>

#define SIZE 1000000

int arr[SIZE];
long long rmq[SIZE*4];

long long update(int index, int value, int node, int node_s, int node_e);
long long query(int node, int node_s, int node_e ,int start, int end);
long long init(int node, int start, int end);


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
			printf("%lld\n",query(1, 0, N-1, b-1, c-1));
	}
	return 0;
}

long long init(int node, int start, int end)
{
	int a=0,b=0;
	int mid;

	if(start==end)
	{
		return rmq[node]=arr[start];
	}
	mid=(start+end)/2;
    init(node*2, start, mid);
	init(node*2+1, mid+1, end);
    return rmq[node]=rmq[node*2]+rmq[node*2+1];
}

long long query(int node, int node_s, int node_e ,int start, int end)
{
	int mid;

	if(start > node_e || end < node_s)
		return 0;

	if(start<=node_s && end>=node_e)
		return rmq[node];

	mid=(node_s+node_e)/2;
	return query(node*2, node_s, mid, start, end)+query(node*2+1, mid+1, node_e, start, end);
}

long long update(int index, int value, int node, int node_s, int node_e)
{
	int mid;

	if(index<node_s || index>node_e)
		return rmq[node];

	if(node_s==node_e)
		return rmq[node]=value;

	mid=(node_s+node_e)/2;

	return rmq[node]=update(index, value, node*2, node_s, mid)+update(index, value, node*2+1, mid+1, node_e);
}
