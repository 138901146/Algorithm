#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, new_key_size=0;
	char j_key[200001]={0}, i_key[200001]={0}, j_qbit[200001]={0}, i_qbit[200001]={0}, new_key[200001]={0};

	scanf("%d", &N);
	scanf("%s", j_qbit);
	scanf("%s", j_key);
	scanf("%s", i_qbit);
	scanf("%s", i_key);

	for(int n=0;n<N;++n)
		if(j_qbit[n]==i_qbit[n])
		{
			if(i_key[n]==j_key[n])
				new_key[new_key_size++]=i_key[n];
			else
			{
				printf("htg!");
				return 0;
			}
		}

	printf("%s", new_key);
	return 0;
}