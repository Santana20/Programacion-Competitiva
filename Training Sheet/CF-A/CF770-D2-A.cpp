#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    
    int n, k, letter = 97;
    cin >> n >> k;
    for ( int i = 0, aux = 0; i < n; ++i, ++aux )
    {
        aux = aux % k;
        cout << (char)(letter + aux);
    }
    return 0;
}