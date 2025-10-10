#include<stdio.h>
#include<stdbool.h>

int child[26][25], child_count[26]={0};
bool drug[26]={false}, blocked[26]={false};

void spread(int current)
{
	for(int i=0;i<child_count[current];++i)
	{
		int next=child[current][i];

		if(!blocked[next])
		{
			drug[next]=true;
			spread(next);
		}
	}
}

int main(void)
{
	int N, M, parent_count[26]={0}, arrested, count=0;
	char from, to;

	scanf("%d%d", &N, &M);
	getchar();
	while(M--)
	{
		scanf("%c %c", &from, &to);
		getchar();

		from-='A';
		to-='A';

		++parent_count[to];
		child[from][child_count[from]++]=to;
	}

	scanf("%d", &arrested);
	getchar();
	while(arrested--)
	{
		scanf("%c", &to);
		getchar();
		blocked[to-'A']=true;
	}

	for(int n=0;n<N;++n)
		if(child_count[n]&&!parent_count[n]&&!blocked[n])
			spread(n);

	while(N--)
		count+=drug[N];

	printf("%d", count);
	return 0;
}