#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int C, V, preference[100][100], vote[101]={0}, most[2]={0};

		scanf("%d%d", &C, &V);

		for(int v=0;v<V;++v)
		{
			for(int c=0;c<C;++c)
				scanf("%d", &preference[v][c]);
			++vote[preference[v][0]];
		}

		for(int c=1;c<=C;++c)
			if(vote[most[0]]<vote[c])
			{
				most[1]=most[0];
				most[0]=c;
			}
			else if(vote[most[1]]<vote[c])
				most[1]=c;

		if(V<=vote[most[0]]<<1)
		{
			printf("%d 1\n", most[0]);
			continue;
		}

		vote[most[0]]=vote[most[1]]=0;
		for(int v=0;v<V;++v)
			for(int c=0;c<C;++c)
				if(preference[v][c]==most[0]||preference[v][c]==most[1])
				{
					++vote[preference[v][c]];
					break;
				}

		printf("%d 2\n", vote[most[0]]<vote[most[1]]?most[1]:most[0]);
	}

	return 0;
}