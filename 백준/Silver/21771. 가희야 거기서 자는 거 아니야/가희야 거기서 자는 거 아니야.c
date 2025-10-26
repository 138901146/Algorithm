#include<stdio.h>

int main(void)
{
	int R, C, Rg, Cg, Rp, Cp, leftmost=100, rightmost=0, topmost=100, bottommost=0;
	char room[100][101]={0};

	scanf("%d%d", &R, &C);
	scanf("%d%d%d%d", &Rg, &Cg, &Rp, &Cp);
	for(int r=0;r<R;++r)
		scanf("%s", room[r]);

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(room[r][c]=='P')
			{
				leftmost=c<leftmost?c:leftmost;
				rightmost=rightmost<c?c:rightmost;
				topmost=r<topmost?r:topmost;
				bottommost=bottommost<r?r:bottommost;
			}

	if(bottommost-topmost+1!=Rp||rightmost-leftmost+1!=Cp)
	{
		printf("1");
		return 0;
	}

	for(int r=topmost;r<=bottommost;++r)
		for(int c=leftmost;c<=rightmost;++c)
			if(room[r][c]=='G')
			{
				printf("1");
				return 0;
			}

	printf("0");
	return 0;
}