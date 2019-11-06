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
//#define sort(x,y) std::sort(x,y)
V(int) primes;
void seive(){V(int) isPrime(100001,true);primes.pb(2);for(int i=3;i*i<=100000;i+=2){if(isPrime[i]){for(int j=i*i;j<=100000;j+=2*i)isPrime[j]=false;}}for(int i=3;i<=100000;i+=2)if(isPrime[i])primes.pb(i);}
V(int)factors;
void factseive(){factors.resize(100001,2);for(int i=3;i*i<=100000;i+=2){if(factors[i]==2){factors[i]=i;for(int j=i*i;j<=100000;j+=2*i)if(factors[j]==2)factors[j]=i;}}for(int i=3;i<=100000;i+=2)if(factors[i]==2)factors[i]=i;}
inline int max(int a,int b){return (a>b)?a:b;}
bool cmp(P(int,int) a,P(int,int) b){
    return (a.first>b.first);
}
class CPlatformsJumping {
public:
	void solve(std::istream& in, std::ostream& out) {
//	    int n,m,d;in>>n>>m>>d;
//	    V(P(int,int)) ar(m);
//	    fl(0,m){in>>ar[i].first;ar[i].second=i+1;}
//	    std::sort(ar.begin(),ar.end(),cmp);
//	    fl(0,m)std::cout<<ar[i].first<<" "<<ar[i].second<<"\t";std::cout<<"\n";
//	    int reach[n+2]={0};
//	    reach[0]=1;int ptr=0;
//	    for(int i=d;i<=n;i+=d){
//	        if(ptr==m)break;
//	        int j;
//	        for(j=i;j-i<ar[ptr].first&&j<=n;j++){reach[j]=ar[ptr].second;}i=j-1;ptr++;
//	    }
//	    for(int i=1;i<=n;i++){
//	        if(reach[i]==0){
//	            out<<"NO\n";return;
//	        }
//	    }
//	    out<<"YES\n";
//	    fl(1,n+1)out<<reach[i]<<" ";
        int n,m,d;in>>n>>m>>d;
        int ar[m];
        fl(0,m)in>>ar[i];
        int re[n+2];int pr=0;
        for(int i=d;i<=n;i++){
            re[i]=pr+1;
        }
	}
};
