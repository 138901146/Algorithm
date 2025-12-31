#include<stdio.h>

int main(void)
{
	int N, count=0, total=0;
	char slogan[1001]={0};

	scanf("%d", &N);
	scanf("%s", slogan);

	for(int n=0;n<N;++n)
	{
		count*=10;

		if('0'<=slogan[n] && slogan[n]<='9')
			count+=slogan[n]-'0';
		else
		{
			total+=count/10;
			count=0;
		}
	}

	printf("%d", total+count);
	return 0;
}