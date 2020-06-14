#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    //IOS
    
    int t;
    cin >> t;

    while ( t-- )
    {
        string s;
        cin >> s;

        int i, contador = 0;
        forin(i, ((int)s.size() - 1 ))
        {
            if ( ( s[i] == 'x' && s[i+1] == 'y' ) ||
                  ( s[i] == 'y' && s[i+1] == 'x' )   )
            {
                ++i;
                ++contador;
            }
        }

        cout << contador << '\n';
    }
    return 0;
}