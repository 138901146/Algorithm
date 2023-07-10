#include<stdio.h>
#include<stdbool.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, M, number, min;
	bool broken[10]={false, };

	scanf("%d", &N);
	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &number);
		broken[number]=true;
	}

	min=abs(N-100);

	if(min<2 || M==10)
	{
		printf("%d\n", min);
		return 0;
	}

	for(int i=0;i<10;i++)
		if(!broken[i])
		{
			min=i+1+N<min?i+1+N:min;
			break;
		}

	for(int n=1;n<1000000;n++)
	{
		bool able=true;
		int count=0;
		number=n;

		while(number>0)
		{
			if(broken[number%10])
			{
				able=false;
				break;
			}
			count++;
			number/=10;
		}

		if(able)
			min=count+abs(N-n)>min?min:count+abs(N-n);
	}

	printf("%d\n", min);
	return 0;
}