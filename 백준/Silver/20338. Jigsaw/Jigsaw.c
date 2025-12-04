#include<stdio.h>

int main(void)
{
	int c, e, m;

	scanf("%d%d%d", &c, &e, &m);

	if(c!=4||e&1)
	{
		printf("impossible");
		return 0;
	}

	for(int w=0;w<=(e>>1);++w)
	{
		int h=(e>>1)-w;

		if((long long)w*h==m)
		{
			if(w<h)
			{
				int temp=w;
				w=h;
				h=temp;
			}

			printf("%d %d", w+2, h+2);
			return 0;
		}
	}

	printf("impossible");
	return 0;
}