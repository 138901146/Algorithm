#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	int star1;
	int star2;
	double distance;
}
starinfo;

int *parent=NULL;

int find_parent(int star)
{
	if(parent[star]==star)
		return star;
	return parent[star]=find_parent(parent[star]);
}

void union_star(int star1,int star2)
{
	if(find_parent(star1)!=find_parent(star2))
		parent[find_parent(star1)]=find_parent(star2);
}

int compare(const void *x,const void *y)
{
	return ((starinfo *)x)->distance>((starinfo *)y)->distance?1:-1;
}

int main(void)
{
	int n, size=0, count=1;
	double **star=NULL, sum=0;
	starinfo *relation=NULL;

	scanf("%d", &n);
	star=(double **)malloc(n*sizeof(double *));
	relation=(starinfo *)malloc((n*n-n)*sizeof(starinfo));
	parent=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		star[i]=(double *)malloc(2*sizeof(double));
		for(int j=0;j<2;j++)
			scanf("%lf", &star[i][j]);
	}

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			relation[size].star1=i;
			relation[size].star2=j;
			relation[size++].distance=sqrt((star[i][0]-star[j][0])*(star[i][0]-star[j][0])+(star[i][1]-star[j][1])*(star[i][1]-star[j][1]));
		}

	qsort(relation,size,sizeof(starinfo),compare);


	for(int i=0;count<n;i++)
		if(find_parent(relation[i].star1)!=find_parent(relation[i].star2))
		{
			union_star(relation[i].star1,relation[i].star2);
			sum+=relation[i].distance;
			count++;
		}

	printf("%lf\n", sum);
	for(int i=0;i<n;i++)
		free(star[i]);
	free(star);
	free(relation);
	free(parent);
	return 0;
}