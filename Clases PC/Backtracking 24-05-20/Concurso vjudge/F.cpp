#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool salir; int n;
int conf[9][9], disp_col[9][10], disp_row[9][10], disp_reg[3][3][10];

void print_conf()
{
    for ( int i = 0; i < (n * n); ++i )
    {
        for ( int j = 0; j < (n * n) - 1; ++j )
        {
            cout << conf[i][j] << ' ';
        }
        cout << conf[i][(n * n) - 1] << '\n';
    }
}

void bt(int row, int col)
{
    if ( salir ) return;

    if ( row == (n * n) - 1 && col == n * n )
    {
        print_conf();
        salir = true;
        return;
    }
    
    else if ( col == n * n )
    {
        bt(row + 1, 0);
        return;
    }

    
    if ( conf[row][col] != 0 )
    {
        bt(row, col + 1);
        return;
    }

    for ( int op = 1; op <= ( n * n ); ++op  )
    {
        if ( disp_col[col][op] && disp_row[row][op] && disp_reg[row/n][col/n][op] )
        {
            conf[row][col] = op;
            disp_col[col][op] = 0;
            disp_row[row][op] = 0;
            disp_reg[row/n][col/n][op] = 0;

            bt(row, col + 1);

            conf[row][col] = 0;
            disp_col[col][op] = 1;
            disp_row[row][op] = 1;
            disp_reg[row/n][col/n][op] = 1;
            
            if (salir) break;
        }
    }


       
}

int main()
{
    //IOS
    bool line = false;
    while (cin >> n)
    {
        memset(conf, 0, sizeof(conf));
        memset(disp_col, 1, sizeof(disp_col));
        memset(disp_row, 1, sizeof(disp_row));
        memset(disp_reg, 1, sizeof(disp_reg));

        salir = false;
        for ( int row = 0; row < (n * n); ++row )
        {
            for ( int col = 0; col < (n * n); ++col )
            {
                cin >> conf[row][col];
                if ( conf[row][col] )
                {
                    int aux = conf[row][col];
                    disp_col[col][aux] = 0;
                    disp_row[row][aux] = 0;
                    disp_reg[row/n][col/n][aux] = 0;
                }
            }
        }

        if ( line ) cout << '\n';
        else line = true;

        bt(0,0);
        if (!salir) cout << "NO SOLUTION\n";
    }
    
    return 0;
}