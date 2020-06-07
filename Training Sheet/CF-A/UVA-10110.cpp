#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    IOS
    ll numero;
    while( cin >> numero )
    {
        if ( numero == 0 ) break;
        ll raiz = (ll)sqrt(numero);

        cout << ( ( raiz * raiz == numero ) ? "yes" : "no" ) << '\n';
    }

    return 0;
}