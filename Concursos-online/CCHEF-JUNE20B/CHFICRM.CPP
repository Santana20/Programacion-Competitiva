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
        int n, i, chef5= 0, chef10=0; cin >> n;
        vector<int> queue(n); int current; bool dec = true;
        forin(i, n)
        {
            cin >> current;
            if ( !dec ) continue;

            int vuelto = current - 5;
            if ( vuelto == 0 ) 
            {
                chef5++;
                continue;
            }
            else if ( vuelto == 5 ) //recibo 10
            {
                if ( chef5 >= 1 )
                {
                    chef10++; 
                    chef5--; 
                } 
                else dec = false; 
            }
            else
            {
                if ( chef10 >= 1 ) chef10--;
                else if ( chef5 >= 2 ) chef5 -=2;
                else dec = false;
            }

        }

        cout << ( dec ? "YES" : "NO" ) << '\n';
    }
    return 0;
}