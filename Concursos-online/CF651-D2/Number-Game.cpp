#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int minimodivisorimpar(int numero)
{
    int minDivimpar = -1;

    for ( int i = 2; (i*i) <= numero; ++i )
    {
        if ( numero % i == 0 )
        {
            int aux = numero / i;

            if ( minDivimpar == -1 )
            {
                if ( i & 1 ) { minDivimpar = i; break; }
                else if ( aux & 1 ) { minDivimpar = aux; break; }
            }
        }
    }
    return minDivimpar;
}

int cntdivisorimpar(int numero)
{
    int cntDivimpar = 0;

    for ( int i = 2; (i*i) <= numero; ++i )
    {
        if ( numero % i == 0 )
        {
            int aux = numero / i;

                if ( i & 1 ) cntDivimpar++;
                else if ( aux & 1 ) cntDivimpar++;

        }
    }
    return cntDivimpar;
}

int main()
{
    IOS
    
    int t;
    cin >> t;

    while ( t-- )
    {
        int n, turno = 1;
        cin >> n;
        while( 1 )
        {
            if ( n == 1 )break;

            if ( n & 1 ) n = 1;

            else
            {
                int aux = minimodivisorimpar(n);
                int cnt = cntdivisorimpar(n);
                if ( aux == -1 ) --n;
                else if ( cnt > 1 )
                {
                    
                    ++turno;
                    break;
                }
                else
                {
                    n /= aux;
                }
            }
            
            ++turno;
        }

        cout << ( (turno & 1) ? "FastestFinger" : "Ashishgup" ) << '\n';
    }
    return 0;
}