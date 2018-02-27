#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n=200000;
    bool prime[n+1];
    int p;
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    int j=2;
    vector<int> pri;
    for (int p=2; p <= n; p++)
    {
       if (prime[p])
       {
           pri.push_back(p);
           j++;
       }
    }
    
    int test;
    cin >> test;
    while(test--)
    {
        int z;
        cin >> z;
        cout << pri[z-1] << '\n';
    }
    return 0;
}
