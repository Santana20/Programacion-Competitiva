#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 4005
typedef long long ll;
const char nl = '\n';



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //IOS

    int target, a, b, c; cin >> target >> a >> b >> c; 
    int ans = 0;
    for ( int x = 0; ( x*a ) <= target; ++x )
    {
        for( int y = 0; ( x * a ) + (y * b) <= target; ++y )
        {
            int res = target - ( ( x*a ) + (y*b) );
            if ( res % c == 0 )
            {
                int z = res / c;
                ans = max(ans, x + y + z);
            }
        }
    }

    cout << ans;
	return 0;
}