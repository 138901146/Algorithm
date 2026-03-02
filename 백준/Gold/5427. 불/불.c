#include<stdio.h>
#include<malloc.h>

#define INF 123456789

int main(void)
{
	int test_case, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};

	scanf("%d", &test_case);

	while(test_case--)
	{
		int w, h, **fire=NULL, **sg=NULL, *fire_queue=NULL, *sg_queue=NULL, fire_front=0, fire_rear=0, sg_front=0, sg_rear=1, escape=-1, r, c;
		char **map=NULL;

		scanf("%d%d", &w, &h);

		map=(char **)malloc(h*sizeof(char *));

		for(r=0;r<h;++r)
		{
			map[r]=(char *)calloc(w+1,sizeof(char));
			scanf("%s", map[r]);
		}

		fire=(int **)malloc(h*sizeof(int *));
		sg=(int **)malloc(h*sizeof(int *));
		fire_queue=(int *)malloc(w*h*sizeof(int));
		sg_queue=(int *)malloc(w*h*sizeof(int));

		for(r=0;r<h;++r)
		{
			fire[r]=(int *)malloc(w*sizeof(int));
			sg[r]=(int *)malloc(w*sizeof(int));

			for(c=0;c<w;++c)
			{
				fire[r][c]=INF;
				sg[r][c]=INF;

				if(map[r][c]=='*')
				{
					fire[r][c]=0;
					fire_queue[fire_rear++]=r<<10|c;
				}
				else if(map[r][c]=='@')
				{
					sg[r][c]=0;
					sg_queue[0]=r<<10|c;
				}
			}
		}

		r=sg_queue[0]>>10;
		c=sg_queue[0]&1023;

		if(r==0||r==h-1||c==0||c==w-1)
		{
			printf("1\n");
			for(r=0;r<h;++r)
			{
				free(map[r]);
				free(fire[r]);
				free(sg[r]);
			}
			free(map);
			free(fire);
			free(sg);
			free(fire_queue);
			free(sg_queue);
			continue;
		}

		while(sg_front<sg_rear&&escape==-1)
		{
			int current_rear=fire_rear;

			while(fire_front<current_rear)
			{
				r=fire_queue[fire_front]>>10;
				c=fire_queue[fire_front]&1023;

				for(int i=0;i<4;++i)
				{
					int next_r=r+dr[i], next_c=c+dc[i];

					if(next_r<0||h<=next_r||next_c<0||w<=next_c||map[next_r][next_c]=='#'||fire[next_r][next_c]!=INF)
						continue;

					fire[next_r][next_c]=fire[r][c]+1;
					fire_queue[fire_rear++]=next_r<<10|next_c;
				}

				++fire_front;
			}

			current_rear=sg_rear;

			while(sg_front<current_rear&&escape==-1)
			{
				r=sg_queue[sg_front]>>10;
				c=sg_queue[sg_front]&1023;

				for(int i=0;i<4;++i)
				{
					int next_r=r+dr[i], next_c=c+dc[i];

					if(next_r<0||h<=next_r||next_c<0||w<=next_c||map[next_r][next_c]=='#'||fire[next_r][next_c]!=INF||sg[next_r][next_c]!=INF)
						continue;
					else if(next_r==0||next_r==h-1||next_c==0||next_c==w-1)
					{
						escape=sg[r][c]+2;
						break;
					}

					sg[next_r][next_c]=sg[r][c]+1;
					sg_queue[sg_rear++]=next_r<<10|next_c;
				}

				++sg_front;
			}
		}

		if(escape==-1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", escape);

		for(r=0;r<h;++r)
		{
			free(map[r]);
			free(fire[r]);
			free(sg[r]);
		}
		free(map);
		free(fire);
		free(sg);
		free(fire_queue);
		free(sg_queue);
	}

	return 0;
}