#include<iostream>
#include<fstream>
#include<climits>
#include<vector>
#include<string>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
#include<map>
#include <set>
#include <queue>
#include <stack>
#define ll long long
#define sil(x)  int x;in>>x;while(x--)
#define sid(n)   int n;in>>n
#define si(x) in>>x
#define s(x) string x;in>>x;
#define fl(m,n) for(  int i=m;i<n;i++)
#define flr(n,m) for( int i=n;i>=m;i--)
#define wl(q) while(q--)
#define P(A,B) std::pair<A,B>
#define V(A) std::vector<A>
#define pb push_back
V(int) primes;
void seive(){V(int) isPrime(100001,true);primes.pb(2);for(int i=3;i*i<=100000;i+=2){if(isPrime[i]){for(int j=i*i;j<=100000;j+=2*i)isPrime[j]=false;}}for(int i=3;i<=100000;i+=2)if(isPrime[i])primes.pb(i);}
V(int)factors;
void factseive(){factors.resize(100001,2);for(int i=3;i*i<=100000;i+=2){if(factors[i]==2){factors[i]=i;for(int j=i*i;j<=100000;j+=2*i)if(factors[j]==2)factors[j]=i;}}for(int i=3;i<=100000;i+=2)if(factors[i]==2)factors[i]=i;}
int max(int a,int b){return (a>b)?a:b;}
class CLittleGirlAndMaximumSum {
public:
	void solve(std::istream& in, std::ostream& out) {
	    ll n,q;in>>n>>q;
	    ll cnt[n+2]={0};
	    ll ar[n+1]={0};
	    fl(1,n+1)in>>ar[i];
	    std::sort(ar+1,ar+n+1);
	    while(q--){
	        int x,y;in>>x>>y;
	        cnt[x]++,cnt[y+1]--;
	    }
	    fl(2,n+1)cnt[i]+=cnt[i-1];
	    std::sort(cnt+1,cnt+n+1);
	    ll sm=0;
	    fl(1,n+1)sm+=ar[i]*cnt[i];
	    out<<sm;

	}
};
