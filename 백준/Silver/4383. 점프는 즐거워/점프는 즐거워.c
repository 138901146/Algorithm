#include<stdio.h>
#include<stdbool.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int n;

	while(scanf("%d", &n)!=EOF)
	{
		int number[2], diff;
		bool occur[3001]={false}, done=false;

		scanf("%d", &number[0]);
		for(int i=1;i<n;++i)
		{
			scanf("%d", &number[i&1]);

			diff=abs(number[0]-number[1]);
			if(!done)
			{
				if(!diff||n<=diff||occur[diff])
					done=true;
				occur[diff]=true;
			}
		}

		printf("%s\n", done?"Not jolly":"Jolly");
	}

	return 0;
}