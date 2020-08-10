#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 102
typedef long long ll;
const char nl = '\n';

int memo[MAXN][MAXN];
vector<int> A;

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

void solve()
{
    memset(memo, -1, sizeof(memo));
    A.clear();
    string s; getline(cin, s);
    stringstream in;
    in << s;
    int aux, suma = 0, i = 0;

    while(in >> aux)
    {
        A.push_back(aux);
        suma += aux;
    }

    if ( suma % 2 ) cout << "NO";
    else
    {
        suma /= 2;
        cout << ( f((int)A.size(), suma) ? "YES" : "NO" );
    }
    cout << nl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //IOS
    int q; cin >> q; cin.ignore();
    while(q--)
    {
        solve();
    }

    return 0;
}