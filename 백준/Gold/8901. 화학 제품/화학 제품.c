#include<stdio.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int A, B, C, AB, BC, CA, ab, bc, ca, c, max=0;

		scanf("%d%d%d", &A, &B, &C);
		scanf("%d%d%d", &AB, &BC, &CA);

		for(int a=0;a<=A;++a)
			for(int b=0;b<=B&&b<=a;++b)
			{
				ab=b*AB;

				if(B-b+A-a<=C)
				{
					bc=(B-b)*BC;
					ca=(A-a)*CA;
				}
				else if(BC<CA)
				{
					c=min(A-a,C);
					ca=c*CA;
					bc=(C-c)*BC;
				}
				else
				{
					c=min(B-b,C);
					bc=c*BC;
					ca=(C-c)*CA;
				}

				max=ab+bc+ca<max?max:ab+bc+ca;
			}

		printf("%d\n", max);
	}

	return 0;
}