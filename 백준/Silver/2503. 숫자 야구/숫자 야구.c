#include<stdio.h>

int main(void)
{
	int N, list[100][3], count=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		for(int i=0;i<3;++i)
			scanf("%d", &list[n][i]);

	for(int i=123;i<988;++i)
	{
		int temp=i, answer[3], same=1;

		for(int j=0;j<3;++j, temp/=10)
		{
			answer[j]=temp%10;

			if(!answer[j])
			{
				same=0;
				break;
			}

			for(int k=0;k<j;++k)
				if(answer[j]==answer[k])
					same=0;
		}

		for(int n=0;n<N && same;++n)
		{
			int strike=0, ball=0;

			temp=list[n][0];

			for(int j=0;j<3;++j, temp/=10)
			{
				int number=temp%10;

				for(int k=0;k<3;++k)
					if(answer[k]==number)
					{
						if(j==k)
							++strike;
						else
							++ball;
						break;
					}
			}

			if(strike!=list[n][1] || ball!=list[n][2])
				same=0;
		}

		count+=same;
	}

	printf("%d", count);
	return 0;
}