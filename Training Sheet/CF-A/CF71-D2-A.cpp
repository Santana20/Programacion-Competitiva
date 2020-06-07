#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    //IOS
    
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;

        if ( s.length() > 10 ) cout << s[0] << ( s.length() - 2 ) << s[s.length()-1];
        else cout << s;
        cout << '\n';
    }

    return 0;
}