#include<stdio.h>
#include<string.h>
#include<math.h>
#include<complex.h>

#define N 1050000
#define PI 3.14159265358979

int max(int x,int y)
{
	return x<y?y:x;
}

void swap(complex *x,complex *y)
{
	complex temp=*x;
	*x=*y;
	*y=temp;
}

void dft(complex x[N],int n,int in)
{
	for(int i=1,j=0;i<n;++i)
	{
		int k=n>>1;

		while(!((j^=k)&k))
		    k>>=1;

		if(i<j)
			swap(x+i,x+j);
	}

	for(int i=1;i<n;i<<=1)
	{
		double T=(in?-1:1)*PI/i;
		complex w=cos(T)-sin(T)*I;

		for(int j=0;j<n;j+=(i<<1))
		{
			complex wp=1;

			for(int k=0;k<i;++k)
			{
				complex a=x[k+j], b=x[k+j+i]*wp;
				x[k+j]=a+b;
				x[k+j+i]=a-b;
				wp*=w;
			}
		}
	}
}

void idft(complex x[N],int n)
{
	dft(x,n,1);

	for(int i=0;i<n;++i)
		x[i]=(int)(x[i]/n+0.1);
}

void mul(complex x[],complex y[],complex z[],int n)
{
	dft(x,n,0);
	dft(y,n,0);

	for(int i=0;i<n;++i)
		z[i]=x[i]*y[i];

	idft(z,n);
}

int set(int n)
{
	for(int i=0;;++i)
		if(n<=1<<i)
			return 1<<i+1;
}

int re(complex a)
{
	return (int)creal(a);
}

complex x[N], y[N], z[N], w[N];
char a[N], b[N];

int main(void)
{
	int n, la, lb, za=0, zb=0;

	scanf("%s%s", a, b);

	if(a[0]=='0' || b[0]=='0')
	{
		printf("0");
		return 0;
	}

	la=strlen(a);
	lb=strlen(b);

	for(int i=la-1;a[i]=='0';++za, a[i--]=0);
	for(int i=lb-1;b[i]=='0';++zb, b[i--]=0);

	for(int i=0;a[i];++i)
		x[i]=a[i]-'0';
	for(int i=0;b[i];++i)
		y[i]=b[i]-'0';

	n=set(max(la,lb));
	mul(x,y,z,n);

	while(!re(z[n]) && n)
		--n;

	if(re(z[n]))
		++n;

	for(int i=0;i<n;++i)
		w[i]=z[n-1-i];

	for(int i=0;i<n-1;++i)
	{
		w[i+1]+=w[i]/10;
		w[i]=re(w[i])%10;
	}

	while(!re(w[n]) && n)
		--n;

	for(int i=n;i>=0;--i)
		printf("%d", re(w[i]));
	for(int i=0;i<za+zb;++i)
		printf("0");
	return 0;
}