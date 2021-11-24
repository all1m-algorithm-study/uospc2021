#include <iostream>
using namespace std;
#define SIZE 200000

int n;
int state[SIZE];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> state[i];

    int zeroBulb = 1;
    for (int i=0; i<n; i++)
        if (state[i] == 1) {
            zeroBulb = 0;
            break;
        }
    if (zeroBulb == 1) {
        cout << 0;
        return 0;
    }

    int first = 0;
    for (int i=0; i<n; i++) {
        if (state[i] == 1) {
            first = i;
            break;
        }
    }

    int last = 0;
    for (int i=n-1; i>=0; i--) {
        if (state[i] == 1) {
            last = i;
            break;
        }
    }

    int ans = last - first;

    for (int i=first+1, previous=first; i<n; i++) {
        if (state[i] == 1) {
            ans = min(ans, n - i + previous);
            previous = i;
        }
    }

    cout << ans;
}
