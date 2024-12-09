#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int abval = abs(a[i] - a[j]);
                if (abval % k == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES" << endl;
                cout << i + 1 << endl;
                found = true;
                break;
            }
        }
 
        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
