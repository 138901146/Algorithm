#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int N, **domino=NULL, *domino_count=NULL, *parent=NULL, *stack=NULL, top, *group=NULL, id, num;
bool *found=NULL, *reachable=NULL;

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int DFS(int x)
{
	parent[x]=++id;
	stack[top++]=x;

	int p=parent[x];

	for(int i=0;i<domino_count[x];i++)
	{
		int y=domino[x][i];

		if(!parent[y])
		{
			int next=DFS(y);
			p=p<next?p:next;
		}
		else if(!found[y])
			p=p<parent[y]?p:parent[y];
	}

	if(p==parent[x])
	{
		int count=0;

		while(x)
		{
			int y=stack[--top];
			group[y]=num;
			found[y]=true;

			if(x==y)
				break;
		}

		num++;
	}

	return p;
}

int main(void)
{
	int T, M, fall, **relation=NULL;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		relation=(int **)malloc(M*sizeof(int *));
		domino_count=(int *)calloc(N+1,sizeof(int));
		domino=(int **)malloc((N+1)*sizeof(int *));
		group=(int *)malloc((N+1)*sizeof(int));

		for(int m=0;m<M;m++)
		{
			relation[m]=(int *)malloc(2*sizeof(int));
			scanf("%d%d", &relation[m][0], &relation[m][1]);
			domino_count[relation[m][0]]++;
		}

		for(int n=1;n<=N;n++)
		{
			domino[n]=(int *)malloc(domino_count[n]*sizeof(int));
			domino_count[n]=0;
		}

		for(int m=0;m<M;m++)
			domino[relation[m][0]][domino_count[relation[m][0]]++]=relation[m][1];

		found=(bool *)calloc(N+1,sizeof(bool));
		parent=(int *)calloc(N+1,sizeof(int));
		stack=(int *)malloc((N+1)*sizeof(int));
		for(int n=1;n<=N;n++)
			qsort((void *)domino[n],(size_t)domino_count[n],sizeof(int),compare);

		fall=id=num=top=0;
		for(int n=1;n<=N;n++)
			if(!parent[n])
				DFS(n);

		reachable=(bool *)calloc(num,sizeof(bool));
		for(int m=0;m<M;m++)
		{
			if(group[relation[m][0]]!=group[relation[m][1]])
				reachable[group[relation[m][1]]]=true;
			free(relation[m]);
		}

		for(int i=0;i<num;i++)
			fall+=!reachable[i];
		printf("%d\n", fall==0?1:fall);

		for(int n=1;n<=N;n++)
			free(domino[n]);
		free(relation);
		free(domino);
		free(stack);
		free(parent);
		free(domino_count);
		free(found);
		free(group);
		free(reachable);
	}

	return 0;
}