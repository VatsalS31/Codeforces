#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    int w = 1, ans = 1;
 
    while (w < n) {
        w = w * 2 + 2;
        ans++;
    }
 
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}
