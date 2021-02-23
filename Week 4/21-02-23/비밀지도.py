def solution(n, arr1, arr2):
    arr1_convert = []
    arr2_convert = []
    for i in range(n):
        line1 = format(arr1[i], 'b')
        line2 = format(arr2[i], 'b')
        if len(line1) != n:
            for _ in range(n-len(line1)):
                line1 = '0' + line1
        if len(line2) != n:
            for _ in range(n-len(line2)):
                line2 = '0' + line2
        arr1_convert.append(list(line1))
        arr2_convert.append(list(line2))

    answer = ['' for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if arr1_convert[i][j] == '1' or arr2_convert[i][j] == '1':
                answer[i] += '#'
            elif arr1_convert[i][j] == '0' and arr2_convert[i][j] == '0':
                answer[i] += ' '

    return answer


arr1 = [9, 20, 28, 18, 11]
arr2 = [30, 1, 21, 17, 28]
n = 5
print(solution(n,arr1,arr2))