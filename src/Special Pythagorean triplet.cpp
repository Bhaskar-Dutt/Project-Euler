#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        int pro = -1,temp; 
        for(int a = 1, b, c; a <= n/3; a++)
        {
            b = (n*n - 2*n*a)/(2*n - 2*a);
            c = n - a - b; 
            if(c*c == (a*a + b*b))
            {
                temp = a*b*c; 
                if(temp > pro)
                {
                    pro = temp; 
                }
            }
        }
        cout << pro << endl;
    }
}
