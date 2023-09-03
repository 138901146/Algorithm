#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int MBTI[16]={0, }, N, answer=100;

		scanf("%d", &N);

		if(N>32)
		{
			char temp[5];

			while(N--)
				scanf("%s", temp);

			printf("0\n");
			continue;
		}

		while(N--)
		{
			int index=0;
			char mbti[5]={'\0', };

			scanf("%s", mbti);

			index=mbti[0]=='E';
			index<<=1;
			index|=mbti[1]=='S';
			index<<=1;
			index|=mbti[2]=='F';
			index<<=1;
			index|=mbti[3]=='P';

			++MBTI[index];
		}

		for(int i=0;i<16;++i)
			if(MBTI[i])
			{
				--MBTI[i];

				for(int j=0;j<16;++j)
					if(MBTI[j])
					{
						--MBTI[j];

						for(int k=0;k<16;++k)
							if(MBTI[k])
							{
								int current=0;

								for(int l=0;l<4;l++)
								{
									current+=((i>>l)&1)^((j>>l)&1);
									current+=((i>>l)&1)^((k>>l)&1);
									current+=((j>>l)&1)^((k>>l)&1);
								}

								answer=current<answer?current:answer;
							}

						++MBTI[j];
					}

				++MBTI[i];
			}

		printf("%d\n", answer);
	}

	return 0;
}