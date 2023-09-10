def power(x,y):
    if y==0:
        return 1
    pow=power(x,y>>1)
    pow**=2

    return pow*x % 1000000007 if y&1==1 else pow % 1000000007

N, M=map(int,input().split())
print((power(M,N)-power(M-1,N)) % 1000000007)