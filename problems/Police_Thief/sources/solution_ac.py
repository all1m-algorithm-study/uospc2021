import sys
sys.setrecursionlimit(200002)
input = sys.stdin.readline

def dfs(now,prev):
    global s,e
    for nxt in adj[now]:
        if s != 0:
            return 0
        if nxt == prev:
            pass
        elif par[nxt] == -1:
            par[nxt] = now
            dfs(nxt,now)
        else:
            s = now
            e = nxt
            return 0

def backtrack(s,e):
    now = s
    while (now != e):
        now = par[now]
        cycle.append(now)

def bfs(x):
    dist = [-1 for i in range(n+1)]
    cnt = 0
    
    q = [x]
    dist[x] = 0
    while q:
        cnt += 1

        for _ in range(len(q)):
            now = q.pop(0)

            for nxt in adj[now]:
                if dist[nxt] == -1:
                    dist[nxt] = cnt
                    q.append(nxt)
    return dist

n = int(input())
adj = [[]for i in range(n+1)]
for i in range(n):
    a,b=map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
p,t = map(int,input().split())

par = [-1 for _ in range(n+1)]
par[1] = 0
s,e = 0,0
dfs(1,1)
cycle = [s]
backtrack(s,e)

len_p = bfs(p)
len_t = bfs(t)

flag = False

for i in cycle:
    if len_p[i] > len_t[i]:
        flag = True

if flag:
    print("NO")
else:
    print("YES")



