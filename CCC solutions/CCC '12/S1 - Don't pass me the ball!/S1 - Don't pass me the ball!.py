from itertools import permutations 

n = int(input()) + 1
def solve():
   cnt = 0
   for a in range(1,n):
      for b in range(a,n):
         if b <= a:
            continue
         for c in range(b,n):
            if c <= b:
               continue
            for d in range(c,n):
               if d <= c:
                  continue
               if n-a < 4:
                  return cnt
               if a < b < c < d and d==n-1:
                  cnt += 1
   return cnt
               
print(solve())