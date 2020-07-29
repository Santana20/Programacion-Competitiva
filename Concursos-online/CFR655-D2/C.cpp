#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    IOS
    
    int t; cin >> t;
    while ( t-- )
    {
        int n; cin >> n;
        
        int i;
        int fal_groups = 0;
        bool falsos = true, fix = false;;
        forin( i, n )
        {
            int aux; cin >> aux;
            if (fix) continue;
            if (falsos && (i+1) != aux)
            {
                ++fal_groups;
                falsos = false;
                if (fal_groups == 2) fix = true;
            }
            else if ((i+1) == aux)
            {
                falsos = true;
            }
            
        }

        cout << fal_groups << '\n';
    }
    

    return 0;
}