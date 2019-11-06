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
class DBinaryStringMinimizing {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int t;in>>t;
	    while(t--){
	        ll n,k;in>>n>>k;
	        std::string s;in>>s;
	        if(s.length()==1){
	            out<<s<<std::endl;
                continue;
	        }
	        ll one=0,zero=0;
	        while(one<s.length()&&s[one]!='1')one++;
	        if(one>=s.length()-1)out<<s<<std::endl;
	        else{
	            for(ll i=one+1;i<s.length()&&k&&one<s.length();i++){
	                if(s[i]=='0'&&one<i){
	                    if(i-one<=k){std::swap(s[one],s[i]);k-=(i-one);}
	                    else {
	                        std::swap(s[i],s[i-k]);
	                        k=0;
	                    }
	                   // std::cout<<s<<std::endl;
	                    one++;
	                    //while(one<s.length()&&s[one]!='1')one++;
	                }
	            }
	            out<<s<<std::endl;
	        }
	    }

	}
};
