#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Check if the weight is even and at least 4
    if (n % 2 == 0 && n >= 4) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
