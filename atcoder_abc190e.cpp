//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 31 in 20 : 26 : 19
//title - E_Magical_Ornament.cpp
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
#include <bits/stdc++.h>
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
const int N=1e5 + 10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N], b[N], c[N], n, m, k, dp[17][1 << 17], dis[17][N];
vvi A;
void get_dis(int v){
	queue<int>q;
	q.push(c[v] - 1);
	vi vis(n);vis[c[v] - 1] = 1;
	fill(dis[v], dis[v] + N, inf);
	fill(dp[v] + 1, dp[v] + (1 << 17), inf);
	dis[v][c[v] - 1] = 0;
	while(q.empty() == 0){
		int u = q.front();
		q.pop();
		for(auto &i: A[u]){
			if(vis[i] == 0)
				vis[i] = 1,
				dis[v][i] = dis[v][u] + 1,
				q.push(i);
		}
	}
	return;
}
void solve(){
	cin >> n >> m;A.resize(n);
	rep(i, 0, m - 1){
		cin >> a[i] >> b[i];
		A[a[i] - 1].pb(b[i] - 1);
		A[b[i] - 1].pb(a[i] - 1);
	}
	cin >> k;
	rep(i, 0, k - 1){
		cin >> c[i];
		get_dis(i);
	}
	int ans = inf;
	if(k == 1){cout << 1;return;}
	rep(mas, 0, (1 << k) - 2)
		rep(i, 0, k - 1)if(((1 << i) & mas) == 0)
			rep(j, 0, k - 1)
				dp[i][mas | (1 << i)] = min(dp[j][mas] + dis[j][c[i] - 1], dp[i][mas | (1 << i)]);
	rep(i, 0, k - 1)ans = min(ans, dp[i][(1 << k) - 1]);
	cout << (ans == inf ? - 1 : ans + 1);
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}