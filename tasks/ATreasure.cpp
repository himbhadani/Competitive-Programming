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
class ATreasure {
public:
	void solve(std::istream& in, std::ostream& out) {
	    std::string s;in>>s;
	    int ct=0,hc=0;
	    fl(0,s.length())if(s[i]=='(')ct++;else if(s[i]==')')ct--;else hc++;
	    if(ct<hc){out<<-1;return;}
	    V(int) ans(hc,1);
	    std::stack<int>st;
	    fl(0,s.size()){
	        if(s[i]=='(')st.push('(');
	        else if(s[i]==')')if(st.empty()){out<<-1;return;}else st.pop();
	    }//std::cout<<st.size()<<std::endl;
	    ans[hc-1]=st.size()-hc+1;
	    fl(0,hc)out<<ans[i]<<"\n";
	}
};
