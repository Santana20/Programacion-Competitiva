/*
    Nombre del problem: A problem of Backtracking
*/

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

vector<int> numeros(10), ans(10); int k; ll suma;
vector<bool> disponibles; bool encontrado = false;
void bt(int pos)
{
    if ( pos == 10 )
    {
        if ( suma <= k )
        {
            for ( int i = 0; i < 10; ++i )
                cout << ans[i] << ' ';
            cout << '\n';
            encontrado = true;
        }
        return;
    }
    if ( encontrado ) return;
    else
    {
        for ( int i = 0; i < (int)ans.size(); ++i )
        {
            if ( disponibles[i] && ( suma + numeros[pos] * i ) <= k )
            {
                ans[pos] = i;
                suma += numeros[pos] * ans[pos];
                disponibles[i] = false;  
                bt(pos + 1);
                
                disponibles[i] = true;
                suma -= numeros[pos] * ans[pos];
                if (encontrado) break;
            }  
        }
    }
}

int main()
{
    IOS
    
    int t; cin >> t;

    while( t-- )
    {
        disponibles.assign(10, true);
        suma = 0; encontrado = false;
        for ( int i = 0; i < 10; ++i ) cin >> numeros[i];
        cin >> k;
        bt(0);
        if ( !encontrado ) cout << -1 << '\n';
    }
    
    return 0;
}
