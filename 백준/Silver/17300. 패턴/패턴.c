#include<stdio.h>
#include<stdbool.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int L, A[9], r[10]={0,0,0,0,1,1,1,2,2,2}, c[10]={0,0,1,2,0,1,2,0,1,2}, location[3][3]={1,2,3,4,5,6,7,8,9};
	bool visited[10]={false};

	scanf("%d", &L);
	for(int i=0;i<L;++i)
		scanf("%d", &A[i]);

	visited[A[0]]=true;
	for(int i=1;i<L;++i)
	{
		if(visited[A[i]])
		{
			printf("NO");
			return 0;
		}

		int dr=r[A[i]]-r[A[i-1]], dc=c[A[i]]-c[A[i-1]];

		if(abs(dr)!=1&&abs(dc)!=1&&!visited[location[r[A[i]]-(dr>>1)][c[A[i]]-(dc>>1)]])
		{
			printf("NO");
			return 0;
		}

		visited[A[i]]=true;
	}

	printf("YES");
	return 0;
}