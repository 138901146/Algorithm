tile = [1] * 251
tile[2] = 3
for i in range(3, 251):
    tile[i] = tile[i-1] + (tile[i-2] << 1)

while True:
    try:
        print(tile[int(input())])
    except EOFError:
        break
