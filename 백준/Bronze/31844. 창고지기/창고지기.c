#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int robot, box, target;
	char storage[11]={0};

	gets(storage);

	for(int i=0;i<10;++i)
		switch(storage[i])
		{
			case '@':
				robot=i;
				break;
			case '#':
				box=i;
				break;
			case '!':
				target=i;
				break;
			default:
				break;
		}

	if(!(robot<box && box<target || target<box && box<robot))
	{
		printf("-1");
		return 0;
	}

	printf("%d", abs(target-robot)-1);
	return 0;
}