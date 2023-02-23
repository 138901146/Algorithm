TestCase=int(input())

for t in range(TestCase):
    N,M=list(map(int,input().split()))
    importance=list()
    queue=[]
    for i in range(9):
        importance.append([])

    string=input()
    for i in range(N):
        importance[int(string[i*2])-1].append(i+1)

    last=0
    ll=int()
    for i in range(8,-1,-1):
        for j in range(len(importance[i])):
            if last<importance[i][j]:
                queue.append(importance[i][j])
                ll=importance[i][j]
        for j in range(len(importance[i])):
            if last>importance[i][j]:
                queue.append(importance[i][j])
                ll=importance[i][j]
        last=ll

    for i in range(len(queue)):
        if queue[i]==M+1:
            print(i+1)
            break