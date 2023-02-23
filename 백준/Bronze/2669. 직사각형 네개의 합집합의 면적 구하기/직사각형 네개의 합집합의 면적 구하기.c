#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	bool plane[101][101]={false, };
	int coordinate[4][4], area=0;

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d", &coordinate[i][j]);

	for(int i=0;i<4;i++)
		for(int x=coordinate[i][0];x<coordinate[i][2];x++)
			for(int y=coordinate[i][1];y<coordinate[i][3];y++)
				plane[x][y]=true;

	for(int x=1;x<101;x++)
		for(int y=1;y<101;y++)
			area+=plane[x][y];

	printf("%d\n", area);
	return 0;
}