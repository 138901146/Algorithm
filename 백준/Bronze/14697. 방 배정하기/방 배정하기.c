#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int A, B, C, N;
	bool solved=false;

	scanf("%d %d %d %d", &A, &B, &C, &N);

	for(int c=0;c<=N;c+=C)
	{
		for(int b=0;b+c<=N;b+=B)
			if((N-b-c)%A==0)
			{
				solved=true;
				break;
			}
		if(solved)
			break;
	}

    printf("%d\n", solved);
    return 0;
}