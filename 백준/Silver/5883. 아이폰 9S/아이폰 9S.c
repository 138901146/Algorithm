#include<stdio.h>
#include<stdbool.h>

bool viewed[1000001]={false};

int main(void)
{
	int N, B[1000], max=1;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d", &B[i]);

	for(int i=0;i<N;++i)
	{
		if(viewed[B[i]])
			continue;

		int last=B[0], count=1;
		viewed[B[i]]=true;

		for(int j=1;j<N;++j)
			if(B[i]==B[j])
				continue;
			else if(B[j]==last)
			{
				++count;
				max=count<max?max:count;
			}
			else
			{
				count=1;
				last=B[j];
			}
	}

	printf("%d", max);
	return 0;
}