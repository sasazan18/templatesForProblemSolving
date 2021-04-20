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



