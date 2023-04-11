import sys
input = sys.stdin.readline


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)

    if rnk[a] > rnk[b]:
        parent[b] = a
    elif rnk[b] > rnk[a]:
        parent[a] = b
    else:
        parent[b] = a
        rnk[a] += 1


n, m = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(m + 1)]

parent = [i for i in range(n + 1)]
rnk = [0] * (n + 1)

up = sorted(edge, key=lambda x: x[-1])

down = sorted(edge, key=lambda x: -x[-1])
max_cost = 0
min_cost = 0

for a, b, c in up:
    if find(a) != find(b):
        union(a, b)
        if c == 0:
            max_cost += 1

parent = [i for i in range(n + 1)]
rnk = [0] * (n + 1)

for a, b, c in down:
    if find(a) != find(b):
        union(a, b)
        if c == 0:
            min_cost += 1
print(max_cost * max_cost - min_cost * min_cost)