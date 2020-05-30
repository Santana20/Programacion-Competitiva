#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    //IOS
    
    string s; set<int> distinc;

    getline(cin, s);

    for ( char x : s )
    {
        int aux = (int)x;
        if ( aux >= 97 && aux <= 122 ) distinc.insert(aux);
    }

    cout << distinc.size();
    return 0;
}