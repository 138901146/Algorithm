#include<stdio.h>

#define MOD 100000

int main(void)
{
	int w, h, map[100][100][4]={0};

	scanf("%d%d", &w, &h);

	--w;
	--h;
	for(int i=0;i<=w;++i)
		map[i][0][0]=1;
	for(int j=0;j<=h;++j)
		map[0][j][1]=1;

	for(int j=1;j<=h;++j)
		for(int i=1;i<=w;++i)
		{
			map[i][j][0]=(map[i-1][j][0]+map[i-1][j][2])%MOD;
			map[i][j][1]=(map[i][j-1][1]+map[i][j-1][3])%MOD;
			map[i][j][2]=map[i-1][j][1];
			map[i][j][3]=map[i][j-1][0];
		}

	printf("%d", (map[w][h][0]+map[w][h][1]+map[w][h][2]+map[w][h][3])%MOD);
	return 0;
}