#include<stdio.h>

int main(void)
{
	int num[3];
	char str[4]={'\0', };

	for(int i=0;i<3;i++)
		scanf("%d", &num[i]);

	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)
			if(num[i]>num[j])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}

	scanf("%s", str);

	for(int i=0;i<3;i++)
		printf("%d ", str[i]=='A'?num[0]:str[i]=='B'?num[1]:num[2]);
	printf("\n");

	return 0;
}