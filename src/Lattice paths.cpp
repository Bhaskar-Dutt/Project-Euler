#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while(test--)
    {
        int n, m;
        cin >> n >> m;
        int a[n+1][m+1];
        for (int i = 0; i <=n; ++i) 
        {
            a[i][0] = 1;
        }
        for (int i = 0; i <=m; ++i) 
        {
            a[0][i] = 1;
        }
        for (int i = 1; i <=n; ++i) 
        {
            for (int j = 1; j <=m; ++j) 
            {
                a[i][j] = (a[i-1][j] + a[i][j-1]) % mod;
            }        
        }
        cout << a[n][m] << "\n";
    }
    return 0;
}
