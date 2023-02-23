#include<stdio.h>

int abs(int x)
{
	return x>0?x:-x;
}

int main(void)
{
	int Br, Bc, Dr, Dc, Jr, Jc, B, D;

	scanf("%d %d", &Br, &Bc);
	scanf("%d %d", &Dr, &Dc);
	scanf("%d %d", &Jr, &Jc);

	Br=abs(Br-Jr);
	Bc=abs(Bc-Jc);
	B=Br<Bc?Bc:Br;
	D=abs(Dr-Jr)+abs(Dc-Jc);

	printf("%s\n", B<D?"bessie":B>D?"daisy":"tie");
	return 0;
}