#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while(test--)
    {
        int n,k;
        cin >> n >> k;
        string str;
        cin >> str;
        for(int i = 0 ; i < str.size() ; i++)
        {
            str[i]-=48;
        }
        int ans = 0,mul,j;
        for(int i = 0 ; i < str.size() ; i++)
        {
            mul = 1 ,j = i;
            while(j < i+k)
            {
                mul*=str[j];
                j++;
            }
            if(ans < mul)
                ans = mul;
        }
        cout << ans << '\n';
    }
    return 0;
}
