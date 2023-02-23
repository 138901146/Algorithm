#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int A, B, a=0, b=0, cmp=1, count=0, ans=0;
		char str_a[11]={'\0', }, str_b[11]={'\0', };

		scanf("%d %d", &A, &B);

		while(A>0)
		{
			if(A%2==1)
				a+=cmp;
			A/=2;
			cmp*=10;
		}
		cmp=1;
		while(B>0)
		{
			if(B%2==1)
				b+=cmp;
			B/=2;
			cmp*=10;
		}

		sprintf(str_a,"%d", a);
		sprintf(str_b,"%d", b);
		while(str_a[count]==str_b[count] && count<strlen(str_a) && count<strlen(str_b))
			count++;

		cmp=1;
		while(count>0)
		{
			ans+=cmp*(str_a[--count]-'0');
			cmp*=2;
		}

		printf("%d\n", 10*ans);
	}

	return 0;
}