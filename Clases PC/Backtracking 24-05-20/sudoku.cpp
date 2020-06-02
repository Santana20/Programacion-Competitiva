#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<vector<int>> conf;
void print_conf()
{
    for(auto fila : conf)
    {
        for( int x : fila )
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bt(int row, int col)
{
    if ( row == 9 && col == 9 )
    {
        print_conf();
        return;
    }
    if ( col == 9 )
    {
        bt(row + 1, 0);
        return;
    }
    for(int op=1; op <=9; ++op)
    {
        conf[row][col] = op;
        bt(row, col + 1);
    }

}

int main() 
{
    //IOS
    conf.assign(9, vector<int>(9, -1));
    bt(0, 0);
    return 0;
}