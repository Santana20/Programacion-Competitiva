#include <bits/stdc++.h>

using namespace std; 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( i = 0; i < (int)n; ++i )
typedef long long ll;

int searchRecursivo(int A[], int lo, int hi, int t)
{
    if ( lo == hi )
    {
        if ( A[lo] == t ) return lo;
        else return -1;
    }

    int mi = lo + (hi-lo) / 2;

    if ( A[mi] < t ) return searchRecursivo(A, mi + 1, hi, t);
    return searchRecursivo(A, lo, mi, t);
}



int searchIterativo(int A[], int lo, int hi, int t)
{
    while( lo < hi )
    {
        int mi = lo + (hi-lo) / 2;

        if( A[mi] < t ) lo = mi + 1;
        else hi = mi;
    }
    if ( A[lo] == t ) return lo;
    else return -1;
}

int main()
{
    //IOS
    
    
    return 0;
}