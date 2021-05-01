
///A CRT solver which works even when moduli are not pairwise co prime



#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector< pair<ll,ll> > equation ;  /// this will contain the value of a and m


ll mul ( ll a , ll b , ll MOD )
{
    return (a%MOD * b%MOD ) % MOD;
}

ll add ( ll a, ll b, ll MOD )
{
        return (a%MOD + b%MOD ) % MOD;
}

ll egcd(ll a, ll b , ll &x ,ll &y)
{

    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    ll x1,y1;

    ll d= egcd( b,a%b,x1,y1 ) ;
    x=y1;
    y=x1- y1 * (a/b);

    return d;


}


pair<ll,ll> CRT()  /// it will return a  {x, N} pair, where x is the unique solution modulo N.
{

    if(equation.size()==0)  return {-1,-1}; ///No equations to solve

    ll a1= equation[0].first;
    ll m1= equation[0].second;

    a1%=m1;

     /** Initially x = a1 (mod m1)**/

    /** merging the solution with the remaining equatuions **/


   for(int i=1;i<equation.size();i++)
   {

       ll a2= equation[i].first;
       ll m2= equation[i].second;

       ll g= __gcd(m1,m2);

       if(a1%g!=a2%g) return {-1,-1} ; // conflict in equation

       /** Merge the two equations **/

       ll p,q;

       ll gcd=egcd(m1/g, m2/g, p, q);

       ll MOD= m1/g * m2 ; /// lcm(m1,m2)

       ll x =add(   mul( mul(a1,m2/g,MOD) , q ,MOD ) ,  mul( mul(a2,m1/g,MOD) , p ,MOD ) , MOD);

       ///Merged equation

       a1=x;

       if(a1<0) a1+=MOD;

       m1=MOD;


   }


   return {a1,m1};




}


int main()
{

     int n;
     cin>>n;

     for(int i=0;i<n;i++)
     {
         int x,y;

         cin>>x>>y;  //taking input of x and y

         equation.push_back({x,y});
     }


     pair<ll,ll> p = CRT();

     cout<<p.first<<endl;









    return 0;
}
