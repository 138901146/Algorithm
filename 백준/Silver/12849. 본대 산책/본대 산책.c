#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	int D, current=0, next=1, route[8][2]={1,0}, transit_count[8]={2,3,4,4,4,3,2,2}, transit[8][4]={{1,2},{0,2,3},{0,1,3,4},{1,2,4,5},{2,3,5,7},{3,4,6},{5,7},{4,6}};

	scanf("%d", &D);

	while(D--)
	{
		for(int i=0;i<8;++i)
			route[i][next]=0;

		for(int i=0;i<8;++i)
			for(int j=0;j<transit_count[i];++j)
				route[transit[i][j]][next]=(route[transit[i][j]][next]+route[i][current])%MOD;

		current^=1;
		next^=1;
	}

	printf("%d", route[0][current]);
	return 0;
}