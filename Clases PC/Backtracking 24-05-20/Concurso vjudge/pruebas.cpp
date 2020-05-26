/*
Nombre del problema: Sum It Up
*/
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main()
{
    
    set<string> arreglo;

    arreglo.insert("4");
    arreglo.insert("3+1");
    arreglo.insert("2+2");
    arreglo.insert("2+1+1");
    arreglo.insert("2+1+1");

    for ( auto x : arreglo ) cout << x << endl;
    cout << endl;
    for ( auto rit = arreglo.rbegin(); rit != arreglo.rend(); ++rit )
        cout << *rit << endl;
    return 0;
}