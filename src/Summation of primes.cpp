#include<bits/stdc++.h>

using namespace std;

#define int long long
#define a 2000001
signed main() 
{
    bool prime[2000001];
    memset(prime,true,sizeof(prime));
    
    for (int p = 2; p*p <=a; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=a; i += p)
                prime[i] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
    int j = 0, add = 0, sum[a] = {0};
    for(int i=0;i<a;i++)
    {
        if(prime[i])
        {
            add+=i;
            sum[j]=sum[j]+add;
        }
        else
            sum[j]=sum[j-1];
        j++;
    }
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        cout << sum[n] << '\n';
    }
    return 0;
}
