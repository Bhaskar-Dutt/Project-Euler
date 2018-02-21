#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n,c=0,res;
        cin >> n;
        if(n==1)
            cout << "1" << '\n';
        else
        {
        for(int i = (n-1) * n ; ;i++)
        {
            c=0;
            for(int j=1;j<=n;j++)
            {
                if(i % j == 0)
                {
                    res=i;
                    c++;
                }
                else
                    break;
            }
            if(c == n)
            {
                cout << res << '\n';
                break;
            }
        }
        }
    }
    return 0;
}
