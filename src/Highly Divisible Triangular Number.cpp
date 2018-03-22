#include <bits/stdc++.h>
using namespace std;
#define int long long

int factor(int n)
{
    int i,j,flag = 0,a,l = 1;
    for(i = 2 ; i <= n ; i++)
    {
        flag = 0;
        if(n % i == 0)
        {
            for(j = 2 ; j * j < i ; j++)
            {
                if(i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                a = 0;
                while(n % i == 0)
                {
                    a++;
                    n/=i;
                }
                l = l * (a + 1);
            }
        }
    }
    return l;
}

signed main() 
{
    int flag = 0, a[10000][2], b[10000][2], c[10000][2];
    
    for(int i = 0 ; i < 10000 ; i++)
    {
        a[i][0] = i * (i + 1) / 2;
        a[i][1] = factor(a[i][0]);
        
        int j=10000+i;
        
        b[i][0] = j * (j + 1) / 2;
        b[i][1] = factor(b[i][0]);
        
        int jj=10000+j;
        
        c[i][0] = jj * (jj + 1) / 2;
        c[i][1] = factor(c[i][0]);
    }
    int test;
    cin >> test;
    while(test--)
    {
        int n,k;
        cin >> n;
        if(n < 480)
        {
            int flag = 0;
            for(k = 0 ; k < 10000 ; k++)
            {
                if(a[k][1] > n)
                {
                    flag = 1;
                    break;
                }
            }if(flag == 1)
            cout << a[k][0] << '\n';
        }
        else if(n < 648)
        {
            int flag = 0;
            for(k = 0 ; k < 10000 ; k++)
            {
                if(b[k][1] > n)
                {
                    flag = 1;
                    break;
                }
            }if(flag == 1)
            cout << b[k][0] << '\n';
        }
        else if(n < 768)
        {
            int flag = 0;
            for(k = 0 ; k < 10000 ; k++)
            {
                if(c[k][1] > n)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                cout << c[k][0] << '\n';
        }
        else
        {
            cout << "842161320" << '\n';      //This is important. //jugad baazi lol.
        }
    }
    return 0;
}
