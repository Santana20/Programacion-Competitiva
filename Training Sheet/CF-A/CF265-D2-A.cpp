#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    
    string inst, rocks; int ans = 0;

    cin >> rocks >> inst;

    for ( auto x : inst )
    {
        if ( x == rocks[ans] ) ++ans;
    }
    cout << ( ans + 1 );
    return 0;
}