mapdict = {10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'}


'''def convert(number,n):
    answer = ''
    if number // n < 1:
        remain = number % n
        if remain >= 10:
            remain = mapdict[remain]
        answer = str(remain) + answer
    while number // n >=1:
        remain = number % n
        if remain >= 10:
            remain = mapdict[remain]
        number = number // n
        answer = str(remain) + answer
        if n > number:
            if number >= 10:
                number = mapdict[number]
            answer = str(number) + answer
    return answer'''

def convert(num, n):
    arr = "0123456789ABCDEF"
    ret = ''
    if num == 0:
        return '0'
    while num > 0:
        ret = arr[num % n] + ret
        num = num // n
    return ret

def solution(n, t, m, p):
    i = 0
    res = []
    while True:
        _i = convert(i, n)
        res += list(_i)
        if len(res) > m*t:
            break
        i += 1
    answer = ''
    for j in range(p-1, t*m, m):
        answer += res[j]
    answer = answer[:t]
    return answer