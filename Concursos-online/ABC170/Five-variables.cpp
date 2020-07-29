#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int main()
{
    //IOS

    int i, aux, pos;

    forin(i, 5)
    {
        cin >> aux;
        if ( aux == 0 ) pos = i + 1; 
    }

    cout << pos;
    return 0;
}