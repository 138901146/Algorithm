#include<stdio.h>

int main(void)
{
	int N, remember[10]={10, }, order[10]={0, };

	scanf("%d", &N);

	for(int n=0;n<N;n++)
		scanf("%d", &remember[n]);

	order[remember[0]]=1;
	for(int n=1;n<N;n++)
		for(int i=0;i<N;i++)
			if(!order[i])
			{
				int count=0;
				for(int j=0;j<i;j++)
					count+=!order[j]||order[j]>n;

				if(count==remember[n])
					order[i]=n+1;
			}

	for(int n=0;n<N;n++)
		printf("%d ", order[n]);
	printf("\n");
	return 0;
}