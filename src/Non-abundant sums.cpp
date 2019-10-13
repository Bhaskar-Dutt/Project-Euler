#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fore(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

int sum_of_divisors(int num) 
{ 
    int result = 0; 
  
    for (int i=2; i<=sqrt(num); i++) 
    { 
        if (num%i==0) 
        { 
            if (i==(num/i)) 
                result += i; 
            else
                result += (i + num/i); 
        } 
    } 
    return (result + 1); 
} 

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    for(int i=12;i<100000;i++)
        if(sum_of_divisors(i)>i)
            a.pb(i);
    vector<int> b;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i;j<a.size();j++)
        {
            if(a[i]+a[j]<=28123)
                b.pb(a[i]+a[j]);
            else
                break;
        }
    }
    int test;
    cin>>test;
    while(test--)
    {
        int n,f=0;
        cin>>n;
        if(n>28123)
        {
            cout<<"YES\n";
            continue;
        }
        fore(i,b.size())
        {
            if(n==b[i])
            {
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
