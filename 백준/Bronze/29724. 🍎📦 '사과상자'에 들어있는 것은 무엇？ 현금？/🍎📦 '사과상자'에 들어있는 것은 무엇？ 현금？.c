#include<stdio.h>

int main(void)
{
	int N, W, H, L, weight=0, price=0;
	char T;

	scanf("%d", &N);

	while(N--)
	{
		getchar();
		scanf("%c%d%d%d", &T, &W, &H, &L);

		if(T=='A')
		{
			weight+=1000+(W/12)*(H/12)*(L/12)*500;
			price+=4000*(W/12)*(H/12)*(L/12);
		}
		else
			weight+=6000;
	}

	printf("%d\n%d", weight, price);
	return 0;
}