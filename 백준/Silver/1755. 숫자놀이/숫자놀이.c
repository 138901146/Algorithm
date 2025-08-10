#include<stdio.h>

int main(void)
{
	int M, N, done=0, left[100]={0}, current, order[10]={9,4,8,7,2,1,6,5,0,3};

	scanf("%d%d", &M, &N);

	for(int i=M;i<=N;++i)
		left[i]=1;

	do
	{
		current=0;

		for(int i=M;i<=N;++i)
			if(left[i])
			{
				int pri_c, pri_i, sec_c, sec_i;

				if(9<current)
				{
					pri_c=order[current/10];
					sec_c=order[current%10];
				}
				else
				{
					pri_c=order[current];
					sec_c=-1;
				}
				if(9<i)
				{
					pri_i=order[i/10];
					sec_i=order[i%10];
				}
				else
				{
					pri_i=order[i];
					sec_i=-1;
				}

				if(pri_i<pri_c||pri_i==pri_c&&sec_i<sec_c)
					current=i;
			}

		if(current)
		{
			printf("%d ", current);
			left[current]=0;
			if(!(++done%10))
				printf("\n");
		}
	}
	while(current);

	return 0;
}