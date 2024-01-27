#include<stdio.h>

int convert[27]={1}, convert_count=0, best=1000000000, A, B, K;

void find_best(int index,int temp)
{
	if(index==convert_count)
	{
		if(temp+B/(A*temp)<best)
		{
			best=temp+B/(A*temp);
			K=temp;
		}
	}
	else
	{
		find_best(index+1,temp);
		find_best(index+1,temp*convert[index]);
	}
}

int main(void)
{
	int C, count=0, prime[27]={1}, c, x=1, y=1, z;

	scanf("%d%d", &A, &B);

	C=B/A;

	while(!(C&1))
	{
		prime[count++]=2;
		C>>=1;
	}

	for(c=3;c<=C;c+=2)
		if(!(C%c))
		{
			prime[count++]=c;
			C/=c;
			c-=2;
		}

	convert[0]=prime[0];
	for(int i=1;i<count;++i)
	{
		if(prime[i]==prime[i-1])
			convert[convert_count]*=prime[i];
		else
			convert[++convert_count]=prime[i];
	}
	++convert_count;

	for(int i=0;i<convert_count;++i)
		for(int j=i+1;j<convert_count;++j)
			if(convert[i]<convert[j])
			{
				int temp=convert[i];
				convert[i]=convert[j];
				convert[j]=temp;
			}

	find_best(0,1);
	x=K;
	y=best-K;
	if(x>y)
	{
		int temp=x;
		x=y;
		y=temp;
	}
	printf("%d %d", x*A, y*A);
	return 0;
}