#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( i = 0; i < n; ++i )
typedef long long ll;

int main()
{
    //IOS
    
    int n, i, aux; vector<int> ones, two, three;

    cin >> n;
    forn(i, n)
    {
        cin >> aux;
        if ( aux == 1 ) ones.push_back(i + 1);
        else if ( aux == 2 ) two.push_back(i + 1);
        else three.push_back(i+1);
    }

    n = min ( (int)ones.size(), min((int)(two.size()), (int)three.size() ) );
    cout << n << '\n';
    forn(i, n)
    {
        cout << ones[i] << ' ' << two[i] << ' ' << three[i] << '\n';
    }
    return 0;
}