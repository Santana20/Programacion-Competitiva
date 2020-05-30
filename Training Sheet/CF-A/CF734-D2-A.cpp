#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS

    int contA = 0, contD = 0;
    int n; cin >> n;
    char result;

    for ( int i  = 0; i < n; ++i )
    {
        cin >> result;
        if ( result == 'A' ) contA++;
        else contD++;
    }

    if ( contA == contD ) cout << "Friendship";
    else if ( contA > contD ) cout << "Anton";
    else cout << "Danik";
    return 0;
}