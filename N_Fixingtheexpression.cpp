#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        
        int dig1 = str[0] - '0';  
        int dig2 = str[2] - '0';
 
        if ((str[1] == '<' && dig1 < dig2) || 
            (str[1] == '>' && dig1 > dig2) || 
            (str[1] == '=' && dig1 == dig2)) {
            cout << str << endl;
        } else {
            if (dig1 < dig2)
                str[1] = '<';
            else if (dig1 > dig2)
                str[1] = '>';
            else
                str[1] = '=';
 
            cout << str << endl;
        }
    }
    return 0;
}
