#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    int k = atoi(argv[3]);
    vector<pair<int,int>> edges;
    
    cout << n << "\n";

    /* set big cycle */

    vector<int> c;

    for (int i=1; i<=n; i++){
        c.push_back(i);
    }

    shuffle(c.begin(), c.end());

    for (int i=0; i<t-1; i++){
        int rd = rnd.next(2);
        if (rd == 0) edges.push_back({c[i], c[i+1]});
        else edges.push_back({c[i+1], c[i]});
    }
    edges.push_back({c[0], c[t-1]});
    
    /* make branches */
    int r = 0; 

    if (k == 1 || k == 2 || k == 3 || k == 4){
        int j = rnd.next(t);
        r = j;
        for (int i = t; i<n; i++){
            int rd = rnd.next(2);
            if (rd == 0) edges.push_back({c[i], c[j]});
            else edges.push_back({c[j], c[i]});
        }
    }
    
    if (k == 5 || k == 6 || k == 7 || k == 8){
        for (int i = t; i<n; i++){
            int rd = rnd.next(2);
            if (rd == 0) edges.push_back({c[i], c[i-1]});
            else edges.push_back({c[i-1], c[i]});
        }
    }
    
    if (k == 9 || k == 10 || k == 11 || k == 12){
        int j1 = rnd.next(t);
        int j2 = (rnd.next(t) + rnd.next(1,t-1)) % t;
        r = j2;
        for (int i = t; i<n; i++){
            int rd = rnd.next(2);
            
            if (i%2 == 0){
                if (rd == 0) edges.push_back({c[i], c[j1]});
                else edges.push_back({c[j1], c[i]});
            }
            else if (i%2 == 1){
                if (rd == 0) edges.push_back({c[i], c[j2]});
                else edges.push_back({c[j2], c[i]});
            }
        }
    }
    
    
    
    /* output */
    shuffle(edges.begin(), edges.end());
    
    for (int i=0; i<n; i++){
        cout << edges[i].first << " " << edges[i].second << "\n";
    }
    
    if (k%4 == 1) cout << c[r] << " " << c[n-1] << "\n";
    else if (k%4 == 2) cout << c[n-1] << " " << c[0] << "\n";
    else if (k%4 == 3) cout << c[n-1] << " " << c[n-2] << "\n";
    else if (k%4 == 0) cout << c[n-2] << " " << c[n-1] << "\n";
}
