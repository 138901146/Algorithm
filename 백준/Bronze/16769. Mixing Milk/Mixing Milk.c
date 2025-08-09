#include<stdio.h>

int main(void)
{
	int m[3], c[3], current=0, next=1;

	for(int i=0;i<3;++i)
		scanf("%d%d", &c[i], &m[i]);

	for(int i=0;i<100;++i)
	{
		if(m[current]+m[next]<=c[next])
		{
			m[next]+=m[current];
			m[current]=0;
		}
		else
		{
			m[current]-=c[next]-m[next];
			m[next]=c[next];
		}

		current=(current+1)%3;
		next=(next+1)%3;
	}

	for(int i=0;i<3;++i)
		printf("%d\n", m[i]);
	return 0;
}