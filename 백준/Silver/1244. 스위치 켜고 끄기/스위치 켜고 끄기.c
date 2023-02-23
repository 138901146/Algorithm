#include<stdio.h>

int main(void)
{
	int N, M, *_switch=NULL, *gender=NULL, *number=NULL;

	scanf("%d", &N);
	_switch=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
		scanf("%d", &_switch[n]);

	scanf("%d", &M);
	gender=(int *)malloc(M*sizeof(int));
	number=(int *)malloc(M*sizeof(int));
	for(int m=0;m<M;m++)
		scanf("%d%d", &gender[m], &number[m]);

	for(int m=0;m<M;m++)
	{
		if(gender[m]==1)
		{
			for(int n=0;n<N;n++)
				if((n+1)%number[m]==0)
					_switch[n]++;
		}
		else
		{
			int count=0;

			while(number[m]+count<=N && number[m]-count>0)
			{
				if(_switch[number[m]-1+count]%2!=_switch[number[m]-1-count]%2)
					break;
				else
					count++;
			}

			count--;
			for(int i=number[m]-1-count;i<=number[m]-1+count;i++)
				_switch[i]++;
		}
	}

	for(int n=0;n<N;n++)
		printf("%d%c", _switch[n]%2, n%20==19?'\n':' ');
	free(number);
	free(gender);
	free(_switch);
	return 0;
}