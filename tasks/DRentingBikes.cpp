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
#define Sort(x,y) std::sort(x,y)
void seive(){V(int) isPrime(100001,true);primes.pb(2);for(int i=3;i*i<=100000;i+=2){if(isPrime[i]){for(int j=i*i;j<=100000;j+=2*i)isPrime[j]=false;}}for(int i=3;i<=100000;i+=2)if(isPrime[i])primes.pb(i);}
vector<int>factors;
void factseive(){factors.resize(100001,2);for(int i=3;i*i<=100000;i+=2){if(factors[i]==2){factors[i]=i;for(int j=i*i;j<=100000;j+=2*i)if(factors[j]==2)factors[j]=i;}}for(int i=3;i<=100000;i+=2)if(factors[i]==2)factors[i]=i;}
int max(int a,int b){return (a>b)?a:b;}
class DRentingBikes {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n,m,a;in>>n>>m>>a;
	    int ar[n],int cost[m];
	    fl(0,n)in>>ar[i];
	    fl(0,m)in>>cost[i];
	    Sort(ar,ar+n);
	    Sort(cost,cost+m);
	    int bkd=0,cnt=0;
	    fl(0,m){
	        int x=lower_bound(ar+bkd,ar+n,cost[i]);
	        if(x==n-bkd)break;
	        if(cost[i]!=ar[i]&&x)x--;
	        if(x==n)break;
	        if(x)x--;
	        bkd=x+1;
	    }

	}
};
