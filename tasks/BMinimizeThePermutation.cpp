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
class BMinimizeThePermutation {
public:
    void swap(int &a,int &b){
        int t=a;
        a=b;
        b=t;
    }
	void solve(std::istream& in, std::ostream& out) {
	    int t;in>>t;
	    while(t--){
	        int n;in>>n;
	        int ar[n+1];
	        int x;
	        fl(0,n){
	            in>>x;
	            ar[x]=i;
	        }
	        int prev=0;
	        for(int i=1;i<=n;i++){
	            if(ar[i]==prev)prev++;
	            else if(ar[i]<prev)continue;//ar[i]++;
	            else{
	                int tmp=ar[i];
	                ar[i]=prev;
	                //prev=tmp;
	                for(int j=i+1;j<=n;j++)if(ar[j]>=prev&&ar[j]<tmp)ar[j]++;prev=tmp;
                    //for(int i=1;i<=n;i++)std::cout<<ar[i]<<" ";std::cout<<"\n";
	            }
	        }
	        int arr[n];
	        //for(int i=1;i<=n;i++)std::cout<<ar[i]<<" ";std::cout<<"\n";
	        for(int i=1;i<=n;i++)arr[ar[i]]=i;
	        fl(0,n)out<<arr[i]<<" ";out<<"\n";
	    }

	}
};
