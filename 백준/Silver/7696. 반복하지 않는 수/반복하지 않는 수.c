#include<stdio.h>
#include<stdbool.h>

int last=0, number[1000001]={0};

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n)
	{
		if(n>last)
		{
			for(int i=last+1;i<=n;++i)
			{
				number[i]=number[i-1];

				bool flag=false;

				while(!flag)
				{
					bool digit[10]={false};
					int temp=++number[i];
					flag=true;

					while(temp)
					{
						if(digit[temp%10])
						{
							flag=false;
							break;
						}
						digit[temp%10]=true;
						temp/=10;
					}
				}
			}

			last=n;
		}

		printf("%d\n", number[n]);
		scanf("%d", &n);
	}

	return 0;
}