#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int l = atoi(argv[2]);
    int r = atoi(argv[3]);

    cout << n << "\n";

    for (int i = 0; i < n - 1; i++) {
        cout << rnd.next(l, r) << ' ';
    }
    cout << rnd.next(l, r) << '\n';

    for (int i = 0; i < n - 1; i++) {
        cout << rnd.next(l, r) << ' ';
    }
    cout << rnd.next(l, r) << '\n';
}

