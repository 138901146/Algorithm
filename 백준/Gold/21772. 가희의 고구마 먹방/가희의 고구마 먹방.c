#include<stdio.h>

int R, C, T, max=0, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
char map[100][100];

void sweet_potato(int r,int c,int t,int eaten)
{
	if(T<t)
		return;

	max=eaten<max?max:eaten;

	for(int i=0;i<4;++i)
	{
		int next_r=r+dr[i], next_c=c+dc[i];

		if(next_r<0||R<=next_r||next_c<0||C<=next_c||map[next_r][next_c]=='#')
			continue;

		if(map[next_r][next_c]=='S')
		{
			map[next_r][next_c]='.';
			sweet_potato(next_r,next_c,t+1,eaten+1);
			map[next_r][next_c]='S';
		}
		else
			sweet_potato(next_r,next_c,t+1,eaten);
	}
}

int main(void)
{
	scanf("%d%d%d", &R, &C, &T);

	for(int r=0;r<R;++r)
		scanf("%s", map[r]);

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(map[r][c]=='G')
				sweet_potato(r,c,0,0);

	printf("%d", max);
	return 0;
}