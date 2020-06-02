#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int contador, n;
vector<int> queens; vector<vector<int>> invalid; 
vector<bool> disponiblecolumn, disp_diago1, disp_diago2;
/*void pintartablero(int pos, int caracter)
{
    int faux = pos, caux = queens[pos], i = 1;
    while ( ( faux + i ) < n)
    {
        validaciones++;
        if ( caux + i < n ) invalid[faux + i][caux + i] += caracter;
        if ( caux - i >= 0 ) invalid[faux + i][caux - i] += caracter;
        ++i;
    }
}*/

void bt(int pos)
{
    if ( pos == n )
    {
        contador++;
        return;
    }

    for ( int i = 0; i < n; ++i )
    {
        if ( disponiblecolumn[i] && invalid[pos][i] == 0 
           && disp_diago1[i+pos] && disp_diago2[i - pos + n - 1] )
        {
            queens[pos] = i;
            disponiblecolumn[i] = false;
            disp_diago1[i+pos] = false;
            disp_diago2[i - pos + n - 1] = false;
            
            bt(pos + 1);

            disponiblecolumn[i] = true;
            disp_diago1[i+pos] = true;
            disp_diago2[i - pos + n - 1] = true;
            queens[pos] = -1;
        }
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
        contador = 0;

        queens.assign(n, -1); disponiblecolumn.assign(n, true);
        disp_diago1.assign(2*n, true); 
        disp_diago2.assign(2*n, true);
        invalid.assign(n, vector<int>(n));

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {    
                cin >> caracter;
                invalid[i][j] = caracter == '*' ? 1 : 0; 
            }
        }
        bt(0);
        cout << "Case " << caso++ << ": " << contador << '\n';
    }

    return 0;
}
