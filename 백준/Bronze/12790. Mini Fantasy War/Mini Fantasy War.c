#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int ability[2][4];

		for(int i=0;i<2;i++)
			for(int j=0;j<4;j++)
				scanf("%d", &ability[i][j]);

		for(int i=0;i<4;i++)
		{
			ability[0][i]+=ability[1][i];

			if(i<2)
				ability[0][i]=ability[0][i]<1?1:ability[0][i];
			else if(i==2)
				ability[0][i]=ability[0][i]<0?0:ability[0][i];
		}

		printf("%d\n", ability[0][0]+5*ability[0][1]+2*(ability[0][2]+ability[0][3]));
	}

	return 0;
}