#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, red_r, red_c, red[2], blue_r, blue_c, blue[2], state_r, state_c, moved=0, front=0, rear=0, queue[65536];
	char map[10][11]={'\0', };
	bool visited[65536]={false, }, found=false;

	scanf("%d%d", &N, &M);
	for(int n=0;n<N;n++)
	{
		getchar();
		scanf("%s", map[n]);

		for(int m=1;m<M;m++)
			if(map[n][m]=='R')
			{
				red_r=n;
				red_c=m;
				map[n][m]='.';
			}
			else if(map[n][m]=='B')
			{
				blue_r=n;
				blue_c=m;
				map[n][m]='.';
			}
	}

	queue[rear++]=red_r<<12|red_c<<8|blue_r<<4|blue_c;

	while(front<rear && !found)
	{
		int previous_rear=rear;

		while(front<previous_rear && !found)
		{
			blue_c=queue[front]&15;
			queue[front]>>=4;
			blue_r=queue[front]&15;
			queue[front]>>=4;
			red_c=queue[front]&15;
			red_r=queue[front]>>4;

			state_r=red_r<blue_r;
			state_c=red_c<blue_c;

			if(state_r)
			{
				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				
				while(map[red[0]][red[1]]=='.')
					red[0]--;
				if(map[red[0]][red[1]]=='O')
					found=true;
				else
					map[++red[0]][red[1]]='R';

				while(map[blue[0]][blue[1]]=='.')
					blue[0]--;
				if(map[blue[0]][blue[1]]=='O')
				{
					if(!found)
						map[red[0]][red[1]]='.';
					found=false;
				}
				else
				{
					map[red[0]][red[1]]='.';
					blue[0]++;
					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					
				}
				visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;

				if(found)
					break;

				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[blue[0]][blue[1]]=='.')
					blue[0]++;
				if(map[blue[0]][blue[1]]!='O')
				{
					map[--blue[0]][blue[1]]='B';

					while(map[red[0]][red[1]]=='.')
						red[0]++;
					if(map[red[0]][red[1]]=='O')
					{
						found=true;
						break;
					}
					red[0]--;
					map[blue[0]][blue[1]]='.';

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					}
				}
			}
			else
			{
				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[blue[0]][blue[1]]=='.')
					blue[0]--;
				if(map[blue[0]][blue[1]]!='O')
				{
					map[++blue[0]][blue[1]]='B';

					while(map[red[0]][red[1]]=='.')
						red[0]--;
					if(map[red[0]][red[1]]=='O')
					{
						found=true;
						break;
					}
					red[0]++;

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					}
					map[blue[0]][blue[1]]='.';
				}

				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[red[0]][red[1]]=='.')
					red[0]++;
				if(map[red[0]][red[1]]=='O')
					found=true;
				else
					map[--red[0]][red[1]]='R';
				while(map[blue[0]][blue[1]]=='.')
					blue[0]++;
				if(map[blue[0]][blue[1]]=='O')
				{
					if(!found)
						map[red[0]][red[1]]='.';
					found=false;
				}
				else
				{
					blue[0]--;

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
					}
					if(!found)
						map[red[0]][red[1]]='.';
				}
			}
			if(state_c)
			{
				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				
				while(map[red[0]][red[1]]=='.')
					red[1]--;
				if(map[red[0]][red[1]]=='O')
					found=true;
				else
					map[red[0]][++red[1]]='R';

				while(map[blue[0]][blue[1]]=='.')
					blue[1]--;
				if(map[blue[0]][blue[1]]=='O')
				{
					if(!found)
						map[red[0]][red[1]]='.';
					found=false;
				}
				else
				{
					map[red[0]][red[1]]='.';
					blue[1]++;
					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					
				}
				visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;

				if(found)
					break;

				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[blue[0]][blue[1]]=='.')
					blue[1]++;
				if(map[blue[0]][blue[1]]!='O')
				{
					map[blue[0]][--blue[1]]='B';

					while(map[red[0]][red[1]]=='.')
						red[1]++;
					if(map[red[0]][red[1]]=='O')
					{
						found=true;
						break;
					}
					red[1]--;
					map[blue[0]][blue[1]]='.';

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					}
				}
			}
			else
			{
				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[blue[0]][blue[1]]=='.')
					blue[1]--;
				if(map[blue[0]][blue[1]]!='O')
				{
					map[blue[0]][++blue[1]]='B';

					while(map[red[0]][red[1]]=='.')
						red[1]--;
					if(map[red[0]][red[1]]=='O')
					{
						found=true;
						break;
					}
					red[1]++;

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
					}
					map[blue[0]][blue[1]]='.';
				}

				red[0]=red_r;
				red[1]=red_c;
				blue[0]=blue_r;
				blue[1]=blue_c;

				while(map[red[0]][red[1]]=='.')
					red[1]++;
				if(map[red[0]][red[1]]=='O')
					found=true;
				else
					map[red[0]][--red[1]]='R';
				while(map[blue[0]][blue[1]]=='.')
					blue[1]++;
				if(map[blue[0]][blue[1]]=='O')
				{
					if(!found)
						map[red[0]][red[1]]='.';
					found=false;
				}
				else
				{
					blue[1]--;

					if(!visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]])
					{
						queue[rear++]=red[0]<<12|red[1]<<8|blue[0]<<4|blue[1];
						visited[red[0]<<12|red[1]<<8|blue[0]<<4|blue[1]]=true;
					}
					if(!found)
						map[red[0]][red[1]]='.';
				}
			}

			front++;
		}

		moved++;
	}

	printf("%d\n", found?moved:-1);

	return 0;
}