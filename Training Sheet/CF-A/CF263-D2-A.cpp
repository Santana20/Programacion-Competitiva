#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    IOS
    int moves, Fans, Cans, aux;

    for ( int i = 1; i <= 5; ++i )
    {
        for ( int j = 1; j <= 5; ++j )
        {
            cin >> aux;
            if (aux) 
            {
                Fans = i; Cans = j;
            }
        }
    }
    moves = ( abs(Fans-3) + abs(Cans - 3) );
    cout << moves;
    return 0;
}