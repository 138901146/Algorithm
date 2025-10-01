#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int n, t;
}
order;

int compare(const void *x,const void *y)
{
	return ((order *)x)->t<((order *)y)->t?-1:((order *)y)->t<((order *)x)->t?1:((order *)x)->n<((order *)y)->n?-1:1;
}

int main(void)
{
	int N, M, size=0, n;
	order o[100];
	char command[9];

	scanf("%d%d", &N, &M);

	while(N--)
	{
		scanf("%s", command);

		switch(command[0])
		{
			case 'o':
				scanf("%d%d", &o[size].n, &o[size].t);
				++size;
				for(int i=0;i<size;++i)
					printf("%d ", o[i].n);
				break;
			case 's':
				qsort((void *)o,(size_t)size,sizeof(order),compare);
				for(int i=0;i<size;++i)
					printf("%d ", o[i].n);
				if(!size)
					printf("sleep");
				break;
			case 'c':
				scanf("%d", &n);
				for(int i=0;i<size;++i)
					if(o[i].n==n)
					{
						for(int j=i+1;j<size;++j)
							o[j-1]=o[j];
						--size;
						break;
					}
				for(int i=0;i<size;++i)
					printf("%d ", o[i].n);
				if(!size)
					printf("sleep");
				break;
			default:
				break;
		}

		printf("\n");
	}

	return 0;
}