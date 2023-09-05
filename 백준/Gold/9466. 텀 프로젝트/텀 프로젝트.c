#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int T, select[100001], choice[100001];
	bool done[100001], team[100001];

	scanf("%d", &T);

	while(T--)
	{
		int n, count=0;

		scanf("%d", &n);

		for(int i=1;i<=n;++i)
		{
			scanf("%d", &select[i]);
			if(select[i]==i)
				done[i]=team[i]=true;
			else
				done[i]=team[i]=false;
			choice[i]=0;
		}

		for(int i=1;i<=n;++i)
		{
			if(!done[i])
			{
				done[i]=true;
				choice[i]=i;
				int temp=select[i];

				while(!done[temp])
				{
					done[temp]=true;
					choice[temp]=i;
					temp=select[temp];
				}

				while(choice[temp]==i)
				{
					team[temp]=true;
					choice[temp]=0;
					temp=select[temp];
				}
			}

			count+=team[i];
		}

		printf("%d\n", n-count);
	}

	return 0;
}