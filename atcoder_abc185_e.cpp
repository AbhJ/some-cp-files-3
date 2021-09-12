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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
// dp[i][j] = 
// match dp[i + 1][j + 1]
// 1 + min(dp[i][j + 1], dp[i + 1][j])
int n, m, dp[N][N], a[N], b[N];
void solve(){
  cin >> n >> m;
  rep(i, 1, n)cin >> a[i];
  rep(i, 1, m)cin >> b[i];
  rep(i, 0, n)
    rep(j, 0, m){
      if(i == 0)dp[i][j] = j;
      if(j == 0)dp[i][j] = i;
      if(a[i] == b[j] and i != 0 and j != 0)dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]) + 1);
      if(a[i] != b[j] and i != 0 and j != 0)dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
    }
  cout << dp[n][m];
  
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}