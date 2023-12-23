#include<stdio.h>

typedef struct
{
	long long a, b, c;
}
coefficient;

coefficient ESC[2]={0};

coefficient function_a(void)
{
	return (coefficient){1,0,2};
}

coefficient function_b(void)
{
	return (coefficient){0,1,-2};
}

coefficient function_c(void)
{
	return (coefficient){-1,1,1};
}

int main(void)
{
	int n;

	ESC[0].c=1;

	scanf("%d", &n);

	for(int i=1;i<=n;++i)
	{
		ESC[i&1].a=ESC[i&1].b=ESC[i&1].c=0;
		ESC[i&1].a+=ESC[i&1^1].a*function_a().a;
		ESC[i&1].b+=ESC[i&1^1].a*function_a().b;
		ESC[i&1].c+=ESC[i&1^1].a*function_a().c;
		ESC[i&1].a+=ESC[i&1^1].b*function_b().a;
		ESC[i&1].b+=ESC[i&1^1].b*function_b().b;
		ESC[i&1].c+=ESC[i&1^1].b*function_b().c;
		ESC[i&1].a+=ESC[i&1^1].c*function_c().a;
		ESC[i&1].b+=ESC[i&1^1].c*function_c().b;
		ESC[i&1].c+=ESC[i&1^1].c*function_c().c;
	}

	printf("%lld", ESC[n&1].a+ESC[n&1].b+ESC[n&1].c);
	return 0;
}