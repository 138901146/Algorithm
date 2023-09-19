def gcd(x, y):
    if x < y:
        x, y = y, x
    while y > 0:
        x, y = y, x % y
    return x


def combination(current, index, total):
    global answer
    lcm = 1

    for i in range(current):
        lcm /= gcd(lcm, select[i])
        lcm *= select[i]

    if current > 0:
        answer = answer + int(N/lcm) if (current & 1) == 1 else answer - int(N/lcm)

    if current == total:
        return

    for i in range(index, K):
        select[current] = A[i]
        combination(current+1, i+1, total)


select = [0] * 20
answer = 0
N, K = map(int, input().split())
A = list(map(int, input().split()))
combination(0, 0, K)
print(int(answer))