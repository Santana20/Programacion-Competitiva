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
    while( t-- )
    {
        int n, row; cin >> n;
        forin(row, n)
        {
            if ( row % 2 == 0 )
            {
                for( int i = row * n + 1; i <= ( ( row + 1 ) * n ); ++i )
                    cout << i << ' ';
            }
            else
            {
                for( int i = ( ( row + 1 ) * n ); i >= ( row * n )+ 1; --i )
                    cout << i << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}