#include<stdio.h>

int main(void)
{
	int Fs, Cs, Es, Bs, Fn, Cn, En, Bn, Q, i, query, count=0;

	scanf("%d%d%d%d", &Fs, &Cs, &Es, &Bs);
	scanf("%d%d%d%d", &Fn, &Cn, &En, &Bn);
	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d%d", &query, &i);

		switch(query)
		{
			case 1:
				if(i*Fn<=Fs && i*Cn<=Cs && i*En<=Es && i*Bn<=Bs)
				{
					Fs-=i*Fn;
					Cs-=i*Cn;
					Es-=i*En;
					Bs-=i*Bn;
					count+=i;
					printf("%d\n", count);
				}
				else
					printf("Hello, siumii\n");
				break;
			case 2:
				Fs+=i;
				printf("%d\n", Fs);
				break;
			case 3:
				Cs+=i;
				printf("%d\n", Cs);
				break;
			case 4:
				Es+=i;
				printf("%d\n", Es);
				break;
			case 5:
				Bs+=i;
				printf("%d\n", Bs);
				break;
		}
	}

	return 0;
}