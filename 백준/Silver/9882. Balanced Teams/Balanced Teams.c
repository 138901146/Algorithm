#include<stdio.h>

int selected[12], skill[12], best=99999999;

void simulate(int current)
{
	int done=1;

	if(current==9)
	{
		int count=9, sum[4]={0}, max=0, min=99999999;

		for(int i=1;i<9;++i)
			done|=1<<selected[i];
		for(int i=1;i<12;++i)
			if(!(done&(1<<i)))
				selected[count++]=i;

		for(int i=0;i<12;++i)
			sum[i/3]+=skill[selected[i]];
		for(int i=0;i<4;++i)
		{
			max=sum[i]<max?max:sum[i];
			min=sum[i]<min?sum[i]:min;
		}

		best=max-min<best?max-min:best;
		return;
	}

	for(int i=1;i<current;++i)
		done|=1<<selected[i];
	for(int i=current%3?selected[current-1]+1:1;i<12;++i)
		if(!(done&(1<<i)))
		{
			selected[current]=i;
			simulate(current+1);
		}
}

int main(void)
{
	for(int i=0;i<12;++i)
		scanf("%d", &skill[i]);

	selected[0]=0;
	simulate(1);

	printf("%d", best);
	return 0;
}