#include<stdio.h>

#define swap(x,y,temp) {temp=x;x=y;y=temp;}

int main(void)
{
	int tree[5], temp;

	for(int i=0;i<5;i++)
		scanf("%d", &tree[i]);

	while(tree[0]!=1 || tree[1]!=2 || tree[2]!=3 || tree[3]!=4 || tree[4]!=5)
	{
		if(tree[0]>tree[1])
		{
			swap(tree[0],tree[1],temp);

			for(int i=0;i<5;i++)
				printf("%d ", tree[i]);
            printf("\n");
        }
        if(tree[1]>tree[2])
        {
			swap(tree[1],tree[2],temp);

            for(int i=0;i<5;i++)
                printf("%d ", tree[i]);
            printf("\n");
        }
        if(tree[2]>tree[3])
        {
			swap(tree[2],tree[3],temp);

            for(int i=0;i<5;i++)
                printf("%d ", tree[i]);
            printf("\n");
        }
        if(tree[3]>tree[4])
        {
			swap(tree[3],tree[4],temp);

            for(int i=0;i<5;i++)
                printf("%d ", tree[i]);
            printf("\n");
        }
    }

    return 0;
}