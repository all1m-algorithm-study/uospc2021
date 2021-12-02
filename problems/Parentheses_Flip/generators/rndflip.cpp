#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int exp = atoi(argv[2]);

    cout << n << "\n";

    for (int i=0; i<n; i++){
        int now = rnd.next(1,100);

        if (now <= exp) cout << "(";
        else cout << ")";

    }
    cout << "\n";
}





