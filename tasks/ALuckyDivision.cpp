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
class ALuckyDivision {
public:
	void solve(std::istream& in, std::ostream& out) {
	    std::map<int,int>mp;
	    int ar[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	    int dp[1001]={0};
	    dp[0]=1,dp[4]=1,dp[7]=1;
	    fl(8,1001){
	        for(int j=0;j<14;j++){
	            if(ar[j]>i)break;
	            dp[i]=dp[i-ar[j]];
	            if(dp[i])break;
	        }
	    }
	    //mp[4]=1,mp[7]=1,mp[44]=1,mp[47]=1,mp[74]=1,mp[77]=1,mp[444]=1,mp[447]=1,mp[474]=1,mp[477]=1,mp[744]=1,mp[747]=1,mp[774]=1,mp[777]=1;
        int n;in>>n;
        if(dp[n])out<<"YES";
        else out<<"NO";
//        int k=0;
//        while(n>=0){
//            if(n%4==0){std::cout<<n<<std::endl;out<<"YES";return;}n-=7;
//        }
//        out<<"NO";
	}
};
