/*
It is very easier to calculate (a*b) mod m. But what if a<m, b<m but a*b is such large that we can’t store it in long long too. Such as,
 a=10^12 
b=10^12
m=10^15
So, a*b will overflow. 

This is why need the following approach to solve this

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod=10005412336548794;



ll MulviaAdd(ll a, ll b)
{
    if(b==1) return a;

    ll ret=0;

    if(b%2) ret= ret%mod + (a %mod + MulviaAdd(a,b-1)%mod ) % mod;
    else
    {
        ll temp=MulviaAdd(a,b/2) % mod ;

        ret=ret%mod + (temp + temp ) % mod;

    }

    ret%=mod;

    return ret;
}


int main()
{

    ll a,b;
    cin>>a>>b;

    cout<<MulviaAdd(a,b)<<endl;


    return 0;
}



