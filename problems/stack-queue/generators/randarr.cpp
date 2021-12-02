#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    cout << n << "\n";

    vector<int> v;

    v.push_back(m);

    for (int i=1; i<=n; i++){
        if (i != m) v.push_back(i);
    }

    shuffle(v.begin()+1,v.end());

    for (int i=0; i<n-1; i++){
        cout << v[i] << " ";
    }
    cout << v[n-1] << "\n";
}

