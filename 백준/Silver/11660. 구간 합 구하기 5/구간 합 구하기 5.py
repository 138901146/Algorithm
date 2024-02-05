N, M = map(int, input().split())
board = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

for r in range(1, N + 1):
    board[r] = [0] + list(map(int, input().split()))
    for c in range(1, N + 1):
        board[r][c] += board[r - 1][c] + board[r][c - 1] - board[r - 1][c - 1]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    print(board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1])