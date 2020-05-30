#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS
    
    int n;
    cin >> n;
    vector<int> columnas(n, -1);
    for ( int &x : columnas ) cin >> x;
    sort(columnas.begin(), columnas.end());

    for ( auto x : columnas ) cout << x << ' ';
    return 0;
}