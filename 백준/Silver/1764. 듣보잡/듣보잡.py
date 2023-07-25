N, M=map(int,input().split())

check=set()
count=0
none=list()

for n in range(N):
    check.add(input())

for m in range(M):
    str=input()
    if str in check:
        count+=1
        none.append(str)

print(count)
none.sort()
for i in range(count):
    print(none[i])