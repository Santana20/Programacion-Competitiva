#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS

    int numero;
    cin >> numero;

    int x = numero % 10;

    if ( x == 0 || x == 1 || x == 6 || x == 8 ) cout << "pon";
    else if ( x == 3 ) cout << "bon";
    else cout << "hon";

    return 0;
}
