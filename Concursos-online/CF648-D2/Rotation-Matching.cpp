#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for ( int i = 0; i < n; ++i )
typedef long long ll;

const int MAX_N = 2e5 + 1;
vector<int> pos(MAX_N);
map<int, int> cont;
int main()
{
    //IOS
    
    int i, n, aux, match = 0; cin >> n;
    forn(i, n)
    {
        cin >> aux;
        pos[aux] = i;
    }

    forn(i, n)
    {
        cin >> aux;
        int diff = pos[aux] - i;
        if ( diff < 0 ) diff += n;

        cont[diff]++;
    }

    for (auto x : cont)
    {
        match = max(match, x.second);
    }

    cout << match;
    return 0;
}