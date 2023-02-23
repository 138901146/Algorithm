#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int DA[31]={0,1,0,1,1,}, DB[31]={0,0,1,1,2,}, D, K;
	bool solved=false;

	scanf("%d %d", &D, &K);

	for(int d=5;d<=D;d++)
	{
		DA[d]=DA[d-1]+DA[d-2];
		DB[d]=DB[d-1]+DB[d-2];
	}

	for(int A=1;2*A*DA[D]<=K;A++)
	{
		for(int B=A;A*DA[D]+B*DB[D]<=K;B++)
			if(A*DA[D]+B*DB[D]==K)
			{
				printf("%d\n%d\n", A, B);
				solved=true;
				break;
			}
		if(solved)
			break;
	}

	return 0;
}