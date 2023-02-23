#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		bool palindrome=true;
		int N1, N2=0, temp;
		char str[10]={'\0', };

		scanf("%d", &N1);
		temp=N1;

		while(temp>0)
		{
			N2*=10;
			N2+=temp%10;
			temp/=10;
		}

		N1+=N2;
		sprintf(str,"%d",N1);

		for(int i=0;i<strlen(str)/2;i++)
			if(str[i]!=str[strlen(str)-1-i])
			{
				palindrome=false;
				break;
			}

		printf("%s\n", palindrome?"YES":"NO");
	}

	return 0;
}