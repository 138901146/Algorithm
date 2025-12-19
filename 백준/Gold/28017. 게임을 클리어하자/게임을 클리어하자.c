#include<stdio.h>

#define INF 123456789

int main(void)
{
	int N, M, t[500], ending[500][2]={0}, current=0, next=1, min=INF;

	scanf("%d%d", &N, &M);

	while(N--)
	{
		for(int i=0;i<M;++i)
			scanf("%d", &t[i]);

		for(int i=0;i<M;++i)
		{
			ending[i][next]=INF;
			for(int j=0;j<M;++j)
				if(i!=j)
					ending[i][next]=ending[j][current]<ending[i][next]?ending[j][current]:ending[i][next];
			ending[i][next]+=t[i];
		}

		current^=1;
		next^=1;
	}

	for(int i=0;i<M;++i)
		min=ending[i][current]<min?ending[i][current]:min;

	printf("%d", min);
	return 0;
}