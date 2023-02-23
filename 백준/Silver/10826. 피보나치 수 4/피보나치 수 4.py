F=[0,1,1]

n=int(input())
for i in range(2, n):
    F.append(F[i]+F[i-1])

print(F[n])