#include<stdio.h>

int main(void)
{
	char str[101]={0};
	int count[26]={0}, erase=0;

	scanf("%s", str);

	for(int i=0;str[i];++i)
		++count[str[i]-'a'];

	for(int i=0;i<25;++i)
		for(int j=i+1;j<26;++j)
			if(count[i]<count[j])
			{
				int temp=count[i];
				count[i]=count[j];
				count[j]=temp;
			}

	for(int i=2;i<26;++i)
		erase+=count[i];

	printf("%d", erase);
	return 0;
}