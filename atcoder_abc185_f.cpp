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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, t[4*N], q;
//building the tree
void build(int a[], int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum( l, min(r, tm),v*2, tl, tm)
           ^ sum(max(l, tm+1), r,v*2+1, tm+1, tr );
}
//
void update(int pos, int new_val,int v=1, int tl=1, int tr=n ) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,v*2, tl, tm);
        else
            update(pos,new_val,v*2+1, tm+1, tr);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}
int a[N];
void solve(){
  cin >> n >> q;
  rep(i, 1, n)cin >> a[i];
  build(a);
  while(q--){
    int typ, x, y;
    cin >> typ >> x >> y;
    if(typ == 1){
      update(x, a[x] ^ y);
      a[x] ^= y;
    }
    if(typ == 2){
      cout << sum(x, y);
      cout << "\n";
    }
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}