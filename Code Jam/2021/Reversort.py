def reverse(s,i,j):
    newList = []
    for k in range(0,i):
        newList.append(s[k])
    for k in range(j,i-1,-1):
        newList.append(s[k])
    for k in range(j+1,len(s)):
        newList.append(s[k])
    return newList

def reversort(s):
    cnt = 0
    for i in range(0, len(s)-1):
        j = 0
        MIN = 1000000000000
        for k in range(i, len(s)):
            if (s[k] < MIN):
                MIN = s[k]
                j = k
        s = reverse(s,i,j)
        cnt += j-i+1
    return cnt


for i in range(int(input())):
    N = int(input())
    s = list(map(int, input().split()))
    print(f"Case #{i + 1}: {reversort(s)}")

