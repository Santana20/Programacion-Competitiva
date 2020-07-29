#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;


class BagPacking
{
private:
public:
    int minPay(vector <int> bagsizes)
    {
        if ( (int)bagsizes.size() == 1 ) return 1;
        vector<bool> status((int)bagsizes.size(), false);

        sort(bagsizes.begin(), bagsizes.end());

        bool dec; int cont = 0;
        do
        {
            int aux = -1; dec = false;
            for ( int i = 0; i < (int)bagsizes.size(); ++i )
                if ( !status[i] )
                {
                    aux = i; break;
                } 
            
            if ( aux == -1 ) break;

            for ( int i = 1; i < (int)bagsizes.size(); ++i )
            {
                if ( !status[i] && (bagsizes[i] > bagsizes[aux]) )
                {
                    status[i] = status[aux] = true;
                    aux = i;
                    dec = true;
                }
            }
            if ( dec ) ++cont;
        } while (dec);
        
        for ( int i = 0; i < (int)bagsizes.size(); ++i )
                if ( !status[i] )
                {
                    ++cont;
                } 

        return cont;
    }
};



int main()
{
    //IOS
    
    vector <int> bagsizes ={2,2};

    cout << minPay(bagsizes);
    return 0;
}