#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS
    int n, writes = 0;;
    cin >> n;
    for ( int i = 0; i < n; ++i )
    {
        int auxcont = 0, input;
        for ( int j =  0;  j < 3; ++j )
        {
            cin >> input;
            if ( input ) ++auxcont;
        }
        if ( auxcont >= 2 ) ++writes;
    }

    cout << writes;
    return 0;
}