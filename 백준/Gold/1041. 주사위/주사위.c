#include<stdio.h>

int main(void)
{
	int number[6], sum=0, max=0, N, min[3]={50,100,150};

	scanf("%d", &N);
	for(int i=0;i<6;++i)
		scanf("%d", &number[i]);

	for(int i=0;i<6;++i)
	{
		int total=number[i];

		sum+=number[i];
		max=number[i]<max?max:number[i];

		min[0]=total<min[0]?total:min[0];

		for(int j=i+1;j<6;++j)
		{
			if(i+j==5)
				continue;

			total+=number[j];
			min[1]=total<min[1]?total:min[1];

			for(int k=j+1;k<6;++k)
			{
				if(i+k==5 || j+k==5)
					continue;

				total+=number[k];
				min[2]=total<min[2]?total:min[2];
				total-=number[k];
			}

			total-=number[j];
		}
	}

	printf("%lld", N==1?sum-max:(long long)min[0]*(5*N-6)*(N-2)+min[1]*((N<<3)-12)+(min[2]<<2));
	return 0;
}