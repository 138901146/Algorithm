#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x>*(long long *)y?1:*(long long *)x==*(long long *)y?0:-1;
}

long long absL(long long x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, left, right;
	long long neutrality[3]={4000000000,0,0}, *liquid=NULL;

	scanf("%d", &N);
	liquid=(long long *)malloc(N*sizeof(long long));

	for(int n=0;n<N;n++)
		scanf("%lld", &liquid[n]);

	qsort((void *)liquid,(size_t)N,sizeof(long long),compare);

	for(int i=0;i<N-2;i++)
	{
		left=i+1;
		right=N-1;

		while(left<right)
		{
			if(absL(liquid[i]+liquid[left]+liquid[right])<absL(neutrality[0]+neutrality[1]+neutrality[2]))
			{
				neutrality[0]=liquid[i];
				neutrality[1]=liquid[left];
				neutrality[2]=liquid[right];
			}

			if(liquid[i]+liquid[left]+liquid[right]==0)
				break;
			else if(liquid[i]+liquid[left]+liquid[right]<0)
				left++;
			else
				right--;
		}
	}

	printf("%lld %lld %lld\n", neutrality[0], neutrality[1], neutrality[2]);
	free(liquid);
	return 0;
}