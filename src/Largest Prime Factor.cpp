#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxp(int n)
{
    int maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }
    if (n > 2)
        maxPrime = n;
    return maxPrime;
}

signed main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        int ans=maxp(n);
        cout << ans << "\n";
        
    }
    return 0;
}
