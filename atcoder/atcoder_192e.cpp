//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 21 in 00 : 23 : 54
//title - E_Train.cpp
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
int n, m, x, y, A[N], B[N], k[N], t[N], d[N];vvi a[N];
void solve(){
	cin >> n >> m;
	fill(d + 1, d + 1 + n, inf);
	cin >> x >> y;
	d[x] = 0;
	rep(i, 1, m){
		cin >> A[i] >> B[i] >> t[i] >> k[i];
		a[A[i]].pb(vi{B[i], k[i], t[i]});
		a[B[i]].pb(vi{A[i], k[i], t[i]});
	}
	priority_queue<vi>q;
	q.push(vi{0, x});
	while(q.empty() == 0){
		int c = - (q.top())[0];
		int u = (q.top())[1];
		q.pop();
		for(auto &v: a[u]){
			int ta = v[0], K = v[1], T = v[2];
			int ti = ((c + K - 1) / K) * K;
			if(d[ta] > ti + T)
				d[ta] = ti + T,
				q.push(vi{- ti - T, ta});
		}
	}
	cout << (d[y] != inf ? d[y] : - 1);
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}