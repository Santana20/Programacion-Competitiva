#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS

    int n, h, aux, contador = 0;
    cin >> n >> h;

    for ( int i = 0; i < n; ++i )
    {
        cin >> aux;
        if ( aux > h ) contador++;
    }

    cout << ( n + contador );
    return 0;
}