#include <iostream>
#include <set>
using namespace std;
#define SIZE 200001

int n;
long long vx[SIZE];
long long vy[SIZE];
multiset<long long> x_prod_v;
multiset<long long> y_prod_v;

int ans = 0;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> vx[i];
    for (int i=1; i<=n; i++) cin >> vy[i];

    for (long long i=1; i<=n; i++) x_prod_v.insert(i * vx[i]);
    for (long long i=1; i<=n; i++) y_prod_v.insert(i * vy[i]);

    for (auto it=x_prod_v.begin(); it!=x_prod_v.end(); it++)
        if (y_prod_v.find(*it) != y_prod_v.end()) {
            ans++;
            y_prod_v.erase(y_prod_v.find(*it));
        }

    cout << ans;
}
