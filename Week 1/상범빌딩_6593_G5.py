# 시간 제한 1초 => 2000만번
# 메모리 제한 128 MB
# 30 * 30 * 30 = 27000 => O(nlogn)

from collections import deque

dcol = [1, 0, -1, 0, 0, 0]
drow = [0, 1, 0, -1, 0, 0]
dlevel = [0, 0, 0, 0, 1, -1]


def bfs(slevel, srow, scol):
    queue = deque()
    queue.append((slevel, srow, scol))
    searched = set()
    searched.add((slevel,srow,scol))
    while queue:
        z, y, x = queue.popleft()
        for dc, dr, dl in zip(dcol, drow, dlevel):
            ncol = x + dc
            nrow = y + dr
            nlevel = z + dl
            if (0<= ncol < C) and (0<= nrow < R) and (0<= nlevel < L):
                if building[nlevel][nrow][ncol] != '#' and (nlevel, nrow, ncol) not in searched:
                    searched.add((nlevel, nrow, ncol))
                    dp_table[nlevel][nrow][ncol] = dp_table[z][y][x] + 1
                    queue.append((nlevel, nrow, ncol))



while True:
    L, R, C = map(int, input().split(' '))
    if L == 0 and R == 0 and C == 0:
        break
    building = [[] for _ in range(L)]
    dp_table = [[[float('inf') for _ in range(C)] for _ in range(R)] for _ in range(L)]
    for level in range(L):
        for row in range(R+1):
            cols = input()
            if cols == '':
                continue
            if 'S' in cols:
                scol = cols.find('S')
                srow = row
                slevel = level
            if 'E' in cols:
                ecol = cols.find('E')
                erow = row
                elevel = level
            building[level].append(cols)


    dp_table[slevel][srow][scol] = 0
    bfs(slevel, srow, scol)
    if dp_table[elevel][erow][ecol] != float('inf'):
        print('Escaped in %s minute(s).' % dp_table[elevel][erow][ecol])
    else:
        print('Trapped!')


'''def dfs(slevel, srow, scol, time = 0):
    if building[slevel][srow][scol] == 'E':
        times.append(time)
        return True
    else:
        for dc, dr, dl in zip(dcol, drow, dlevel):
            ncol = scol + dc
            nrow = srow + dr
            nlevel = slevel + dl
            if (0<= ncol < C) and (0<= nrow < R) and (0<= nlevel < L):
                if (nlevel, nrow, ncol) not in visited and building[nlevel][nrow][ncol] != '#':
                    visited.add((nlevel, nrow, ncol))
                    time += 1
                    dfs(nlevel, nrow, ncol, time)
        time -= 1
        return False'''