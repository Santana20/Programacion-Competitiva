#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int conf[9][9], disp_col[9][10], disp_row[9][10], disp_reg[3][3][10];


void print_conf()
{
    for ( int i = 0; i < 9; ++i )
    {
        for ( int j = 0; j < 9; ++j )
        {
            cout << conf[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bt(int row, int col)
{
    if ( row == 8 && col == 9 )
    {
        print_conf();
        return;
    }
    if ( col == 9 )
    {
        bt(row + 1, 0);
        return;
    }

    for ( int op = 1; op <= 9; ++op )
    {
        if ( disp_col[col][op] && disp_row[row][op] && disp_reg[row/3][col/3][op] )
        {
            conf[row][col] = op;
            disp_col[col][op] = 0;
            disp_row[row][op] = 0;
            disp_reg[row/3][col/3][op] = 0;

            bt(row, col + 1);
            
            disp_col[col][op] = 1;
            disp_row[row][op] = 1;
            disp_reg[row/3][col/3][op] = 1;
            conf[row][col] = -1;
        }
        
    }

}

int main() 
{
    memset(conf, -1, sizeof(conf));
    memset(disp_col, 1, sizeof(disp_col));
    memset(disp_row, 1, sizeof(disp_row));
    memset(disp_reg, 1, sizeof(disp_reg));
    bt(0, 0);
    return 0;
}