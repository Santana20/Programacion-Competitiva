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
    while( t-- )
    {
        int aux, cont = 0, n, k, i;
        cin >> n >> k;
        forin(i, n)
        {
            cin >> aux;
            if( aux > k ) cont += ( aux - k );
        }
        cout << cont << '\n';
    }
    
    return 0;
}