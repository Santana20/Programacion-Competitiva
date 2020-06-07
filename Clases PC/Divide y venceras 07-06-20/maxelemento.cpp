#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

vector<int> A;
int max_elem(int ini, int fin)
{
    if ( ini == fin ) return A[fin];

    int mi = (ini + fin) / 2;
    //     maximo( mayor sub-prob 1 , mayor sub-prob 2 )
    return max( max_elem( ini, mi ), max_elem( mi + 1, fin ) ); 
}

int main()
{
    //IOS
    
    int n, i;
    cin >> n;
    A.assign(n, 0);
    forin ( i, n ) cin >> A[i];

    cout << max_elem(0, n - 1 );
    return 0;
}