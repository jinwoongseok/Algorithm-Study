# 초기 위치는 L : '*' R : '#'
# 1,4,7을 누를경우 'L' 반환 Lposition은 해당 숫자 위치로
# 3,6,9를 누를경우 'R' 반환 Rposition은 해당 숫자 위치로
# 이외의 경우에는 각 position에서 bfs수행, 최단거리탐색 후 더 짧은쪽을 결과로 반환, position갱신
# 만약 거리가 같다면 hand에 따라 결과 반환
# 최종 결과 출력


from collections import deque

def solution(numbers, hand):
    Lposition = '*'
    Rposition = '#'
    answer = ''
    for number in numbers:
        result, Lposition, Rposition = hands(number, Lposition, Rposition, hand)
        answer += result

    return answer

def hands(num, Lpos, Rpos, hand):
    if num == 1 or num == 4 or num == 7:
        res = 'L'
        Lpos = num
    elif num == 3 or num == 6 or num == 9:
        res = 'R'
        Rpos = num
    else:
        Ldist = bfs_dist(Lpos, num)
        Rdist = bfs_dist(Rpos, num)
        print('L', Ldist)
        print('R', Rdist)
        if Ldist<Rdist:
            res = 'L'
            Lpos = num
        elif Rdist<Ldist:
            res = 'R'
            Rpos = num
        else:
            if hand == 'right':
                res = 'R'
                Rpos = num
            elif hand == 'left':
                res = 'L'
                Lpos = num

    return res, Lpos, Rpos

def bfs_dist(positionnumber, number):
    if positionnumber == number:
        return 0
    q = deque()
    cnt_table = [[0 for _ in range(3)] for _ in range(4)]
    i, j = mapdict[positionnumber]
    q.append((i, j))
    cnt_table[i][j] = 1
    while q:
        x, y = q.popleft()
        for di, dj in zip(dx, dy):
            nx ,ny = x+di, y+dj
            if 0<=nx<4 and 0<=ny<3 and not cnt_table[nx][ny]:
                if numpad[nx][ny] == number:
                    return cnt_table[x][y]
                else:
                    q.append((nx,ny))
                    cnt_table[nx][ny] = cnt_table[x][y] + 1

numpad = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9],
          ['*', 0, '#']]
mapdict = {'*': (3, 0),
           0: (3, 1),
           '#': (3, 2)}
i = 1
for j in range(3):
    for k in range(3):
        mapdict[i] = (j, k)
        i += 1

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


numbers = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]
hand = "right"
print(solution(numbers,hand))
