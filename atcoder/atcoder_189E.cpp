//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 24 in 06 : 12 : 25
//title - E_Rotate_and_Flip.cpp
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
int n, m, x[N], y[N], A[N], B[N];
int coord[N], delx[N], dely[N];
vector<vvi>a;
int add(int a, int b){
	return a + b;
}
int mul(int a, int b){
	return a * b;
}
vvi P(vvi a,vvi b){
  vvi x(a.size(),vi(b[0].size()));
  rep(i,0,a.size()-1)
    rep(j,0,b[0].size()-1)
      rep(k,0,a[0].size()-1)
        x[i][j]=add(x[i][j],mul(a[i][k],b[k][j]));
  return x;
}
vvi matri(int typ, int p = - inf){
	vvi mat1;
	if(typ == 1){
		mat1 = vvi{{0, 1, 0}, {- 1, 0, 0}, {0, 0, 1}};
	}
	if(typ == 2){
		mat1 = vvi{{0, - 1, 0}, {1, 0, 0}, {0, 0, 1}};
	}
	if(typ == 3){
		mat1 = vvi{{- 1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}};
	}
	if(typ == 4){
		mat1 = vvi{{1, 0, 0}, {0, - 1, 2 * p}, {0, 0, 1}};
	}
	return P(mat1, a.back());
}
vi get_pos(int i){
	vvi M = a[A[i]];
	return vi {x[B[i]] * M[0][0] + y[B[i]] * M[0][1] + M[0][2], x[B[i]] * M[1][0] + y[B[i]] * M[1][1] + M[1][2]};
	return vi(3);
}
void solve(){
	cin >> n;
	rep(i, 1, n)cin >> x[i] >> y[i];
	a.pb(vvi {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	int m;cin >> m;
	rep(i, 1, m){
		int typ;
		cin >> typ;
		if(typ == 3 or typ == 4){
			int p;cin >> p;
			a.pb(matri(typ, p));
		}
		else a.pb(matri(typ));
	}
	int q;
	cin >> q;
	rep(i, 1, q){
		cin >> A[i] >> B[i];
		vi v = get_pos(i);
		cout << v[0] << " " << v[1] << "\n";
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