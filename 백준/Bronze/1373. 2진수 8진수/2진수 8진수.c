#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;
	char binary[2][1000002]={'\0', }, octal[333335]={'\0', };

	scanf("%s", binary[0]);

	if(strlen(binary[0])%3==0)
		strcpy(binary[1],binary[0]);
	else if(strlen(binary[0])%3==1)
		sprintf(binary[1], "00%s", binary[0]);
	else
		sprintf(binary[1], "0%s", binary[0]);

	N=strlen(binary[1]);
	for(int i=0;i<N;i+=3)
		octal[i/3]='0'+4*(binary[1][i]=='1')+2*(binary[1][i+1]=='1')+(binary[1][i+2]=='1');

	printf("%s\n", octal);
	return 0;
}