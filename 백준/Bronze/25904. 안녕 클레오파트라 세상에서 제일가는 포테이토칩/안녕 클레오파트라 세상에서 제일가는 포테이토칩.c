#include<stdio.h>

int main(void)
{
	int N, X, T[100], index=0;

	scanf("%d%d", &N, &X);
	for(int i=0;i<N;++i)
		scanf("%d", &T[i]);

	while(1)
	{
		if(T[index]<X)
		{
			printf("%d", index+1);
			return 0;
		}
		++X;
		index=(index+1)%N;
	}

	return 0;
}