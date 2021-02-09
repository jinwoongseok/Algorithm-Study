'''위상 정렬을 이용한 풀이
키가 큰 학생들은 자기보다 작은 학생들의 수만큼 차수를 증가시켜 degree에 저장시켜 놓는다
키가 작은 학생들은 자기 뒤의 자기보다 큰 학생이 누가 있는지 graph에 기록해놓는다
차수가 0인 학생들(키가 제일 작은학생들)을 먼저 앞쪽에 세우고(resq), q에 넣어둔다
bfs를 수행하듯 자기보다 큰 학생들의 차수를 순차적으로 1씩 감소시키며 만약 차수가 0이된 학생이 있으면 resq에 줄을 세우고, q에 넣어둔다
모든 반복이 끝나면 순차적으로 resq에 차수가 낮은순서로 줄을 서게 되고 마지막엔 모든 차수가 0이되며 루프가 종료된다'''
# 위상정렬 풀이 기억해둘것!!
# 시간복잡도는 정점(n)의 개수 + 간선(m)의 개수로 132,000

import sys
from collections import deque

n, m = map(int,input().split(' '))
degree = [0 for _ in range(n+1)]
graph = [[] for _ in range(n+1)]
resq = []
q = deque()
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    degree[b] += 1
    graph[a].append(b)

for i in range(1, n+1):
    if degree[i] == 0:
        resq.append(i)
        q.append(i)

while q:
    student = q.popleft()
    for taller_student in graph[student]:
        degree[taller_student] -= 1
        if degree[taller_student] == 0:
            resq.append(taller_student)
            q.append(taller_student)

for student in resq:
    print(student, end=' ')
