#include<stdio.h>

int main(void)
{
	int N, trophy[50], left=0, right=0;

	scanf("%d", &N);

	for(int i=0, max=0;i<N;++i)
	{
		scanf("%d", &trophy[i]);

		if(max<trophy[i])
		{
			max=trophy[i];
			++left;
		}
	}

	for(int i=N-1, max=0;0<=i;--i)
		if(max<trophy[i])
		{
			max=trophy[i];
			++right;
		}

	printf("%d\n%d", left, right);
	return 0;
}