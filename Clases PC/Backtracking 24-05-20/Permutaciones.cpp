#include <bits/stdc++.h>
using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int conf[10], n;
vector<bool> disponible;
void bt(int pos)
{
    if ( pos == n )
    {
        for ( int i = 0; i < n; ++i ) cout << conf[i] << ' ';
        cout << '\n';
        return;
    }
    for ( int j = 0; j < n; ++j )
    {
        if ( disponible[j] )
        {
            conf[pos] = j + 1;
            disponible[j] = false;
            bt(pos + 1);
            disponible[j] = true;
        }
    }
}

int main()
{
    IOS
    
    cin >> n;
    disponible.assign(n, true);
    bt(0);
    
    return 0;
}