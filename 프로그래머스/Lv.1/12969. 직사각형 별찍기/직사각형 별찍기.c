#include <stdio.h>

int main(void) {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    while(m--)
    {
        for(int j=n;j;--j)
            printf("*");
        printf("\n");
    }
    
    return 0;
}