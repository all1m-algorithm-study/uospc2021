n = int(input())
arr = list(map(int,input().split())) 
a = [0 for i in range(n)]
for i in range(n):
    a[arr[i]-1] = i+1
ans = n
for i in range(1,n):
    if a[i] < a[i-1]:
        ans += n-i
print(ans * 2)
