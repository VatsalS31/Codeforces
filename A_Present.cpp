#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1); // 1-based indexing
    vector<int> result(n + 1); // To store the reverse mapping
 
    // Input: who gives to whom
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    // Reverse the mapping
    for (int i = 1; i <= n; i++) {
        result[a[i]] = i;
    }
 
    // Output: who gave a gift to whom
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
 
    return 0;
}
