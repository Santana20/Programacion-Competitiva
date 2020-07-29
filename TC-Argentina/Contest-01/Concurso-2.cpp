#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

bool is_period(string s, int p)
{
    int n = (int)s.size() - p;

    for( int i = 0; i < n; ++i )
    {
        if ( !( s[i] != '.' && s[i+p] != '.' && s[i] == s[i+p] ) ) return false;
    }

    return true;
}

int main()
{
    int n, p;
    string s;
    cin >> n >> p >> s;

    if ( is_period(s, p) ) cout << "No";
    else
    {
        for( int i = 0; i < n - p; ++i )
        {
            if ( s[i] == '.' )
            {
                if ( s[i+p] == '0' ) s[i] = '1';
                else if ( s[i+p] == '1' ) s[i] = '0';
                else
                {
                    s[i] = '0'; s[i+p] = '1';
                }
                
                break;
            }
            else if ( s[i+p] == '.' )
            {
                if ( s[i] == '0' ) s[i+p] = '1';
                else if ( s[i] == '1' ) s[i+p] = '0';
                else
                {
                    s[i] = '0'; s[i+p] = '1';
                }
                break;
            }
        }

        for ( int i = 0; i < n; ++i ) if ( s[i] == '.' ) s[i] = '0';

        cout << s;
    }
    

    return 0;
}