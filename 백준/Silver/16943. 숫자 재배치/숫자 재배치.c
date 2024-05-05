#include<stdio.h>

int A, B, C=-1, arr[9], size=0, full;

void simulate(int num,int flag)
{
	if(flag==full)
	{
		if(num<B && C<num)
			C=num;
		return;
	}

	num*=10;
	for(int i=0;i<size;++i)
		if(!(flag&(1<<i)))
			simulate(num+arr[i],1<<i|flag);
}

int main(void)
{
	scanf("%d%d", &A, &B);

	while(A)
	{
		arr[size++]=A%10;
		A/=10;
	}
	full=(1<<size)-1;

	for(int i=0;i<size;++i)
		if(arr[i])
			simulate(arr[i],1<<i);

	printf("%d", C);
	return 0;
}