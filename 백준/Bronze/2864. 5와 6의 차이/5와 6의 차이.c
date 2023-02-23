#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int A, B, min[2], max[2];
	char num[10]={'\0', };

	scanf("%d %d", &A, &B);

	sprintf(num,"%d", A);
	for(int i=0;i<strlen(num);i++)
		num[i]+=num[i]=='5';
	max[0]=atoi(num);
	for(int i=0;i<strlen(num);i++)
		num[i]-=num[i]=='6';
	min[0]=atoi(num);

	for(int i=0;i<10;i++)
		num[i]='\0';
	sprintf(num,"%d", B);
	for(int i=0;i<strlen(num);i++)
		num[i]+=num[i]=='5';
	max[1]=atoi(num);
	for(int i=0;i<strlen(num);i++)
		num[i]-=num[i]=='6';
	min[1]=atoi(num);

	printf("%d %d\n", min[0]+min[1], max[0]+max[1]);
	return 0;
}