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
class B1CharacterSwapEasyVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int t;in>>t;
	    while(t--){
	        int n;in>>n;
	        std::string s,t;in>>s>>t;
	        std::map<char,int> mp;
            V(int) vr;
            std::string st=s,tt=t;char c;
	        if(s==t){out<<"No\n";goto outi;}
	        fl(0,s.length()){
	            mp[s[i]]++;
	            mp[t[i]]++;
	        }
	        for(auto x:mp){
	            if(x.second%2){
	                out<<"No\n";
	                goto outi;
	            }
	        }
	        fl(0,s.length())if(s[i]!=t[i])vr.pb(i);
	        if(vr.size()!=2){out<<"No\n";goto outi;}
	        c=st[vr[0]];
	        st[vr[0]]=tt[vr[1]];
	        tt[vr[1]]=c;
	        if(st==tt){
	            out<<"Yes\n";
	            goto outi;
	        }
	        st=s,tt=t;
	        c=st[vr[1]];
	        st[vr[1]]=tt[vr[0]];
	        tt[vr[0]]=c;
	        if(st==tt){
	            out<<"Yes\n";
	            goto outi;
	        }
	        out<<"No\n";
	        outi:{}
	    }

	}
};
