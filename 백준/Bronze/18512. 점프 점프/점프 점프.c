#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int X, Y, P1, P2;
	bool solved=false;

	scanf("%d %d %d %d", &X, &Y, &P1, &P2);

	for(int i=0;i<=100;i++)
	{
		int K=i*X+P1;
		for(int j=0;j<=100;j++)
			if(K==(j*Y+P2))
			{
				solved=true;
				printf("%d\n", K);
				break;
			}
		if(solved)
			break;
	}

	if(!solved)
		printf("-1\n");

	return 0;
}