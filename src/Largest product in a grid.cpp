#include <bits/stdc++.h>

using namespace std;
#define int long long
#define n 20
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A[n][n];
    int m=0;
    for (int i=0;i<20;++i)
        for (int j=0;j<20;++j)
            cin >> A[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
        {
            if (j < n-3)
                if (m < A[i][j] * A[i][j+1] * A[i][j+2] * A[i][j+3])
                    m = A[i][j] * A[i][j+1] * A[i][j+2] * A[i][j+3];
            if (i < n-3 && j < n-3)
                if (m < A[i][j] * A[i+1][j+1] * A[i+2][j+2] * A[i+3][j+3])
                    m = A[i][j] * A[i+1][j+1] * A[i+2][j+2] * A[i+3][j+3];
            if (i < n-3)
            if (m < A[i][j] * A[i+1][j] * A[i+2][j] * A[i+3][j])
                m = A[i][j] * A[i+1][j] * A[i+2][j] * A[i+3][j];
            if (i < n-3 && n-3)
                if (m < A[i][j] * A[i+1][j-1] * A[i+2][j-2] * A[i+3][j-3])
                    m = A[i][j] * A[i+1][j-1] * A[i+2][j-2] * A[i+3][j-3];
        }
    cout << m;
    return 0;
}


