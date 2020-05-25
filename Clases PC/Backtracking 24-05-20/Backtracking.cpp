#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
ll fastpow(ll base, ll exponente) 
{
    if( exponente == 0 )  return 1;
    if( exponente & 1 )
        return base * fastpow( base * base, exponente / 2 );
    else
        return fastpow( base * base, exponente / 2 );
}

int conf[10];

void bt(int pos)
{
    if ( pos == 4 )
    {
        for ( int i = 0; i < pos; ++i )
        {
            cout << conf[i] << ' ';
        }
        cout << '\n';
        return; 
    }

    for ( int i = 1; i <= 3; ++i )
    {
        conf[pos] = i;
        bt(pos + 1);
    }
}

int main()
{
    IOS
    
    bt(0);
    
    return 0;
}