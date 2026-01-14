#include<stdio.h>

int main(void)
{
	int N=0, count=0;
	char light[1001]={0};

	scanf("%s", light);

	while(light[N])
		++N;

	for(int i=0;i<N;++i)
		if(light[i]=='Y')
		{
			++count;
			for(int j=i;j<N;j+=i+1)
				light[j]=light[j]=='Y'?'N':'Y';
		}

	printf("%d", count);
	return 0;
}