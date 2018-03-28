#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[10001]={-1};
    int sum[10001]={0},c;
    a[10000] = 2;
    sum[0] = 2;
    for (int q = 1; q <= 10000; q++) 
    {
        int j = 10000;
        c = 0;
        for ( ; j >= 0; j--) 
        {
            if (a[j] == -1) 
                break;
            a[j] *= 2;
            a[j] += c;
            c = a[j] / 10;
            a[j] %= 10;
            sum[q] += a[j];
        }
        if (c > 0) 
        {
            sum[q] += c;
            a[j] = c;
        }
    }
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        cout << sum[n - 1] << "\n";
    }
    return 0;
}
