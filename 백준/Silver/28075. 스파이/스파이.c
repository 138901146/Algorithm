#include<stdio.h>

int N, M, collect[3], monitor[3], count=0;

void simulate(int day,int contribute,int last)
{
	if(day==N)
	{
		count+=M<=contribute;
		return;
	}

	for(int i=0;i<3;++i)
		if(i==last)
		{
			simulate(day+1,contribute+(collect[i]>>1),i);
			simulate(day+1,contribute+(monitor[i]>>1),i);
		}
		else
		{
			simulate(day+1,contribute+collect[i],i);
			simulate(day+1,contribute+monitor[i],i);
		}
}

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<3;++i)
		scanf("%d", &collect[i]);
	for(int i=0;i<3;++i)
		scanf("%d", &monitor[i]);

	simulate(0,0,-1);

	printf("%d", count);
	return 0;
}