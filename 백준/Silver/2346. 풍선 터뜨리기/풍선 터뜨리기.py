N=int(input())
balloon=list(map(int,input().split()))
order=list()
live=[True]*N

order.append(0)
for j in range(N-1):
    current=balloon[order[-1]]
    order.append(order[-1])
    live[0]=False

    if current<0:
        for i in range(-current):
            order[-1]-=1
            if order[-1]<0:
                order[-1]+=N
            while not live[order[-1]]:
                order[-1]-=1
                if order[-1]<0:
                    order[-1]+=N
    else:
        for i in range(current):
            order[-1]+=1
            if order[-1]>=N:
                order[-1]-=N
            while not live[order[-1]]:
                order[-1]+=1
                if order[-1]>=N:
                    order[-1]-=N
    live[order[-1]]=False

for i in range(len(order)):
    print(order[i]+1, end=' ')
