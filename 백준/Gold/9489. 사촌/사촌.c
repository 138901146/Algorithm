#include<stdio.h>

int main(void)
{
	int n, k;

	scanf("%d%d", &n, &k);

	while(n || k)
	{
		int node[1001], child_count[1001]={0}, current_parent=0, depth[1001]={0}, index, parent[1001]={0}, cousin=0;

		scanf("%d", &node[1]);
		for(int i=2;i<=n;++i)
		{
			scanf("%d", &node[i]);

			if(node[i]==k)
				index=i;

			if(node[i]-node[i-1]!=1)
				++current_parent;
			parent[i]=current_parent;
			++child_count[current_parent];
			depth[i]=depth[current_parent]+1;
		}

		for(int i=2;i<=n;++i)
			if(i!=parent[index] && parent[i]==parent[parent[index]])
				cousin+=child_count[i];
			else if(depth[index]<=depth[i])
				break;

		printf("%d\n", cousin);
		scanf("%d%d", &n, &k);
	}

	return 0;
}