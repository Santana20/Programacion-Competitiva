#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 102
typedef long long ll;
const char nl = '\n';

vector<string> grid(MAXN);
bool used[MAXN][MAXN];

vector<int> dr = { 0, 0, 1, -1 }, dc = { 1, -1, 0, 0 };

bool is_alive_dfs(int row, int col, int & n)
{
    if ( row < 0 || row >= n || col < 0 || col >= n || used[row][col] || grid[row][col] == '.' ) return false;
    used[row][col] = true;

    bool alive = ( grid[row][col] == 'x' ) ? true : false;
    forin(op, 4)
    {
        bool aux = is_alive_dfs(row + dr[op], col + dc[op], n);
        if (alive) continue;
        alive = aux;
    }

    return alive;
}
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    //IOS
    int q; cin >> q;
    forin(i, q)
    {
        int n; cin >> n;

        memset(used, 0, sizeof(used));
        forin(row, n)
        {
            cin >> grid[row];
        }

        int ans = 0;

        forin(row, n)
            forin(col, n)
                if ( !used[row][col] )
                    ans += is_alive_dfs(row, col, n);  
        cout << "Case " << ( i + 1 ) << ": " << ans << nl;
    }
    
    //cerr << setprecision(3) << double(clock() - time) / CLOCKS_PER_SEC << nl;
    return 0;
}