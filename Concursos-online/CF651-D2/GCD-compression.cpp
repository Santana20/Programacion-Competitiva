#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    IOS
    
    int t;
    cin >> t;

    while ( t-- )
    {
        int n; cin >> n;
        vector<int> cero, uno;
        int aux;
        for ( int i = 0; i < ( 2 * n ); ++i )
        {
            cin >> aux;
            //impar
            if ( aux & 1 ) uno.push_back(i+1);
            //par
            else cero.push_back(i+1);
        }

        int validos = n - 1, nrounos = ( (int)uno.size() & 1 ) ? (int)uno.size() - 1 : (int)uno.size(), nroceros = ( (int)cero.size() & 1 ) ? (int)cero.size() - 1 : (int)cero.size();

        for ( int i = 0; ( i < nrounos ) && ( validos > 0 ); i+=2 )
        {
            cout << uno[i] << ' ' << uno[i+1] << '\n';
            --validos;
        }

        for ( int i = 0; ( i < nroceros ) && ( validos > 0 ); i+=2 )
        {
            cout << cero[i] << ' ' << cero[i+1] << '\n';
            --validos;
        }
    }
    return 0;
}