#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  printf("%d",x);
#define pl(x)  printf("%lld",x);
#define pf(x)  printf("%.10lf",x);
#define ps(x)  printf("%s",x);
#define en() printf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define sp(x) fixed<<setprecision(x)
#define mod 1000000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}


int main()
{
	
	
	
	
	return 0;
}





////////
sieve 
///////


bitset<10000005>vis;
vector<int>prime;


void sieve()
{
    vis[1]=1;
    vis[0]=1;
    for(int i=3;i*i<=10000000;i+=2)
    {
        if(!vis[i]){

        for(int j=i*i;j<=10000000;j+=i)
        {
            vis[j]=1;

        }
        }
    }
    prime.pb(2);
    for(int i=3;i<=10000000;i+=2)
    {
        if(!vis[i]) prime.pb(i);
    }
}


//primeFactorize


vector<pii> primeFactorize( int n )
{
    vector<pii>List;
    int sqrtN = int( sqrt(n) );
    for( int i = 0; prime[i] <= sqrtN; i++ )
    {
        if( n % prime[i] == 0 )
        {
            int cnt=0;

            while( n % prime[i] == 0 )
            {
                n /= prime[i];
                cnt++;

            }

            List.pb({prime[i],cnt});

        }
    }
    if( n > 1 )
    {

        List.pb({n,1}) ;

    }

    return List;

}



































