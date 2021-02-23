stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]
k = 3

def solution(stones, k):
    low = 1
    high = max(stones)+1
    while (low < high-1):
        mid = (low + high) // 2
        if (check(stones, k, mid)):
            low = mid
        else:
            high = mid

    return low

def check(stones, k, mid):
    cnt = 0
    for stone in stones:
        if stone < mid:
            cnt += 1
        else:
            cnt = 0
        if cnt>=k:
            return False
    return True

print(solution(stones, k))