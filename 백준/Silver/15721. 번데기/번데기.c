#include<stdio.h>

int main(void)
{
	int A, T, secondary, count=1, turn=-1;

	scanf("%d", &A);
	scanf("%d", &T);
	scanf("%d", &secondary);

	while(++count)
	{
		++turn;
		if(!secondary&&!--T)
			break;
		++turn;
		if(secondary&&!--T)
			break;
		++turn;
		if(!secondary&&!--T)
			break;
		++turn;
		if(secondary&&!--T)
			break;
		for(int i=0;i<count;++i)
		{
			++turn;
			if(!secondary&&!--T)
				break;
		}
		if(!T)
			break;
		for(int i=0;i<count;++i)
		{
			++turn;
			if(secondary&&!--T)
				break;
		}
		if(!T)
			break;
	}

	printf("%d", turn%A);
	return 0;
}