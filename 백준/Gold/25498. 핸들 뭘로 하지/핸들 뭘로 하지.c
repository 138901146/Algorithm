#include<stdio.h>
#include<malloc.h>

int **adjacent_list=NULL, *adjacent_list_count=NULL, *parent=NULL, max_depth=0, done=0;
char *str=NULL, *handle=NULL;

void make_tree(int current,int depth)
{
	max_depth=depth<max_depth?max_depth:depth;

	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(parent[current]!=next)
		{
			parent[next]=current;
			make_tree(next,depth+1);
		}
	}
}

void make_handle(int current,int depth)
{
	int count=0;
	char best=0;

	done=depth<done?done:depth;

	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(parent[current]==next)
			continue;

		if(best<str[next])
		{
			best=str[next];
			count=1;
		}
		else if(best==str[next])
			++count;
	}

	if(handle[depth]<best)
		for(int i=depth;i<=done;++i)
			handle[i]=0;
	else if(best<handle[depth])
		return;
	handle[depth]=best;

	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(parent[current]==next)
			continue;

		if(best==str[next])
			make_handle(next,depth+1);
	}
}

int main(void)
{
	int N, *u=NULL, *v=NULL, size=0, current=1, next, selected;

	scanf("%d", &N);
	str=(char *)calloc(N+2,sizeof(char));
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	u=(int *)malloc((N-1)*sizeof(int));
	v=(int *)malloc((N-1)*sizeof(int));
	scanf("%s", str+1);

	for(int i=0;i<N-1;++i)
	{
		scanf("%d%d", &u[i], &v[i]);
		++adjacent_list_count[u[i]];
		++adjacent_list_count[v[i]];
	}

	for(int i=1;i<=N;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		adjacent_list[u[i]][adjacent_list_count[u[i]]++]=v[i];
		adjacent_list[v[i]][adjacent_list_count[v[i]]++]=u[i];
	}

	free(u);
	free(v);
	parent=(int *)calloc(N+1,sizeof(int));

	make_tree(1,1);
	handle=(char *)calloc(max_depth+1,sizeof(char));

	handle[0]=str[1];
	make_handle(1,1);

	printf("%s", handle);
	for(int i=1;i<=N;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(parent);
	free(str);
	free(handle);
	return 0;
}