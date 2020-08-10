#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 100005
typedef long long ll;
const char nl = '\n';

int is_two[MAXN], is_four[MAXN], is_eight[MAXN];


int main()
{
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //IOS
    memset(is_two, 0, sizeof(is_two));
    memset(is_four, 0, sizeof(is_four));
    memset(is_eight, 0, sizeof(is_eight));

    map<int, int> dic;
    set<int> two, four, eight;
    int n; cin >> n;

    forin(i, n)
    {
        int aux; cin >> aux;
        dic[aux]++;
        if ( is_two[aux] == 0 && dic[aux] >= 2 && dic[aux] < 4 ) 
        {
            is_two[aux] = 1;
            two.insert(aux);
        }

        if ( is_four[aux] == 0 && dic[aux] >= 4 && dic[aux] < 8 )
        {
            is_four[aux] = 1; is_two[aux] = 0;
            four.insert(aux); two.erase(aux);
        }

        if ( is_eight[aux] == 0 && dic[aux] >= 8 )
        {
            is_eight[aux] = 1; is_four[aux] = 0;
            eight.insert(aux); four.erase(aux);
        }
    }
    
    int q; cin >> q;
    //cout << (int)eight.size() << nl;
    //for(auto x : eight) cout << x << ' ';
    //cout << nl;
    //cout << (int)four.size() << nl;
    //for(auto x : four) cout << x << ' ';
    //cout << nl;
    //cout << (int)two.size() << nl;
    //for(auto x : two) cout << x << ' ';
    //cout << nl;
    while (q--)
    {
        char op; int aux;
        cin >> op >> aux;

        if ( op == '+' )
        {
            dic[aux]++;
        if ( is_two[aux] == 0 && dic[aux] >= 2 && dic[aux] < 4 ) 
        {
            is_two[aux] = 1;
            two.insert(aux);
        }

        if ( is_four[aux] == 0 && dic[aux] >= 4 && dic[aux] < 8 )
            {
                is_four[aux] = 1; is_two[aux] = 0;
                four.insert(aux); two.erase(aux);
            }

            if ( is_eight[aux] == 0 && dic[aux] >= 8 )
            {
                is_eight[aux] = 1; is_four[aux] = 0;
                eight.insert(aux); four.erase(aux);
            }
        }
        else
        {
            dic[aux]--;
            if ( is_eight[aux] && dic[aux] < 8 )
            {
                is_eight[aux] = 0; is_four[aux] = 1;
                eight.erase(aux); four.insert(aux);
            }
            else if ( is_four[aux] && dic[aux] < 4 )
            {
                is_four[aux] = 0; is_two[aux] = 1;
                four.erase(aux); two.insert(aux);
            }
            else if ( is_two[aux] && dic[aux] < 2 )
            {
                is_two[aux] = 0; two.erase(aux);
            }
        }

        //cout << (int)eight.size() << nl;
        //for(auto x : eight) cout << x << ' ';
        //cout << nl;
        //cout << (int)four.size() << nl;
        //for(auto x : four) cout << x << ' ';
        //cout << nl;
        //cout << (int)two.size() << nl;
        //for(auto x : two) cout << x << ' ';
        //cout << nl;


        if ( (int)eight.size() >= 1 )cout << "YES";
        else
        {
            if ( (int)four.size() >= 2 ) cout << "YES";
            else
            {
                if ( (int)four.size() == 1 )
                {
                    if ( (int)two.size() >= 2 ) cout << "YES";
                    else
                    {
                        auto x = four.begin();

                        if ( dic[(*x)] - 4 >= 2 && (int)two.size() >= 1 ) cout << "YES";
                        else cout << "NO";
                    }
                    
                }
                else cout << "NO";
            }
            
        }
        cout << nl;
    }
    
	return 0;
}