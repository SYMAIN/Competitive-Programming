def solve(str,prev):
    a1,a2 = int(str[0]),int(str[1])
    a3 = int(str[2:])
    
    res = a1 + a2
    if res % 2==0 and res != 0:
        prev = "right"
    elif res % 2 == 1:
        prev = "left"
    print(prev,a3)
    return prev
    
N = input()
prev = ""

while N != "99999":
    prev = solve(N,prev)
    N = input()
