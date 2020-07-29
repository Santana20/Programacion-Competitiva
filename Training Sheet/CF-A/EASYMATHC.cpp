#include <bits/stdc++.h>
 
using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;
 
ll gcd(ll n1, ll n2)
{
    while( n2 != 0 )
    {
        ll tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}
 
 
ll lcm(ll a, ll b){
	return (a*b) / gcd(a, b);
}
 
int main()
{
    //IOS
    int t;
    cin >> t;
    while ( t-- )
    {
        ll lo,hi, a, d;
        cin >> lo >> hi >> a >> d;
 
        vector<ll> nums(5);
        
        for( int i = 0; i < 5; ++i )
        {
            nums[i] = (ll)i*d + a;
        }
 
        ll divs = 0; ll rango = (hi - lo + 1);
        for( int mask = 1; mask < (1 << 5); ++mask )
        {
            ll auxdivs = 0;
            ll current = 1;
            int contador = 0;
            for(int i = 0; i < 5; ++i)
            {
                if((mask >> i) & 1)
                {
                    current = lcm(current, nums[i]);
                    ++contador;
                }
            }
/*
            int inicio = lo / current;
            if ( lo % current ) ++inicio;
 
            for(inicio = inicio * current; inicio <= hi; inicio += current )
            {
                ++auxdivs;
            }
*/
            if ( contador & 1 ) 
            {
                divs +=( ( hi / current ) - (lo-1)/current ); 
            }
            else 
            {
                divs -=( ( hi / current ) - (lo-1)/current ); 
            }
        }
 
        
        cout << (rango - divs ) << '\n';
    }
    return 0;
}  