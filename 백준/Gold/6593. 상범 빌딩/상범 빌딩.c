#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int L, R, C, dl[6]={-1,0,0,0,0,1}, dr[6]={0,-1,0,0,1,0}, dc[6]={0,0,-1,1,0,0};

	scanf("%d%d%d", &L, &R, &C);

	while(L||R||C)
	{
		int *queue=malloc(L*R*C*sizeof(int)), *escape=calloc(32768,sizeof(int)), front=0, rear=1, s, e;
		char ***building=malloc(L*sizeof(char **));

		for(int i=0;i<L;++i)
		{
			building[i]=(char **)malloc(R*sizeof(char *));

			for(int j=0;j<R;++j)
			{
				building[i][j]=(char *)calloc(C+1,sizeof(char));

				scanf("%s", building[i][j]);

				for(int k=0;k<C;++k)
					if(building[i][j][k]=='S')
						s=i<<10|j<<5|k;
					else if(building[i][j][k]=='E')
						e=i<<10|j<<5|k;
			}
		}

		escape[s]=1;
		queue[0]=s;

		while(front<rear&&!escape[e])
		{
			int l=queue[front]>>10, r=queue[front]>>5&31, c=queue[front]&31;

			for(int i=0;i<6;++i)
			{
				int next_l=l+dl[i], next_r=r+dr[i], next_c=c+dc[i], next=next_l<<10|next_r<<5|next_c;

				if(next_l<0||L<=next_l||next_r<0||R<=next_r||next_c<0||C<=next_c||building[next_l][next_r][next_c]=='#'||escape[next])
					continue;

				escape[next]=escape[queue[front]]+1;
				queue[rear++]=next;
			}

			++front;
		}

		if(escape[e])
			printf("Escaped in %d minute(s).\n", escape[e]-1);
		else
			printf("Trapped!\n");
		for(int i=0;i<L;++i)
		{
			for(int j=0;j<R;++j)
				free(building[i][j]);
			free(building[i]);
		}
		free(building);
		free(queue);
		free(escape);
		scanf("%d%d%d", &L, &R, &C);
	}

	return 0;
}