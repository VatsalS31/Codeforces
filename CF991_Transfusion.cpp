#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long sum_odd = 0;
        long long sum_even = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum_even += a[i];
            }
            else
            {
                sum_odd += a[i];
            }
        }

        long long odd_place = n / 2;
        long long even_place = n - odd_place;

        // Check if the conditions are satisfied
        if (sum_odd % odd_place == 0 && sum_even % even_place == 0 && sum_odd / odd_place == sum_even / even_place)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
