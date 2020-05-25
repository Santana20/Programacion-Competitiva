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

int contador, n, pause; ll veces, validaciones;
vector<int> queens; vector<vector<int>> invalid; vector<bool> disponiblecolumn;
bool esvalido(int pos, int candidato)
{
    if ( pos != 0 )
    {
        for ( int i = 0; i < pos; ++i )
        {
            //validaciones++;
            if ( abs( candidato - queens[i] ) == abs(pos - i) ) 
            {
                //cout << "entre a falso donde son de la misma diagonal\n";
                return false;
            }
        }
    }
    
    //cout << "Es valido\n";
    return true;
}

void pintartablero(int pos, int caracter)
{
    int faux = pos, caux = queens[pos], i = 1;
    while ( ( faux + i ) < n)
    {
        validaciones++;
        if ( caux + i < n ) invalid[faux + i][caux + i] += caracter;
        if ( caux - i >= 0 ) invalid[faux + i][caux - i] += caracter;
        ++i;
    }
    /*i = 1;
    while ( ( faux - i ) >= 0)
    {
        validaciones++;
        if ( caux + i < n ) invalid[faux - i][caux + i] += caracter;
        if ( caux - i >= 0 ) invalid[faux - i][caux - i] += caracter;
        ++i;
    }*/
}
void bt(int pos)
{
    ++veces;
    if ( pos == n )
    {
        contador++;
        return;
    }
    for ( int i = 0; i < n; ++i )
    {
        /*cout << "fila: " << pos << '\n';
        cout << "columna: " << i << '\n';*/
        if ( disponiblecolumn[i] && invalid[pos][i] == 0/*&& esvalido(pos, i)*/ )
        {
            //cout << "Entre al IF\n";
            queens[pos] = i;
            disponiblecolumn[i] = false;
            pintartablero(pos, 1);
            
            /*cout << "fila: " << pos << '\n';
            cout << "columna: " << i << '\n';
            cout << "Tablero antes de bt\n";
            for (auto x : invalid)
            {
                for ( auto y : x ) cout << y;
                cout << '\n';
            }
            cout << "antes de entrar a bt\n";
            for ( auto x : queens ) cout << x << ' ';
            cout << '\n';
            cin >> pause;
            cout << "------------------------------\n";*/
            bt(pos + 1);
            pintartablero(pos, -1);
            disponiblecolumn[i] = true;
            queens[pos] = -1;

            /*cout << "fila: " << pos << '\n';
            cout << "columna: " << i << '\n';
            cout << "Tablero despues de bt\n";
            for (auto x : invalid)
            {
                for ( auto y : x ) cout << y;
                cout << '\n';
            }
            cout << "retorne de bt\n";
            for ( auto x : queens ) cout << x << ' ';
            cout << '\n';
            cin >> pause;
            cout << "------------------------------\n";*/
        }
        /*else if (!esvalido(pos, i)) 
        {
            cout << "Entre al segundo if\n";
            cout << "fila: " << pos << '\n';
            cout << "columna: " << i << '\n';
            cout << "no es valido la columna " << i << " en la fila " << pos << endl;
            for ( auto x : queens ) cout << x << ' ';
            cout << '\n';
            cin >> pause;
            cout << "------------------------------\n";
        }
        else if (!disponiblecolumn[i])
        {
            cout << "Entre al tercer if\n";
            cout << "fila: " << pos << '\n';
            cout << "columna: " << i << '\n';
            cout << "la columna " << i << " no esta disponible\n";
            for ( auto x : queens ) cout << x << ' ';
            cout << '\n';
            cin >> pause;
            cout << "------------------------------\n";
        }*/
    }
}

int main() 
{
    //IOS

    int caso = 1;
    while( 1 )
    {
        cin >> n;
        if ( n == 0 ) break;
        char caracter;
        invalid.clear();
        contador = 0;
        veces = 0;
        validaciones = 0;
        queens.assign(n, -1); disponiblecolumn.assign(n, true);
        invalid.assign(n, vector<int>(n));
        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {    
                cin >> caracter;
                invalid[i][j] = caracter == '*' ? 1 : 0; 
            }
        }
        /*cout << "Tablero al inicio\n";
        for (auto x : invalid)
        {
            for ( auto y : x ) cout << y;
            cout << '\n';
        }*/
        bt(0);
        cout << "Case " << caso++ << ": " << contador << '\n';
        cout << "numero de veces: " << veces << '\n';
        cout << "numero de validaciones: " << validaciones << '\n';
    }
    return 0;
}
