#include<stdio.h>

int main(void)
{
	int base=0, multiply;
	char color[7]={0};

	for(int i=0;i<2;++i)
	{
		scanf("%s", color);
		base*=10;
		switch(color[0])
		{
			case 'b':
				base+=color[2]=='a'?0:color[2]=='o'?1:6;
				break;
			case 'r':
				base+=2;
				break;
			case 'o':
				base+=3;
				break;
			case 'y':
				base+=4;
				break;
			case 'g':
				base+=color[3]=='e'?5:8;
				break;
			case 'v':
				base+=7;
				break;
			case 'w':
				base+=9;
				break;
		}
	}

	scanf("%s", color);
	switch(color[0])
	{
		case 'b':
			multiply=color[2]=='a'?1:color[2]=='o'?10:1000000;
			break;
		case 'r':
			multiply=100;
			break;
		case 'o':
			multiply=1000;
			break;
		case 'y':
			multiply=10000;
			break;
		case 'g':
			multiply=color[3]=='e'?100000:100000000;
			break;
		case 'v':
			multiply=10000000;
			break;
		case 'w':
			multiply=1000000000;
			break;
	}

	printf("%lld", (long long)base*multiply);
	return 0;
}