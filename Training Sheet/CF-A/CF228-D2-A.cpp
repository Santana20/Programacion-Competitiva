#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    set<int> colors; int aux;

    for ( int i = 0; i < 4; ++i )
    {
        cin >> aux;
        colors.insert(aux);
    }

    cout << ( 4 - colors.size() );

    return 0;
}