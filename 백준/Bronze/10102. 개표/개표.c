#include<stdio.h>

int main(void)
{
	int V, A=0, B=0;
	char vote[16]={0};

	scanf("%d", &V);
	scanf("%s", vote);

	while(V--)
	{
		if(vote[V]=='A')
			++A;
		else
			++B;
	}

	printf("%s", A<B?"B":B<A?"A":"Tie");
	return 0;
}