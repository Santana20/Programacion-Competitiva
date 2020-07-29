#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    //IOS

    int animals, legs;
    cin >> animals >> legs;

    int turtles, cranes;

    if ( ( legs % 4 == 0 && (legs / 4) == animals ) || ( legs % 2 == 0 && (legs / 2) == animals ) ) cout << "Yes\n";
    else
    {
        int turtles, cranes; bool dec = false;
        for( turtles = ( legs / 4 ); turtles > 0; --turtles )
        {
            cranes = legs - ( turtles * 4 );
            if ( (cranes & 1) == 0 && cranes > 0 ) cranes /= 2;
            else continue;

            if ( cranes + turtles == animals )
            {
                dec = true; break;
            }
        }

        cout << ( dec ? "Yes" : "No" ) << '\n';
    }

    return 0;
}