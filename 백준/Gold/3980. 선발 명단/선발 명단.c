#include<stdio.h>
#include<stdbool.h>

int s[11][11], max;
bool selected[11];

void simulate(int current,int total)
{
	if(current==11)
	{
		max=total<max?max:total;
		return;
	}

	for(int i=0;i<11;++i)
		if(s[current][i]&&!selected[i])
		{
			selected[i]=true;
			simulate(current+1,total+s[current][i]);
			selected[i]=false;
		}
}

int main(void)
{
	int C;

	scanf("%d", &C);

	while(C--)
	{
		for(int i=0;i<11;++i)
			for(int j=0;j<11;++j)
				scanf("%d", &s[i][j]);

		for(int i=0;i<11;++i)
			selected[i]=0;
		max=0;

		simulate(0,0);

		printf("%d\n", max);
	}

	return 0;
}