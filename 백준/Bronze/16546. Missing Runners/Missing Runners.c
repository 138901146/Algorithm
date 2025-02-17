#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, runner;
	bool finished[32769]={false};

	scanf("%d", &N);

	for(int i=1;i<N;++i)
	{
		scanf("%d", &runner);
		finished[runner]=true;
	}

	for(runner=1;runner<=N;++runner)
		if(!finished[runner])
		{
			printf("%d", runner);
			break;
		}

	return 0;
}