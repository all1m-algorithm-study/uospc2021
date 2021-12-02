# author : Bingha
# 2021-11-26 16:44
import sys
input = sys.stdin.readline

n = int(input())
chi = [[]for _ in range(n+1)]
val = [1 for _ in range(n+1)]  
depth = [[]for _ in range(101)]

def dfs(now,dep):
    depth[dep].append(now)

    for nxt in chi[now]:
        dfs(nxt,dep+1)

def GCD(x,y):
    while(y):
        x,y = y,x%y
    return x

def LCM(x,y):
    res = (x*y)//GCD(x,y)
    return res

def find_optimal_weight(lst):
    if len(lst) == 1:
        return lst[0]
    else:
        now = LCM(lst[0],lst[1])
        for i in range(2,len(lst)):
            now = LCM(lst[i],now)
        return len(lst) * now


for _ in range(n-1):
    a,b = map(int,input().split())
    chi[a].append(b)

dfs(1,1)
for d in range(100,0,-1):
    for i in depth[d]:
        if len(chi[i]) == 0:
            pass
        else:
            lst_temp = []
            for temp in chi[i]:
                lst_temp.append(val[temp])
            
            val[i] = find_optimal_weight(lst_temp)

print(val[1])



