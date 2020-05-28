#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS
    ll t;
    cin >> t;
    while ( t-- )
    {
        ll A, B, C;
        cin >> A >> B >> C;
        ll m = ( ( A / 2 ) * A ) - ( C / 2 );
        if ( m < 0 ) 
        {
            cout << "No solution.\n";
        }
        else
        {
            for ( ll i = 1; i <= (ll)sqrt(B); ++i )
            {  
                if ( B % i == 0 )
                {
                    ll y = i, z = B / i;
                    if ( y + z == m - B )
                    {
                        cout << 1 << ' ' << y << ' ' << z << '\n';
                        break;
                    }
                }
            }
        }   
    }
    
    return 0;
}