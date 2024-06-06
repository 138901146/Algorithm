#include<stdio.h>

char str[100002]={0};
int count[100002][26]={0};

int main(void)
{
	int N, left=0, max=0;

	scanf("%d", &N);
	scanf("%s", str+1);

	for(int right=1;str[right];++right)
	{
		for(int i=0;i<26;++i)
			count[right][i]=count[right-1][i]+(str[right]-'a'==i);

		while(left<right)
		{
			int letter=0;

			for(int i=0;i<26;++i)
				letter+=count[right][i]!=count[left][i];

			if(N<letter)
				++left;
			else
				break;
		}

		max=right-left<max?max:right-left;
	}

	printf("%d", max);
	return 0;
}