#include<stdio.h>

int main(void)
{
	int T;
	long long x[4], y[4], d[6];

	scanf("%d", &T);

	while(T--)
	{
		for(int i=0;i<4;i++)
			scanf("%lld%lld", &x[i], &y[i]);

		for(int i=0, count=0;i<3;++i)
			for(int j=i+1;j<4;++j, ++count)
				d[count]=(y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]);

		for(int i=0;i<5;++i)
			for(int j=i+1;j<6;++j)
				if(d[i]>d[j])
				{
					long long temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				}

		printf("%d\n", d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && (d[3]<<1)==d[4] && d[4]==d[5]);
	}

	return 0;
}