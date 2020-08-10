#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 102
typedef long long ll;
const char nl = '\n';

bool memo[MAXN][MAXN];
int A[] = { 1, 5, 3 };

int f(int n, int s)
{
    if ( n == 0 )
    {
        if ( s == 0 ) return 1;
        else return 0;
    }

    if ( memo[n][s] != -1 ) return memo[n][s];

    if ( s - A[n-1] >= 0 ) 
    {
        memo[n][s] = f(n-1, s - A[n-1]) || f(n-1, s);
    }
    else memo[n][s] = f(n-1, s);

    return memo[n][s];
}

int main()
{
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //IOS
    int s; cin >> s;
    int n = 3;
    
    forin(i, s)
    {
        if (i == 0) memo[0][i] = 1;
        else memo[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            if (j - A[i-1] >= 0) memo[i][j] = memo[i-1][j-A[i-1]];
        }
    }
	return 0;
}