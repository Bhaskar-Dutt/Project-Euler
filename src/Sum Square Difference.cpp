#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin >> n;
        int sum=n*(n+1)/2;
        sum*=sum;
        int sq=n*(n+1)*(2*n+1)/6;
        int diff=abs(sum-sq);
        cout<< diff << '\n';
    }
    return 0;
}
