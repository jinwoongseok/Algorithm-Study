'''import copy

def solution(gems):
    _uniqueset = set()
    answer = []
    for gem in gems:
        if gem not in _uniqueset:
            _uniqueset.add(gem)
    maxlen = float('inf')
    spoint = 0
    for i in range(len(gems)):
        uniqueset = copy.deepcopy(_uniqueset)
        for j in range(i, len(gems)):
            cnt = j-i
            if maxlen <= cnt:
                continue
            item = gems[j]
            if item in uniqueset:
                uniqueset.remove(item)
            if len(uniqueset) == 0:
                if maxlen > cnt:
                    maxlen = cnt
                    spoint = i
    answer += [spoint+1, spoint + maxlen+1]
    return answer'''

# 정확성 ok, 예상했던대로 n**2알고리즘이라 최대한 줄여본다 했는데도 효율성 실패(시간초과)
# 문제풀이 참고 결과, O(n)으로 탐색할 수 있는 투 포인터 알고리즘을 이용

from collections import defaultdict

def solution(gems):
    answer = []
    spoint = 0
    epoint = spoint
    uniquegem = set(gems)
    gemkind = len(uniquegem)
    gemdict = defaultdict(lambda : 0)
    candidate = []
    while True:
        kind = len(gemdict)
        if spoint == len(gems):
            break
        if kind == gemkind:
            candidate.append((spoint+1, epoint))
            gemdict[gems[spoint]] -= 1
            if gemdict[gems[spoint]] == 0:
                del gemdict[gems[spoint]]
            spoint += 1
            continue
        if epoint == len(gems):
            break
        if kind != gemkind:
            gemdict[gems[epoint]] += 1
            epoint += 1
            continue

    candidate.sort(key = lambda x: x[1]-x[0])
    answer += candidate[0]
    return answer

gems = ["ZZZ", "YYY", "NNNN", "YYY", "BBB"]
print(solution(gems))