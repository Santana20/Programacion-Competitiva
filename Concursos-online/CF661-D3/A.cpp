#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 100005
typedef long long ll;
const char nl = '\n';

multiset<int> sums;
int used[MAXN];
int suma;
void dfs(int nodo, vector<vector<pair<int, int>>> & graph)
{
    used[nodo] = 1;

    for(auto v : graph[nodo])
    {
        if ( !used[v.first] )
        {
            sums.insert(v.second);
            suma += v.second;
            dfs(v.first, graph);
        }
    }

    return;
}

void solve()
{
    int n, target; cin >> n >> target;

    memset(used, 0, sizeof(used));
    sums.clear(); suma = 0;
    vector<vector<pair<int, int>>> graph(n);
    int ans = 0;
    
    forin(i, n-1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    for ( int i = 0; i < n; ++i )
    {
        if (!used[i]) dfs(i, graph);
    }
    
    for(auto x : sums) cout << x << ' ';
    cout << nl;

    while ( suma > target )
    {
        ans++;
        int aux = (*sums.rbegin());

        sums.erase(sums.find(aux));

        suma -= (aux / 2) + ( aux % 2 ? 1 : 0);

        aux /= 2;
        sums.insert(aux);
    }

    cout << ans << nl;

}

int main()
{
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    IOS
    int q; cin >> q;
    while(q--)
    {
        solve();
    }
	return 0;	
}