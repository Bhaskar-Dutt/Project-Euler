#include <bits/stdc++.h>
using namespace std;

#define int long long
#define l 50
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s(100,'0'),b;
    int n,t,j,x,N,m=0;
    cin >> N;
    for(int i=0;i<N;++i)
    {
        cin >> b;
        reverse(b.begin(),b.end());
        t=0;
        for(j = 0 ; j < l ; ++j)
        {
            x = (s[j] - 48) + (b[j] - 48) + t;
            s[j] = (x%10) + 48;
            t = x/10;            
        }
        while(t!=0)
        {
            x = s[j] - 48 + t;
            s[j] = (x%10) + 48;
            t = x/10;
            j++;
        }
        if (m < j-1)
            m = j-1;
    }
    for (int i = m,j=0 ; j < 10 ; i--,j++)
        cout << s[i];
    return 0;
}
