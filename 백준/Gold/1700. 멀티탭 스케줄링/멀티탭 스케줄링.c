#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, K, next[101][100]={0, }, count[101]={0, }, queue[100], on=0, off=0, using[100];
	bool plugged[101]={false, };

	scanf("%d%d", &N, &K);

	for(int k=0;k<K;++k)
	{
		scanf("%d", &queue[k]);
		next[queue[k]][count[queue[k]]++]=k;
	}

	for(int k=1;k<=K;++k)
		count[k]=0;

	for(int k=0;k<K;++k)
	{
		++count[queue[k]];
		if(plugged[queue[k]])
			continue;
		else if(on<N)
		{
			using[on++]=queue[k];
			plugged[queue[k]]=true;
		}
		else
		{
			int index=0;

			for(int n=0;n<N;++n)
				if(next[using[n]][count[using[n]]]==0)
				{
					index=n;
					break;
				}
				else if(next[using[n]][count[using[n]]]>next[using[index]][count[using[index]]])
					index=n;

			plugged[using[index]]=false;
			using[index]=queue[k];
			plugged[queue[k]]=true;

			++off;
		}
	}

	printf("%d", off);
	return 0;
}