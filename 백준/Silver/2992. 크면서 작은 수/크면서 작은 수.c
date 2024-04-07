#include<stdio.h>

int X, digit[6], length=0, min=1000000, end;

void find_min(int number,int flag)
{
	if(flag==end)
	{
		if(X<number&&number<min)
			min=number;
		return;
	}

	for(int i=0;i<length;++i)
		if(!(1<<i&flag))
			find_min(number*10+digit[i],1<<i|flag);
}

int main(void)
{
	scanf("%d", &X);

	int temp=X;

	while(temp)
	{
		digit[length++]=temp%10;
		temp/=10;
	}

	end=(1<<length)-1;
	find_min(0,0);

	printf("%d", min==1000000?0:min);
	return 0;
}