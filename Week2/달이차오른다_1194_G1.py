# 시간제한 2초
# 메모리제한 128MB
'''
기본적으로 bfs를 이용하는 문제
다만 조건이 가지고 있는 키의 개수까지 확인해야하여 까다롭다
방문여부와 거리, 그리고 가지고 있는 키를 확인하기 위해서 dist는 3차원 배열로 만들어준다 (n*m*64)
여기서 64는 a부터 f까지 6가지 키의 조합의 개수
시작 지점으로부터 bfs를 수행하며 소문자(키)를 만났을 때 or 연산자를 이용하여 키를 가지고 있지 않다면 키를 추가해준다
대문자(문)을 만나면 and 연산자를 이용하여 키를 가지고 있는지 여부를 확인하고 가지고 있으면 통과 아니면 continue
최종적으로 출구(1)에 도착 시, 해당 상태의 x,y,k 거리를 반환한다.
'''



from collections import deque
import sys
import copy




input = sys.stdin.readline

n, m = map(int, input().split())
maze = [list(input().strip()) for _ in range(n)]
dist = [[[0]*64 for _ in range(m)] for _ in range(n)]
q = deque()

def bfs():
    while q:
        x, y, k = q.popleft()
        if maze[x][y] == '1':
            print(dist[x][y][k])
            return
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny, nk = x+dx, y+dy, k
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            c = maze[nx][ny]
            if c.islower():
                # nk |= (1<<(ord(c)-ord('a')))
                nk |= 2 ** ((ord(c))-ord('a'))
            #elif c.isupper() and not nk & (1<<(ord(c)-ord('A'))): # << 쉬프트 연산자, 비트를 1번 왼쪽으로 이동시킴
            elif c.isupper() and not nk & (2 ** ((ord(c))-ord('A'))):
                continue
            if not dist[nx][ny][nk] and c != '#':
                q.append((nx, ny, nk))
                dist[nx][ny][nk] = dist[x][y][k] + 1
    print(-1)
for i in range(n):
    for j in range(m):
        if maze[i][j] == '0':
            q.append((i, j, 0))

bfs()

'''sys.setrecursionlimit(1000000)

di = [0,0,1,-1]
dj = [1,-1,0,0]

n, m = map(int, input().split(' '))

maze = []
for _ in range(n):
    line = list(input())
    if '0' in line:
        start_col = line.index('0')
        start_row = _
    maze.append(line)
maze[start_row][start_col] = '.'
keylist = set()
reslist = []
_maze = copy.deepcopy(maze)
q = deque()
cnt_table = [[0 for _ in range(m)] for _ in range(n)]

def bfs(keylist, _maze, start_row, start_col, q, cnt_table, res=0):
    cnt_table[start_row][start_col] = 1
    q.append([start_row, start_col])
    while q:
        x, y = q.popleft()
        for i, j in zip(di, dj):
            nx, ny = x+i, y+j
            if 0<=nx<n and 0<=ny<m:
                next_node = _maze[nx][ny]
                if next_node == '#':
                    continue
                elif next_node == '1':
                    reslist.append(res+cnt_table[x][y])
                    return res + cnt_table[x][y]
                elif next_node == '.' and not cnt_table[nx][ny]:
                    cnt_table[nx][ny] = cnt_table[x][y] + 1
                    q.append([nx,ny])
                    continue
                elif next_node.isupper() and not cnt_table[nx][ny]:
                    if next_node.lower() in keylist:
                        _maze[nx][ny] = '.'
                        cnt_table[nx][ny] = cnt_table[x][y] + 1
                        q.append([nx,ny])
                        continue
                elif next_node.islower() and not cnt_table[nx][ny]:
                    _keylist= keylist.copy()
                    _keylist.add(next_node)
                    _tmp = copy.deepcopy(_maze)
                    _tmp[nx][ny] = '.'
                    _res = res + cnt_table[x][y]
                    _q = deque()
                    _cnt_table = [[0 for _ in range(m)] for _ in range(n)]
                    bfs(_keylist,_tmp, nx, ny, _q,_cnt_table, _res)
                    cnt_table[nx][ny] = cnt_table[x][y] + 1
                    q.append([nx,ny])
    return False

bfs(keylist,_maze,start_row,start_col,q,cnt_table)
if len(reslist) == 0:
    print(-1)
else:
    print(min(reslist))'''