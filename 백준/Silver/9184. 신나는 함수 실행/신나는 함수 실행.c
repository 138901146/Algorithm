#include<stdio.h>

int main(void)
{
	int w[21][21][21]={0, }, a, b, c;

	for(a=0;a<21;a++)
		for(b=0;b<21;b++)
			for(c=0;c<21;c++)
				if(a==0 || b==0 || c==0)
					w[a][b][c]=1;
				else if(a<b && b<c)
					w[a][b][c]=w[a][b][c-1]+w[a][b-1][c-1]-w[a][b-1][c];
				else
					w[a][b][c]=w[a-1][b][c]+w[a-1][b-1][c]+w[a-1][b][c-1]-w[a-1][b-1][c-1];

	scanf("%d %d %d", &a, &b, &c);

	while(a!=-1 || b!=-1 || c!=-1)
	{
		if(a<=0 || b<=0 || c<=0)
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
		else if(a>20 || b>20 || c>20)
			printf("w(%d, %d, %d) = %d\n", a, b, c, w[20][20][20]);
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);

		scanf("%d %d %d", &a, &b, &c);
	}

	return 0;
}