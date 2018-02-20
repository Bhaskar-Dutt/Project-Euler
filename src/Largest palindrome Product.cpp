#include<bits/stdc++.h>

using namespace std;

#define int long long

int palin(int num)
{
    int n=num;
    int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    if(rev_num==n)
        return true;
    return false;
}

signed main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m,ans=0;
        cin>>n;
        int b=100,a=100;
        for(int i=b;i<=999;i++)
        {
            for(int j=a;j<=999;j++)
            {
                m=i*j;
                if(m>=n)
                {
                     break;
                }
                if(palin(m))
                {
                    if(m>ans)
                    {
                        ans=m;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
