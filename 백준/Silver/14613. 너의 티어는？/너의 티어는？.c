#include<stdio.h>
#include<memory.h>

int main(void)
{
	int current=0, next=1;
	double W, L, D, percent[2][61]={0}, result;

	scanf("%lf%lf%lf", &W, &L, &D);
	percent[0][40]=1;

	for(int i=0;i<20;++i,current^=1,next^=1)
	{
		memset(percent[next],0,61*sizeof(double));

		for(int j=20;j<60;++j)
		{
			percent[next][j-1]+=percent[current][j]*L;
			percent[next][j]+=percent[current][j]*D;
			percent[next][j+1]+=percent[current][j]*W;
		}
	}

	result=percent[0][20];
	for(int i=21;i<61;++i)
	{
		if(i%10==0)
		{
			printf("%.08lf\n", result);
			result=0;
		}

		result+=percent[0][i];
	}
	printf("%.08lf", result);
	return 0;
}
