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
class DPowerProducts {
public:
    ll primes[100001]={0};//,0);
    void seive(){
        //std::vector<bool> prm(100001,true);
        //primes[2]=2;//.pb(2);
        for(int i=2;i*i<=100000;i+=1){
            if(primes[i]==0){
                primes[i]=i;
                //primes.pb(i);
                for(int j=i*i;j<=100000;j+=i)
                    if(primes[j]==0)
                        primes[j]=i;
            }
        }
        for(int i=3;i<=100000;i+=2)if(primes[i]==0)primes[i]=i;
    }
    void solve(std::istream& in, std::ostream& out) {
        seive();//std::cout<<primes.size();
        //fl(2,11)std::cout<<primes[i]<<" ";std::cout<<std::endl;
        //fl(2,100001)if(primes[i]==0)std::cout<<i<<" ";std::cout<<std::endl;
        ll n,k;in>>n>>k;
        ll ar[n];
        fl(0,n)in>>ar[i];
        std::map<ll,ll>mpt;
        fl(0,n){
            if(mpt.find(ar[i])!=mpt.end())ar[i]=mpt[ar[i]];
            int vtr=ar[i];
            int fv=1,cnt=1,prm=primes[ar[i]];
            while(ar[i]>1){
                if(prm==primes[ar[i]/primes[ar[i]]])cnt++;
                else{
                    cnt%=k;
                    fv*=pow(prm,cnt);
                    cnt=1;
                    prm=primes[ar[i]/primes[ar[i]]];
                }
                ar[i]/=primes[ar[i]];
            }
            //std::cout<<vtr<<" "<<fv<<std::endl;
            mpt[vtr]=fv;
            ar[i]=fv;
        }
        //fl(0,n)std::cout<<ar[i]<<" ";std::cout<<std::endl;
        std::map<ll,ll> mp;
        ll ans=0;
        fl(0,n)mp[ar[i]]++;
        for(auto x: mp) {
            ll comp = 1;
            ll prm = primes[x.first], cnt = 1;
            ll vt = x.first;
            while (vt > 1) {
                if (prm == primes[vt / primes[vt]])cnt++;
                else {
                    cnt %= k;
                    comp *= pow(prm, k - cnt);
                    cnt = 1;
                    prm = primes[vt / primes[vt]];
                }
                vt /= primes[vt];
            }
            //std::cout<<x.first<<" "<<comp<<std::endl;
            if (mp.find(comp) != mp.end()) {
                if (comp == x.first)ans += (mp[x.first] * (mp[x.first] - 1));
                else ans += mp[x.first] * mp[comp];
            }
        }
        out<<ans/2;
    }
};
