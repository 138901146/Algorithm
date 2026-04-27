#include<stdio.h>

int main(void)
{
	int A[10], B[10], score[2]={0};

	for(int i=0;i<10;++i)
		scanf("%d", &A[i]);
	for(int i=0;i<10;++i)
		scanf("%d", &B[i]);

	for(int i=0;i<10;++i)
		if(A[i]<B[i])
			score[1]+=3;
		else if(B[i]<A[i])
			score[0]+=3;
		else
		{
			++score[0];
			++score[1];
		}

	printf("%d %d\n", score[0], score[1]);
	if(score[0]!=score[1])
	{
		printf("%c", 'A'+(score[0]<score[1]));
		return 0;
	}

	for(int i=9;0<=i;--i)
		if(A[i]!=B[i])
		{
			printf("%c", 'A'+(A[i]<B[i]));
			return 0;
		}

	printf("D");
	return 0;
}