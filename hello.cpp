#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 28
typedef long long ll;
const char nl = '\n';

ll comb(int n, int k)
{
    int n_k = n-k;

    ll ans = 1;
    for ( int i = 0; i < min(n_k, k); ++i )
    {
        ans = ans * ( n - i ) / ( i + 1 );
    }
    return ans;
}

int n, m;
vector<vector<bool>> used;
vector<string> grid, ans;
int ini_row, ini_col, fin_row, fin_col;
string aux = "IEHOVA#";

bool valid(int r, int c)
{
    if ( r >= 0 && r < n && c >= 0 && c < m && !used[r][c] ) return true;
    return false;
}

void dfs(int r, int c, int indice)
{
    if ( r == fin_row && c == fin_col )
    {
        return;
    }

    used[r][c] = true;

    if ( valid(r, c-1) && grid[r][c-1] == aux[indice] )
    {
        ans.push_back("left");
        dfs(r, c-1, indice + 1);
    }
    
    else if ( valid(r-1, c) && grid[r-1][c] == aux[indice] )
    {
        ans.push_back("forth");
        dfs(r-1, c, indice + 1);
    }

    else if ( valid(r, c + 1) && grid[r][c + 1] == aux[indice] )
    {
        ans.push_back("right");
        dfs(r, c + 1, indice + 1);
    }
    
    return;
}

int main()
{
    //freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    IOS
    
    int q; cin >> q;

    while (q--)
    {
        cin >> n >> m;
        grid.clear(); used.clear(); ans.clear();
        grid.resize(n); used.resize(n, vector<bool>(m, false));
        
        forin(row, n)
        {
            cin >> grid[row];
            forin(col, m)
            {
                if ( grid[row][col] == '@' )
                {
                    ini_row = row; ini_col = col;
                }

                else if ( grid[row][col] == '#' )
                {
                    fin_row = row; fin_col = col;
                }
            }
        }

        dfs(ini_row, ini_col, 0);

        forin( i, ans.size()-1 ) cout << ans[i] << ' ';
        cout << ans[(int)ans.size()-1] << nl;
    }
    
    
    return 0;
}