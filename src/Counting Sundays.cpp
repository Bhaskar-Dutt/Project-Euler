#include<bits/stdc++.h>
using namespace std;
#define int long long
int Zellercongruence(int day, int month, int year) 
{ 
    if (month == 1) 
    { 
        month = 13; 
        year--; 
    } 
    if (month == 2) 
    { 
        month = 14; 
        year--; 
    } 
    int q = day; 
    int m = month; 
    int k = year % 100; 
    int j = year / 100; 
    int h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j; 
    h = h % 7; 
    if(h==1)
        return 1;
    return 0; 
} 

signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int x,y,da,d,m,n;
        cin >> x >> m >> da;
        cin >> y >> n >> d;
        int count = 0;
        if(x == y)
        {
            if(da == 1)
                count += Zellercongruence(1,m,x);
            for(int j = m+1; j <= n; j++)
                count += Zellercongruence(1,j,x);
            cout << count << endl;
            continue;
        }
        if(da == 1)
            count += Zellercongruence(1,m,x);
        for(int j = m+1; j <= 12; j++)
            count += Zellercongruence(1,j,x);
        for(int i = x+1; i <= y; i++)
        {
            if(i == y)
                for(int j = 1; j <= n; j++)
                    count += Zellercongruence(1,j,i);
            else
                for(int j = 1; j <= 12; j++)
                    count += Zellercongruence(1,j,i);
        }
        cout << count << endl;
    }
    return 0;
}
