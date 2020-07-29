#include <iostream>
#include <vector>
using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
typedef long long ll;
const char nl = '\n';

vector<ll> nums;
int main()
{
    //IOS
    
    int n; cin >> n;
    ll resp = 1;
    nums.resize(n); bool cero = false;
    forin(i, n)
    {
        cin >> nums[i];
        if ( nums[i] == 0 ) cero = true;
    }

    if (cero) cout << '0' << nl;
    else
    {
        forin(i, n)
        {
            if ( resp <= ( 1000000000000000000 / nums[i] ) )
            {
                resp = resp * nums[i];
            }
            else
            {
                printf("-1");
                return 0;
            }
        }
        cout << resp << nl;
    }
    
    return 0;
}
