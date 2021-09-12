//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 30 in 19 : 42 : 25
//title - A_Special_Tree.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=18;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, k, a, u, v, tm;vvi A, tmp_bap;
void dfs(int u, int p, vi& j, int koita, vvi& parent) {
    j[u] = koita;
    parent[u][0] = p;
    for (auto i : A[u])if(i != p)
        dfs(i, u, j, koita + 1, parent);
}
void FF(int u, int p, vi& tmp, set<int>& z) {
    for (auto i : A[u]) {
        if (i == p) continue;
        FF(i, u, tmp, z);
        if (tmp[i] != -1) {
            tmp[u] = tmp[i];
        }
    }
    if (tmp[u] == -1) {
        if (z.count(u)) {
            tmp[u] = u;
        }
    }
}
void solve(){
	cin >> n >> k >> a;
	 a--;
    A = vvi(n);
    set<int> z;
    rep(i, 0, k - 1)
        cin >> tm,
        z.insert(tm - 1);
   rep(i, 0, n - 2){
        cin >> u >> v;
        u--, v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    tmp_bap = vvi (n, vi(N, -1));
    vi D(n);
    dfs(a, -1, D, 0, tmp_bap);
    rep(j, 1, N - 1)
        rep(i, 0, n - 1)
            if (tmp_bap[i][j - 1] != -1)
                tmp_bap[i][j] = tmp_bap[tmp_bap[i][j - 1]][j - 1];
    vi tmp(n, -1);
    FF(a, -1, tmp, z);
    vi arr_A(n), arr_B(n);
   rep(i, 0, n - 1){
        if (tmp[i] != -1) {
            arr_A[i] = D[i];
            arr_B[i] = tmp[i];
        }
		else{
			int curr = i;
			int last = N - 1;
			while (1) {
				int flag = 0;
				int temp_last;
				per(D, last, 0){
					int u = tmp_bap[curr][D];
					temp_last = D;
					if (u == -1) continue;
					if (tmp[u] == -1) {
						curr = u;
						flag = 1;
						break;
					}
				}
				if (!flag) {
					curr = tmp_bap[curr][0];
					last = temp_last;
					break;
				}
			}
			int prothom = D[curr];
			int ditio = D[i] - D[curr];
			arr_A[i] = prothom - ditio, arr_B[i] = tmp[curr];
		}
    }
   rep(i, 0, n - 1){
        cout << arr_A[i] << " ";
    }
    cout << "\n";
    rep(i, 0, n - 1){
        cout << arr_B[i] + 1 << " ";
    }
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}