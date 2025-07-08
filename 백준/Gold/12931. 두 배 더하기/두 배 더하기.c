#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, B[50], count=0;
	bool done=false;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d", &B[i]);

	while(!done)
	{
		done=true;
		bool divide=false;

		for(int i=0;i<N;++i)
		{
			if(B[i])
			{
				done=false;
				if(B[i]&1)
				{
					++count;
					--B[i];
				}
			}

			if(B[i])
				divide=true;
		}

		if(divide)
		{
			++count;
			for(int i=0;i<N;++i)
				B[i]>>=1;
		}
	}

	printf("%d", count);
	return 0;
}