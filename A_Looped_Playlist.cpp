//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 31 in 20 : 19 : 12
//title - A_Looped_Playlist.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/3e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], pre[N], taka = inf, pos, p, su, l = 1, posi;
void solve(){
	cin >> n >> p;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, n){
		pre[i] += pre[i - 1] + a[i];
	}
	rep(i, 1, n){
		su += a[i];
		while(i > l and su - a[l] >= p)
			su -= a[l++];
		if(su >= p and taka > i - l + 1)
			taka = i - l + 1,
			posi = (l > n ? l - n : l);
	}
	rep(i, 1, n){
		int dan_hat = pre[n] - pre[i - 1];
		int beche = p - dan_hat;
		int cyc = beche / pre[n];
		beche -= cyc * pre[n];
		if(beche == 0){
			if(taka > cyc * n + n - i + 1)
				taka = cyc * n + n - i + 1, posi = i;
			continue;
		}
		int pos = lower_bound(pre + 1, pre + 1 + n, beche) - pre;
		if(taka > cyc * n + n - i + 1 + pos)
			taka = cyc * n + n - i + 1 + pos, posi = i;
	}
	cout << posi << " " << taka;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}