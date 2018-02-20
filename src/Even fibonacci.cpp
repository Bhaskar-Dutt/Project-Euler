#include <bits/stdc++.h>

using namespace std;

#define int long long

int fibo(int n)
{
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    return fibo(n-1)+fibo(n-2);
}

signed main() 
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        int a=0,b=1,c=1,sum=0;
        while (a+b<n)
        {
            c = a+b;
            a = b;
            b = c;
            if(c % 2 == 0)
              sum+=c;
        }
        cout << sum << '\n';
    }
    return 0;
}
