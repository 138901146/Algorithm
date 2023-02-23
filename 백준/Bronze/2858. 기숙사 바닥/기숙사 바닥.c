#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int L, W, R, B;

	scanf("%d %d", &R, &B);

	for(L=1;;L++)
	{
		bool solved=false;

		for(W=1;W<=L && L*W<=R+B;W++)
			if(2*(L+W-2)==R && L*W-R==B)
			{
				solved=true;
				break;
			}

		if(solved)
			break;
	}

	printf("%d %d\n", L, W);
	return 0;
}