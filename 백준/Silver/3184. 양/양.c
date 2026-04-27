#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int R, C, **area=NULL, area_count=0, *queue=NULL, total_sheep=0, total_wolf=0, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	char **yard=NULL;

	scanf("%d%d", &R, &C);
	yard=(char **)malloc(R*sizeof(char *));
	area=(int **)malloc(R*sizeof(int *));
	queue=(int *)calloc(R*C,sizeof(int));

	for(int r=0;r<R;++r)
	{
		yard[r]=(char *)calloc(C+1,sizeof(char));
		area[r]=(int *)calloc(C,sizeof(int));
		scanf("%s", yard[r]);
	}

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(yard[r][c]!='#'&&!area[r][c])
			{
				int sheep=0, wolf=0, front=0, rear=1;

				area[r][c]=++area_count;
				sheep+=yard[r][c]=='o';
				wolf+=yard[r][c]=='v';
				queue[0]=r<<8|c;

				while(front<rear)
				{
					int cur_r=queue[front]>>8, cur_c=queue[front]&255;

					for(int i=0;i<4;++i)
					{
						int next_r=cur_r+dr[i], next_c=cur_c+dc[i];

						if(next_r<0 || R<=next_r || next_c<0 || C<=next_c || area[next_r][next_c] || yard[next_r][next_c]=='#')
							continue;

						area[next_r][next_c]=area_count;
						sheep+=yard[next_r][next_c]=='o';
						wolf+=yard[next_r][next_c]=='v';
						queue[rear++]=next_r<<8|next_c;
					}

					++front;
				}

				if(wolf<sheep)
					total_sheep+=sheep;
				else
					total_wolf+=wolf;
			}

	printf("%d %d", total_sheep, total_wolf);
	for(int r=0;r<R;++r)
	{
		free(yard[r]);
		free(area[r]);
	}
	free(yard);
	free(area);
	free(queue);
	return 0;
}