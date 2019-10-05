#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fore(i,n) for(int i=0;i<n;i++)

int divSum(int num) 
{ 
    int result = 0; 
    if(num<2)
        return num;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    bool a[100001];
    memset(a, 0, sizeof(a));
    for(int i=2;i<=100000;i++)
    {
        int x=divSum(i),y=divSum(x);
        if(y==i && x!=i && x!=1)
            a[i]=1;
    }
    while(test--)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i])
                sum+=i;
        }
        cout<<sum<<endl;
    }
    return 0;
}
