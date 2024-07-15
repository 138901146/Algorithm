#include<stdio.h>
#include<malloc.h>
#include<complex.h>
#include<math.h>

#define PI 3.14159265358979323846264

int X[60001], Y[60001];

void swap(complex *x,complex *y)
{
	complex temp=*x;
	*x=*y;
	*y=temp;
}

void FFT(complex *f,int size,int inv)
{
	for(int i=1,j=0;i<size;++i)
	{
		int index=size>>1;

		while(!((j^=index)&index))
			index>>=1;
		if(i<j)
			swap(&f[i],&f[j]);
	}

	for(int l=1;l<size;l<<=1)
	{
		double a=(inv?-PI/l:PI/l);
		complex w=cos(a)+sin(a)*I;

		for(int i=0;i<size;i+=(l<<1))
		{
			complex wp=1.0+0.0*I;

			for(int j=0;j<l;++j)
			{
				complex x=f[i+j], y=f[i+j+l]*wp;
				f[i+j]=x+y;
				f[i+j+l]=x-y;
				wp*=w;
			}
		}
	}

	if(inv)
		for(int i=0;i<size;++i)
			f[i]/=size;
}

complex *move(int N)
{
	int size=1;

	while(size<=N)
		size<<=1;
	size<<=1;

	complex *x=calloc(size,sizeof(complex)), *y=calloc(size,sizeof(complex)), *z=malloc(size*sizeof(complex));

	for(int i=0;i<N;++i)
	{
		x[i]=(double)X[i]+0.0*I;
		x[i+N]=(double)X[i]+0.0*I;
		y[i]=(double)Y[N-1-i]+0.0*I;
	}

	FFT(x,size,0);
	FFT(y,size,0);

	for(int i=0;i<size;++i)
		z[i]=x[i]*y[i];
	FFT(z,size,1);

	free(x);
	free(y);
	return z;
}

int main(void)
{
	int N;
	complex *ans;
	double max=0;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &X[i]);
	for(int i=0;i<N;++i)
		scanf("%d", &Y[i]);

	ans=move(N);

	for(int i=0;i<(N<<1);++i)
		max=max<creal(ans[i])?creal(ans[i]):max;

	printf("%.0lf", max);
	return 0;
}