#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int t = atoi(argv[2]);

    vector<int> p(n);

    /* setup parents for vertices 1..n-1 */
    for(int i = 0; i < n; i++)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    cout << n << "\n";

    /* shuffle vertices 1..n-1 */
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());

    /* put edges considering shuffled vertices */
    vector<pair<int,int> > edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    while (true){
        int a = rnd.next(n);
        int b = rnd.next(n);
        if (p[a] != b && p[b] != a && a != b){
            edges.push_back({perm[a],perm[b]});
            break;
        }
    }

    /* shuffle edges */
    shuffle(edges.begin(), edges.end());

    for (int i=0; i < n; i++)
        cout << edges[i].first + 1 << " " << edges[i].second + 1 << "\n";
    
    int a = rnd.next(n);
    int b = (a + rnd.next(1,n-1)) % n;
    cout << a+1 << " " << b+1 << "\n"; 
    
}

