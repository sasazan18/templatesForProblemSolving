#include<bits/stdc++.h>
using namespace std;
#define mxn 1000005
int lp[mxn+1]; //least prime
vector<int>prime;


void linear_sieve(){
    for (int i = 2; i <= mxn; i++)
    {
        if(lp[i]==0){
            lp[i]=i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size() && i*prime[j]<=mxn && prime[j]<=lp[i]  ; ++j ){
            lp[i*prime[j]]=prime[j];
            //we cut each number only once!
            //we will store the least prime for each number.
            //prime[j]<=lp[i] for the case where we might store a prime for a number which is not least!
            //ex : i=6, prime--2,3,5 
            //we might do this-- 12=2,18=3,30=5 but for 18 and 30 it should be 2.
        }
    }
    
}



//PRIME FACTORIZATION USING LINEAR SIEVE

vector<int> primefactorization(int n){
    vector<int>pf;
    while(n>1){
        pf.push_back(lp[n]);
        n/=lp[n];
    }   

    return pf;   
}





int main(){
    linear_sieve();
    vector<int>pf  = primefactorization(124);
}
