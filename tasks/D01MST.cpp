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
#define sort(x,y) std::sort(x,y)
V(int) primes;
void seive(){V(int) isPrime(100001,true);primes.pb(2);for(int i=3;i*i<=100000;i+=2){if(isPrime[i]){for(int j=i*i;j<=100000;j+=2*i)isPrime[j]=false;}}for(int i=3;i<=100000;i+=2)if(isPrime[i])primes.pb(i);}
V(int)factors;
void factseive(){factors.resize(100001,2);for(int i=3;i*i<=100000;i+=2){if(factors[i]==2){factors[i]=i;for(int j=i*i;j<=100000;j+=2*i)if(factors[j]==2)factors[j]=i;}}for(int i=3;i<=100000;i+=2)if(factors[i]==2)factors[i]=i;}
inline int max(int a,int b){return (a>b)?a:b;}
class D01MST {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n,m;in>>n>>m;
	    std::set<int> graph[n+1];
	    int ar[n+1];
	    fl(1,n+1)ar[i]=n-1;
	    fl(0,m){
	        int x,y;in>>x>>y;
	        ar[x]--,ar[y]--;
	        graph[x].insert(y);
	        graph[y].insert(x);
	    }
	    fl(1,n+1)if(ar[i]==n-1){out<<0;return;}
	    //std::priority_queue<P(int,int),V(P(int,int)),std::greater<P(int,int)>> qe;
	    std::set<P(int,int)> qe;
	    std::set<int> st;
	    fl(1,n+1)st.insert(i);
	    qe.insert({0,1});
	    st.erase(1);
	    int vis[n+1];
	    fl(1,n+1)vis[i]=-1;
	    int cst=0;
	    while(qe.size()){
	        auto x=*(qe.begin());qe.erase(qe.begin());
	        if(vis[x.second]!=-1){continue;}
	        st.erase(x.second);
	        vis[x.second]=x.first;
	        cst+=x.first;
	        auto st1=st;
	        for(auto y:st){
	            if(graph[x.second].find(y)==graph[x.second].end()){
	                st1.erase(y);
	                qe.insert({0,y});
	            }
	            else {
	                qe.insert({1,y});
	            }
	        }
	        st=st1;
	    }
	    //fl(1,n+1){cst+=vis[i];}
	    out<<cst;
	}
};
