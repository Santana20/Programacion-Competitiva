#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    //IOS
    
    int t; cin >> t;
    while ( t-- )
    {
        int n, m;
        cin >> n >> m;
        vector<bool> disp_row(n, true), disp_col(m, true);
        int i, j, contador = 0;
        forn(i, n)
        {
            forn(j, m)
            {
                int aux; cin >> aux;
                if ( aux )
                {
                    disp_row[i] = false;
                    disp_col[j] = false;
                }
            }
        }

        forn(i, n)
        {
            forn(j, m)
            {
                if ( disp_row[i] && disp_col[j] ) 
                {
                    contador++;
                    disp_row[i] = false; disp_col[j] = false;
                }
            }
        }

        cout << ( ( contador & 1 ) ? "Ashish" : "Vivek" ) << '\n'; 
    }

    return 0;
}