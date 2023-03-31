N=int(input())
N=N//4 if N%4==0 else N//4+1
print('long ' * N + 'int')