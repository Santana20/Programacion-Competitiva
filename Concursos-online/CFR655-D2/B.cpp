#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int minMayoresMultiplos(int n)
{
    int numaux = 1;
    for ( int i = 2; i <= (int)sqrt(n); ++i )
    {
        if( n % i == 0 )
        {
            numaux = max( numaux, i );
            break;
        }
    }
    return numaux;
}

int main()
{
    IOS
    
    int t;
    cin >> t;
    while ( t-- )
    //for(int i = 100; i < 201; ++i)
    {
        int n; cin >> n;
        if( n % 2 == 0 )
        {
            int aux = n / 2;
            cout << aux << ' ' << aux;
        }
        else
        {
            int aux = minMayoresMultiplos(n);
            if ( aux == 1 )
            {
                cout << aux << ' ' << (n-aux);
            }
            else
            {
                int aux2 = n / aux;
                cout << aux2 << ' ' << (n-aux2);
            }
            
        }

        cout << '\n';
    }

    return 0;
}