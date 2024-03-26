import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
parent = [0] * (N + 1)
depth = [0] * (N + 1)
adjacent_list = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    x, y = map(int, input().split())
    adjacent_list[x].append(y)
    adjacent_list[y].append(x)

queue = deque()
depth[1] = 1
queue.append(1)

while 0 < len(queue):
    current = queue.popleft()
    for child in adjacent_list[current]:
        if depth[child] == 0:
            depth[child] = depth[current] + 1
            parent[child] = current
            queue.append(child)

for _ in range(int(input())):
    x, y = map(int, input().split())

    while depth[x] > depth[y]:
        x = parent[x]

    while depth[y] > depth[x]:
        y = parent[y]

    while x != y:
        x, y = parent[x], parent[y]

    print(x)