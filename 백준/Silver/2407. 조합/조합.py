n,m=map(int,input().split())
combination=1

for i in range(m):
    combination *= n-i
    combination //= i+1

print(combination)