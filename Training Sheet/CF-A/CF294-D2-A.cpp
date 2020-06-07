#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    //IOS
    
    int n, k;
    cin >> n;
    vector<int> wires(n);
    for ( int &x : wires ) cin >> x;
    cin >> k;

    forn ( i, k )
    {
        int x, y;
        cin >> x >> y;
        x--;
        if ( x >= 1 ) wires[x - 1] += ( y - 1 );
        if ( x < n - 1 ) wires[x + 1] += ( wires[x] - y );
        wires[x] = 0;
    }

    for ( int x : wires ) cout << x << '\n';

    return 0;
}