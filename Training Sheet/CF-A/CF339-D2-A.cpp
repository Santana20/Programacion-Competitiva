#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    
    string s; map<char, int> symbs;

    cin >> s;

    for ( char x : s )
    {   
        symbs[x]++;
    }

    for ( auto x : symbs )
    {
        if ( x.first == '+' ) continue;

        for ( int i = 0; i < x.second; ++i )
        {
            cout << x.first;
            if ( symbs['+'] > 0 )
            {
                cout << '+';
                --symbs['+'];
            }
        }
    }
    return 0;
}