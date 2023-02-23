#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, start[2], end[2], temp;
	bool started=false;

	scanf("%d %d", &N, &M);

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
		{
			scanf("%d", &temp);

			if(temp==1)
			{
				if(!started)
				{
					start[0]=n;
					start[1]=m;
					started=true;
				}
				else
				{
					end[0]=n;
					end[1]=m;
					break;
				}
			}
		}
	for(int i=0;i<2;i++)
	{
		end[i]-=start[i];
		end[i]=end[i]<0?-end[i]:end[i];
	}

	printf("%d\n", end[0]+end[1]);
	return 0;
}