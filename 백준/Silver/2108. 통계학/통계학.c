#include<stdio.h>
#include<stdlib.h>

int ABS(int N)
{
	return N>0?N:-N;
}

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *sequence=NULL, pri=0, pri_count=0, sec, sec_count=0, count=1;
	double sum=0.0;

	scanf("%d", &N);
	sequence=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &sequence[n]);
		sum+=sequence[n];
	}

	sum/=(double)N;
	sum*=10.0;
	if(sum>=0 && (int)sum%10>4)
		sum+=10.0;
	else if(sum<0 && (int)abs(sum)%10>4)
		sum-=10.0;

	qsort((void *)sequence,(size_t)N,sizeof(int),compare);

	for(int n=1;n<N;n++)
		if(sequence[n]!=sequence[n-1])
		{
			if(count>pri_count)
			{
				pri=sequence[n-1];
				pri_count=count;
				sec_count=0;
			}
			else if(count==pri_count && count>sec_count)
			{
				sec=sequence[n-1];
				sec_count=count;
			}
			count=1;
		}
		else
			count++;
	if(count>pri_count)
	{
		pri=sequence[N-1];
		pri_count=count;
		sec_count=0;
	}
	else if(count==pri_count && count>sec_count)
	{
		sec=sequence[N-1];
		sec_count=count;
	}

	printf("%d\n%d\n%d\n%d\n", (int)sum/10, sequence[N/2], pri_count==sec_count?sec:pri, sequence[N-1]-sequence[0]);
	free(sequence);
	return 0;
}