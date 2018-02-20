#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() 
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int x=(n-1)/3;
        int y=(n-1)/5,z=(n-1)/15;
        int a,b,c;
        a=x*3*(x+1)/2;
        b=y*5*(y+1)/2;
        c=z*15*(z+1)/2;
        cout<<a+b-c<<endl;
    }
    return 0;
}
