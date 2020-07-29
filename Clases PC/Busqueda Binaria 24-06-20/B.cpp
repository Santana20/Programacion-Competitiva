#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

ll f(ll x, ll s)
{
    return (x*x) + (s*x);
}

ll busqueda_binaria(ll target, int s)
{
    ll lo = 0, hi = 1e9 + 6;

    if ( f(lo, s) == target ) return lo;
    while( hi - lo > 1 )
    {
        int mi = lo + ( hi - lo ) / 2;

        if ( (ll)target > f(mi, s) ) lo = mi;
        else hi = mi;
    }

    if( f(hi, s) == target ) return hi;
    return -1;
}

int suma_cifras(ll x)
{
    int suma = 0;
    while(x)
    {
        suma += x % 10;
        x /= 10;
    }
    return suma;
}

int main()
{
    //IOS
    
    ll target; cin >> target;
    int s; ll ans = 1e9 + 6; bool dec = false;
    for( s = 1; s <= 81; ++s )
    {
        ll x = busqueda_binaria(target, s);

        if ( x >= 1 && suma_cifras(x) == s)
        {
            ans = min(ans, x); dec = true;
        }
    }

    if (dec) cout << ans; 
    else cout << -1;
    return 0;
}