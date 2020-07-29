#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

const char nl =  '\n';

vector<int> valores(20001, 0);
vector<bool> visited(20001, false);
queue<int> q;

void bfs(int ini, int target)
{
    q.push(ini);

    while( !q.empty() )
    {
        int aux = q.front(); q.pop();
        visited[aux] = true;

        if ( (aux - 1) > 0 && !visited[aux - 1] )
        {
            q.push(aux - 1);
            valores[aux - 1] = valores[aux] + 1;
            if ( (aux - 1) == target ) break;
        }
        if ( (aux * 2) <= 20001 && !visited[aux * 2] )
        {
            q.push(aux * 2);
            valores[aux * 2] = valores[aux] + 1;
            if ( (aux * 2) == target ) break;
        }
    }
}

int main()
{
    //IOS
    int desde, hasta;
    cin >> desde >> hasta;

    bfs(desde, hasta);
    cout << valores[hasta];
    
    return 0;
}
