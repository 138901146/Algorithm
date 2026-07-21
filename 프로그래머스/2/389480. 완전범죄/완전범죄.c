#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// info_rows는 2차원 배열 info의 행 길이, info_cols는 2차원 배열 info의 열 길이입니다.
int solution(int** info, size_t info_rows, size_t info_cols, int n, int m)
{
    int answer = n, current = 0, next = 1;
    bool ***reachable = malloc(n * sizeof(bool **));

    for(int i = 0; i < n; ++i)
    {
        reachable[i] = (bool **)malloc(m * sizeof(bool *));
        for(int j = 0; j < m; ++j)
            reachable[i][j] = (bool *)calloc(2, sizeof(bool));
    }
    reachable[0][0][0] = true;

    for(int i = 0; i < info_rows; ++i)
    {
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < m; ++k)
                reachable[j][k][next] = false;

        for(int j = 0; j < n; ++j)
            for(int k = 0; k < m; ++k)
            {
                if(!reachable[j][k][current])
                    continue;

                if(j + info[i][0] < n)
                    reachable[j + info[i][0]][k][next] = true;
                if(k + info[i][1] < m)
                    reachable[j][k + info[i][1]][next] = true;
            }

        current ^= 1;
        next ^= 1;
    }

    for(int i = n - 1; 0 <= i; --i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(reachable[i][j][current])
                answer = i;
            free(reachable[i][j]);
        }
        free(reachable[i]);
    }
    free(reachable);

    return answer == n ? -1 : answer;
}