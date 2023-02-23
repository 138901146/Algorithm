N=int(input())
count,front,rear=0,0,0
card=[]
dump=[]

for i in range(N):
    card.append(i+1)
    rear+=1

while rear>front:
    count+=1

    if count%2==1:
        dump.append(card[front])
        front+=1
    else:
        card.append(card[front])
        front+=1
        rear+=1

for i in dump:
    print(i )