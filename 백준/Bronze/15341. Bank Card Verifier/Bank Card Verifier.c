#include<stdio.h>

int main(void)
{
	while(1)
	{
		int count=0, digit, sum=0;

		for(int i=0;i<4;++i)
		{
			char card[5]={0};

			scanf("%s", card);

			for(int j=0;j<4;++j)
			{
				digit=card[j]-48;
				count+=digit==0;

				if(!(j&1))
				{
					digit<<=1;

					if(9<digit)
						digit-=9;
				}
				sum+=digit;
			}
		}

		if(count==16)
			break;
		else if(sum%10)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}