#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    IOS
    
    int t; cin >> t;
    while ( t-- )
    {
        int n; cin >> n;
        int i, last = 0; bool cero = false, uno = false, sorted= true;
        forn(i, n)
        {
            int aux; cin >> aux;
            if ( last > aux ) sorted = false;

            last = aux;
        }
        forn(i, n)
        {
            int aux; cin >> aux;
            if ( aux ) uno = true;
            else cero = true;
        }

        cout << ( sorted || ( uno && cero ) ? "Yes" : "No" ) << '\n';
    }

    return 0;
}