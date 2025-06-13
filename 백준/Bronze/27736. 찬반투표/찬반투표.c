#include<stdio.h>

int main(void)
{
	int N, vote, result[3]={0};

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%d", &vote);
		++result[vote+1];
	}

	if(N<=(result[1]<<1))
		printf("INVALID");
	else if(result[0]<result[2])
		printf("APPROVED");
	else
		printf("REJECTED");

	return 0;
}