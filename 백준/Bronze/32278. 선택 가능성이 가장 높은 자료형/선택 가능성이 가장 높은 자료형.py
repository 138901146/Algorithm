N = int(input())

if -32768 <= N and N < 32768:
    print("short")
elif -2147483648 <= N and N < 2147483648:
    print("int")
else:
    print("long long")