#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int contador; pair<int, int> queenkey; 
vector<int> queens; vector<bool> disponiblefila;
bool esvalido(int pos, int candidato)
{
    if ( pos != 0 )
    {
        for ( int i = 0; i < pos; ++i )
        {
            if ( abs( candidato - queens[i] ) == abs(pos - i) ) 
            {
                return false;
            }
        }
    }
    
    if ( abs( candidato - queenkey.first ) == abs(pos - queenkey.second) ) return false;
    return true;
}

void bt(int column)
{
    if ( column == 8 )
    {
        printf("%2d      ", contador++);
		printf("%d", queens[0] + 1);
		for (int i = 1; i < 8; i++)
			printf(" %d", queens[i] + 1);
		puts("");
    }

    if ( column != queenkey.second )
    {
        for ( int row = 0; row < 8; ++row )
        {
            if ( disponiblefila[row] && esvalido(column, row) )
            {
                disponiblefila[row] = false;
                queens[column] = row;
                bt(column + 1);
                disponiblefila[row] = true;
                queens[column] = -1;
            }
        }
    }
    else bt(column + 1);    
}


int main() 
{
    //IOS

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> queenkey.first >> queenkey.second;
        queenkey.first--; queenkey.second--;
        contador = 1;
        queens.assign(8, -1);
        disponiblefila.assign(8, true);
        disponiblefila[queenkey.first] = false;
        queens[queenkey.second] = queenkey.first;

        if(i) cout << '\n';
        printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
        //quitarl los clock_t, solo es para medir el tiempo.
        clock_t ini = clock();
        bt(0);
        clock_t fin = clock();
        //estas 2 ultimas lienas tamien borrar.
        double tiempo = (double) (fin - ini) / CLOCKS_PER_SEC;
        cout << "run time: " << tiempo << '\n';
    }
    return 0;
}
