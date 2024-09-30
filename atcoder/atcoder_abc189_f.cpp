//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 24 in 18 : 05 : 50
//title - F_Sugoroku2.cpp
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, k;double c[N], suf_c[N], suf_v[N], v[N];set<int>s;
void solve(){
	cin >> n >> m >> k;
	rep(i, 1, k){
		int black_list;
		cin >> black_list;
		s.insert(black_list);
	}
	per(i, n - 1, 0){
		if(s.count(i) == 1){
			c[i] = 1;
		}
		else{
			c[i] = ((suf_c[i + 1] - suf_c[i + m + 1]) / (double)m);
			v[i] = ((suf_v[i + 1] - suf_v[i + m + 1]) / (double)m) + (double) 1;
		}
		suf_c[i] = suf_c[i + 1] + c[i];
		suf_v[i] = suf_v[i + 1] + v[i];
	}
	cout << fixed << setprecision(4);
	if(c[0] < 1 and c[0] >= 0)cout << (v[0] / (1.0 - c[0]));
	else cout << - 1;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}