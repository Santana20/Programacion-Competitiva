#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 102
typedef long long ll;
const char nl = '\n';

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    IOS
    while(1)
    {
        double h, u, d, f, du, curr = 0; int day = 0;
        cin >> h >> u >> d >> f;
        if ( h == 0 ) break;
        du = ( f * u ) / 100;
        bool ok = false;
        
        while ( 1 )
        {
            ++day;
            if (day > 1) u -= du;

            
            if ( u > 0 ) curr += u;

            if ( curr > h ) { ok = true; break; }
            
            curr -= d;
            if (curr < 0) break;
        }

        cout << ( ok ? "success on day " : "failure on day " ) << day << nl;
    }
    
    return 0;
}