#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS
    int n, m, k, principal, nroamigos = 0;
    cin >> n >> m >> k;
    vector<int> numeros(m);
    for ( int i = 0; i < m; ++i ) cin >> numeros[i];
    cin >> principal;
    
    for ( int i = 0; i < m; ++i )
    {
        int contador = 0;
        for ( int j = 0; j < n; ++j )
        {
            if ( ( ( numeros[i] >> j ) & 1 ) != (( principal >> j ) & 1) )
                ++contador;
        }
        if ( contador <= k ) ++nroamigos;
    }

    cout << nroamigos;
    
    return 0;
}