#include<stdio.h>

#define INF 9000000

int main(void)
{
	int N, min[1000], previous[80];
	char str[1001]={0};

	scanf("%d", &N);
	scanf("%s", str);

	min[0]=0;
	previous[66]=74;
	previous[79]=66;
	previous[74]=79;
	for(int i=1;i<N;++i)
	{
		int last=previous[str[i]];
		min[i]=INF;

		for(int j=0;j<i;++j)
			if(str[j]==last)
				min[i]=min[i]<min[j]+(i-j)*(i-j)?min[i]:min[j]+(i-j)*(i-j);
	}

	printf("%d", min[N-1]==INF?-1:min[N-1]);
	return 0;
}