#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int a, b, price=0;

		scanf("%d %d", &a, &b);

		if(a==0 || a>21)
			price+=0;
		else if(a==1)
			price+=5000000;
		else if(a<4)
			price+=3000000;
		else if(a<7)
			price+=2000000;
		else if(a<11)
			price+=500000;
		else if(a<16)
			price+=300000;
		else
			price+=100000;

		if(b==0 || b>31)
			price+=0;
		else if(b==1)
			price+=5120000;
		else if(b<4)
			price+=2560000;
		else if(b<8)
			price+=1280000;
		else if(b<16)
			price+=640000;
		else
			price+=320000;

		printf("%d\n", price);
	}

	return 0;
}