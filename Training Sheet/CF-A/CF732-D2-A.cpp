#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS

    ll k; int r, n = 1;

    cin >> k >> r;

    while( 1 )
    {
        if ( ( k * n ) % 10 == r || ( k * n ) % 10 == 0 )
        {
            break;
        }
        ++n;
    }
    cout << n;
    return 0;
}