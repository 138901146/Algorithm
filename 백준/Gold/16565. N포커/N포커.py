N = int(input())

answer = 0
i = 1
flag = 1

while (i << 2) <= N:
    current = 1

    for j in range(i):
        current *= 13-j
        current /= j+1

    for j in range(N-(i << 2)):
        current *= 52-(i << 2)-j
        current /= j+1

    answer += flag*current
    i += 1
    flag = -flag

print(int(answer % 10007))