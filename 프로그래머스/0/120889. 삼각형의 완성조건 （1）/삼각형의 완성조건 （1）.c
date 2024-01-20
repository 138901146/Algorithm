#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
    return 2-(sides[0]+sides[1]>sides[2] && sides[0]+sides[2]>sides[1] && sides[1]+sides[2]>sides[0]);
}