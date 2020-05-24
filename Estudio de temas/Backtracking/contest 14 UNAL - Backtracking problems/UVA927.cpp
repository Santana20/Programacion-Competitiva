#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll fastpow(ll base, ll exponente) {
    if( exponente == 0 )  return 1;
    if( exponente & 1 )
        return base * fastpow( base * base, exponente / 2 );
    else
        return fastpow( base * base, exponente / 2 );
}

int main() 
{
    IOS

    int t;
    cin >> t;
    while ( t-- )
    {
        int n, d, k, j = 1;
        cin >> n;
        vector<int> coef(n + 1);
        for ( int i = 0; i <= n; ++i ) cin >> coef[i];
        cin >> d >> k;

        ll num;
        while ( k > 0 )
        {
            num = coef[0];
            
            for ( int i = 1; i <= n; ++i )
            {
                num += ( coef[i] * fastpow(j, i) );
            }

            k -= ( j * d );
            ++j;
        }

        cout << num << '\n';
    }

    return 0;
}
