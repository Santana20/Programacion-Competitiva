/*
Nombre del problema: Sum It Up
*/
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<int> numeros; int n, t, suma, contador; vector<bool> print;
set<string> ans;
void bt(ll pos)
{
    if ( pos == n )
    {
        if ( suma == t )
        {
            string auxans; int i, auxcont = contador;
            
            for ( i = 0; i < n; ++i )
            {
                if ( auxcont == 0 ) break;

                if ( print[i] )
                {
                    --auxcont;
                    auxans += to_string(numeros[i]);
                    if ( auxcont > 0 )  auxans += '+';
                }
            }

            ans.insert(auxans);
        }
        return;
    }
 
    
    if (suma + numeros[pos] <= t) 
    {
        print[pos] = true;
        ++contador;
        suma += numeros[pos];
        bt(pos + 1);
        --contador;
        suma-= numeros[pos];
    }
    print[pos] = false;
    bt(pos + 1);
}

int main()
{
    IOS
    while(1)
    {
        cin >> t >> n;
        if ( n == 0 ) return 0;

        ans.clear();
        suma = 0; contador = 0;
        numeros.assign(n, -1); print.assign(n, false);
        
        cout << "Sums of " << t << ":\n";
        for ( int i = 0; i < n; ++i ) cin >> numeros[i];
        bt(0);

        for ( auto rit = ans.rbegin(); rit != ans.rend(); ++rit )
        {
            cout << *rit << '\n';
        }
        if ( ans.size() == 0 ) cout << "NONE\n";
    }
    return 0;
}