#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

 
int main()
{
    IOS
 
    int x, n;
    cin >> x >> n;
    int i, minimo = x;
    vector<bool> numeros(102, false);
    forin(i, n)
    {
        int aux;
        cin >> aux;
        numeros[aux] = true;
    }
    int sustract = 0;
    while (1)
    {
        if ( !numeros[x - sustract] ) { cout << ( x - sustract ); break; }
        if ( !numeros[x + sustract] ) { cout << ( x + sustract ); break; }

        sustract++;
    }
    return 0;
}
