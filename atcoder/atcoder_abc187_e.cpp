//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 02 in 22 : 43 : 01
//title - a.cpp
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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
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
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, q;vi a[N];int A[N], B[N], father[N], dp[N];
void f(int u, int p = 0){
  father[u] = p;
  for(auto &i: a[u])if(i != p)
    f(i, u);
}
void g(int u, int p = 0){
  father[u] = p;
  dp[u] += dp[p];
  for(auto &i: a[u])if(i != p)
    g(i, u);
}
void solve(){
  cin >> n;
  rep(i, 1, n - 1)
    cin >> A[i] >> B[i],
    a[A[i]].pb(B[i]),
    a[B[i]].pb(A[i]);
  f(1);
  cin >> q;
  rep(i, 1, q){
    int t, n, x;
    cin >> t >> n >> x;
    if(t == 1){
      if(father[A[n]] == B[n])
        dp[A[n]] += x;
      else dp[B[n]] -= x, dp[1] += x;
    }
    if(t == 2){
      if(father[B[n]] == A[n])
        dp[B[n]] += x;
      else dp[A[n]] -= x, dp[1] += x;
    }
  }
  g(1);
  rep(i, 1, n)cout << dp[i] << "\n";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}