#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    
    int a, b, poss;
    cin >> a >> b;
    a = max(a, b);
    poss = 6 - a + 1;

    if ( poss == 4 ) cout << "2/3";
    else if ( poss == 5 ) cout << "5/6";
    else
    {
        cout << 1 << '/' << (6/poss);
    }
     
    return 0;
}