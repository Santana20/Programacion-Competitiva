#include <bits/stdc++.h>

using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool salir;
int conf[4][4], disp_col[4][5], disp_row[4][5], disp_reg[2][2][5];

void print_conf()
{
    for ( int i = 0; i < 4; ++i )
    {
        for ( int j = 0; j < 4; ++j )
        {
            cout << conf[i][j];
        }
        cout << '\n';
    }
}

void bt(int row, int col)
{
    if ( salir ) return;

    if ( row == 3 && col == 4 )
    {
        print_conf();
        salir = true;
        return;
    }
    
    else if ( col == 4 )
    {
        bt(row + 1, 0);
        return;
    }

    
    if ( conf[row][col] != 0 )
    {
        bt(row, col + 1);
        return;
    }

    for ( int op = 1; op <= 4; ++op  )
    {
        if ( disp_col[col][op] && disp_row[row][op] && disp_reg[(int)row/2][(int)col/2][op] )
        {
            conf[row][col] = op;
            disp_col[col][op] = 0;
            disp_row[row][op] = 0;
            disp_reg[row/2][col/2][op] = 0;

            bt(row, col + 1);

            conf[row][col] = 0;
            disp_col[col][op] = 1;
            disp_row[row][op] = 1;
            disp_reg[row/2][col/2][op] = 1;
            
            if (salir) break;
        }
    }


       
}

int main()
{
    //IOS
    

    int n; cin >> n;

    for ( int i = 1; i <= n; ++i )
    {
        memset(conf, 0, sizeof(conf));
        memset(disp_col, 1, sizeof(disp_col));
        memset(disp_row, 1, sizeof(disp_row));
        memset(disp_reg, 1, sizeof(disp_reg));
        char car;
        salir = false;
        for ( int i = 0; i < 4; ++i )
        {
            string s;
            cin >> s;
            for ( int j = 0; j < 4; ++j )
            {
                if ( s[j] == '*' )
                {
                    conf[i][j] = 0;
                }
                else
                {
                    int aux = int(s[j] - '0');
                    conf[i][j] = aux;
                    disp_col[j][aux] = 0;
                    disp_row[i][aux] = 0;
                    disp_reg[i/2][j/2][aux] = 0;
                }
                
            }
        }
        cout << "Case #" << i << ":\n";
        bt(0,0);
    }
    
    return 0;
}