#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, A;
	bool weekday[7]={false};

	scanf("%d", &N);

	while(N-- && !weekday[4])
	{
		bool temp[7]={false};

		scanf("%d", &A);

		A%=7;

		for(int i=0;i<7;++i)
			if(weekday[i])
				temp[i]=temp[(A+i)%7]=true;

		for(int i=0;i<7;++i)
			weekday[i]=temp[i];
		weekday[A]=true;
	}

	printf("%s", weekday[4]?"YES":"NO");
	return 0;
}