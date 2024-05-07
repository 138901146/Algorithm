#include<stdio.h>
#include<stdbool.h>

int max=0;
bool put[50]={false};

int abs(int x)
{
	return x<0?-x:x;
}

void simulate(int current,int count,int *list,int total)
{
	if(current==total)
	{
		max=count<max?max:count;
		return;
	}

	int r=list[current]>>4, c=list[current]&15;
	bool able=true;

	for(int i=0;i<current;++i)
		if(put[i] && abs(r-(list[i]>>4))==abs(c-(list[i]&15)))
		{
			able=false;
			break;
		}

	if(able)
	{
		put[current]=true;
		simulate(current+1,count+1,list,total);
		put[current]=false;
	}

	simulate(current+1,count,list,total);
}

int main(void)
{
	int size, bishop, odd[50], even[50], odd_total=0, even_total=0, odd_max;

	scanf("%d", &size);

	for(int i=0;i<size;++i)
		for(int j=0;j<size;++j)
		{
			scanf("%d", &bishop);

			if(bishop)
			{
				if(i+j&1)
					odd[odd_total++]=i<<4|j;
				else
					even[even_total++]=i<<4|j;
			}
		}

	simulate(0,0,odd,odd_total);
	odd_max=max;

	max=0;
	simulate(0,0,even,even_total);

	printf("%d", odd_max+max);
	return 0;
}