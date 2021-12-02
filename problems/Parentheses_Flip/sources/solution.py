def solve(a):
    b,c=0,0
    for i in range(n):
        b+=-2*ord(a[i])+81
        if b<0:c+=1;b+=2
    return b//2+c
n=int(input())
a=list(input())
b=[chr(-ord(a[i])+81) for i in range(n)]
print(n-solve(b))
print(solve(a))

