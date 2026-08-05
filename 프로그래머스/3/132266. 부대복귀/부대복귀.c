#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999

typedef struct
{
    int id, data;
}
node;

int size = 1;
node *pq = NULL;

node get(void)
{
    int index = 1;

    pq[0] = pq[1];
    pq[1] = pq[--size];

    while(index < size)
    {
        int left = index << 1, right = left | 1, next = left < size ? pq[left].data < pq[right].data ? left : right : right < size ? left : index;

        if(pq[next].data <= pq[index].data)
            break;

        node temp = pq[index];
        pq[index] = pq[next];
        pq[next] = temp;
        index = next;
    }

    return pq[0];
}

void add(node input)
{
    int index = size;

    pq[size++] = input;

    while(1 < index)
    {
        int next = index >> 1;

        if(pq[index].data <= pq[next].data)
            break;

        pq[0] = pq[index];
        pq[index] = pq[next];
        pq[next] = pq[0];
        index = next;
    }
}

// roads_rows는 2차원 배열 roads의 행 길이, roads_cols는 2차원 배열 roads의 열 길이입니다.
// sources_len은 배열 sources의 길이입니다.
int *solution(int n, int **roads, size_t roads_rows, size_t roads_cols, int sources[], size_t sources_len, int destination)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = malloc(sources_len * sizeof(int)), **adjacent_list = malloc((n + 1) * sizeof(int *)), *adjacent_list_count = calloc(n + 1, sizeof(int));
    node *distance = malloc((n + 1) * sizeof(node));

    for(int i = 0; i < roads_rows; ++i)
        for(int j = 0; j < 2; ++j)
            ++adjacent_list_count[roads[i][j]];

    for(int i = 1; i <= n; ++i)
    {
        distance[i].id = i;
        distance[i].data = INF;
        adjacent_list[i] = (int *)malloc(adjacent_list_count[i] * sizeof(int));
        adjacent_list_count[i] = 0;
    }
    distance[destination].data = 0;

    for(int i = 0; i < roads_rows; ++i)
        for(int j = 0; j < 2; ++j)
            adjacent_list[roads[i][j]][adjacent_list_count[roads[i][j]]++] = roads[i][j ^ 1];

    pq = (node *)malloc(30 * n * sizeof(node));
    add(distance[destination]);

    while(1 < size)
    {
        int index = pq[1].id, data = pq[1].data;

        get();

        if(distance[index].data < data)
            continue;

        for(int i = 0; i < adjacent_list_count[index]; ++i)
        {
            int next = adjacent_list[index][i];

            if(data + 1 < distance[next].data)
            {
                distance[next].data = data + 1;
                add(distance[next]);
            }
        }
    }

    for(int i = 0; i < sources_len; ++i)
        answer[i] = distance[sources[i]].data == INF ? -1 : distance[sources[i]].data;

    for(int i = 1; i <= n; ++i)
        free(adjacent_list[i]);
    free(adjacent_list);
    free(adjacent_list_count);
    free(pq);
    free(distance);

    return answer;
}