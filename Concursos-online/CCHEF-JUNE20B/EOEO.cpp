#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    //IOS
    int t;
    cin >> t;
    while( t-- )
    {
        ll numero, exp = 0;
        cin >> numero;
        ll aux = numero;
        while ( numero % 2 == 0 )
        {
            exp++;
            numero /= 2;
        } 
        ++exp;
        ll div = ( 1LL << exp );
        ll ans = ( aux / div );
        cout << ans << '\n';
    }
    
    return 0;
}