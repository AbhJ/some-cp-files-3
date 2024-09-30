//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int result[N],f[N],b[N];
int mul(int a,int b){
  return ((a)*(b))%M;
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
// long long C(long long n,long long r)
// {
//     long long N=1,R=1;
//     if(r>n or r<0)return 0;
//     if(n==r or r==0)return 1;
//     for(long long i=1;i<=n;i++) N=N*i%M;
//     for(long long i=1;i<=r;i++) R=R*i%M;
//     for(long long i=1;i<=n-r;i++) R=R*i%M;
//     return (N*powM(R,M-2))%M;
// }
int invM(int x){
  return powM(x,M-2);
}
void binomialCoeff(int n) 
{ 
  f[0]=b[0]=1;
  rep(i,1,n){
    f[i]=mul(f[i-1],i);
    b[i]=invM(f[i]);
  }
  // rep(i,1,n){
  //   C[i]=mul(mul(f[n],b[n-i]),b[i]);
  // }
} 
int C(int n,int i){
  return mul(mul(f[n],b[n-i]),b[i]);
}
void fact_dp(int n)

{

    if (n >= 0) 

    {

        result[0] = 1;

        for (int i = 1; i <= n; ++i) 

        {

            result[i] = mul(i , result[i - 1]);

        }

    }

}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
  int n,m;cin>>n>>m;
  fact_dp(N-1);
  binomialCoeff(m);
  int x=mul(C(m,n),result[n]);
  int ans=mul(x,x);
  // cout<<sub(ans,mul(sub(powM(2,n),1),mul(1,C(m,n))));
  // cout<<sub(ans,mul(n,mul(m,mul(result[n-1],C(m-1,n-1)))));
  int cnt=0;
  rep(i,1,n){
    int c=1;
    c=mul(c,mul(C(m,n),mul(C(n,i),result[n])));
    c=mul(c,mul(C(m-i,n-i),result[n-i]));
    if(i&1)cnt=add(cnt,c);
    else cnt=sub(cnt,c);
  }
  cout<<sub(ans,cnt);
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}