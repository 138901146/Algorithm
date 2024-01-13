#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min[100001][2]={0};

int *solution(int target) {
    for(int i = target; i ; --i)
    {
        min[i][0] = 1000000;
        min[i][1] = -1;
    }
    
    for(int i = 1; i <= target; ++i)
    {
        for(int j = 1; j < 21; ++j)
            for(int k = 1; k < 4; ++k)
                if(i >= j * k)
                {
                    if(min[i][0] > min[i - j * k][0] + 1 || min[i][0] == min[i - j * k][0] + 1 && min[i][1] < min[i - j * k][1] + (k == 1))
                    {
                        min[i][0] = min[i- j * k][0] + 1;
                        min[i][1] = min[i - j * k][1] + (k == 1);
                    }
                }
                else
                    break;
        
            if(i > 49 && (min[i][0] > min[i - 50][0] + 1 || min[i][0] == min[i - 50][0] + 1 && min[i][1] < min[i - 50][1] + 1))
            {
                min[i][0] = min[i - 50][0] + 1;
                min[i][1] = min[i - 50][1] + 1;
            }
    }
    
    return min[target];
}