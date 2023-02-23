#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int k;

	scanf("%d", &k);

	while(k!=0)
	{
		int order[6], *S=malloc(k*sizeof(int));

		for(int i=0;i<k;i++)
			scanf("%d", &S[i]);

		for(order[0]=0;order[0]<k-5;order[0]++)
			for(order[1]=order[0]+1;order[1]<k;order[1]++)
				for(order[2]=order[1]+1;order[2]<k;order[2]++)
					for(order[3]=order[2]+1;order[3]<k;order[3]++)
						for(order[4]=order[3]+1;order[4]<k;order[4]++)
							for(order[5]=order[4]+1;order[5]<k;order[5]++)
							{
								for(int i=0;i<6;i++)
									printf("%d ", S[order[i]]);
								printf("\n");
							}

		printf("\n");
		free(S);
		scanf("%d", &k);
	}

	return 0;
}