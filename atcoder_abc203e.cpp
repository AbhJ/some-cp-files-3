//Coded by Abhijay Mitra (AbJ)
#include "bits/stdc++.h"
#define double       long double
#define int          long long int
#define ibs          ios_base::sync_with_stdio(false)
#define cti          cin.tie(0)
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define all(x)       x.begin(), x.end()
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int n, m; pii p[N];
void solve(){
	cin >> n >> m;
	set<int>pawn, adder, eraser;
	pawn.emplace(n);
	rep(i, 1, m){
		cin >> p[i].F >> p[i].S;
	}
	sort(p + 1, p + 1 + m);
	int l = 1, r = 1;
	while(l != m + 1){
		r = l;
		while(r != m and p[r + 1].F == p[r].F)
			r++;
		rep(i, l, r){
			// B
			//WWW
			if((pawn.count(p[i].S - 1) or pawn.count(p[i].S + 1)) and pawn.count(p[i].S) ^ 1)
				adder.emplace(p[i].S);
			// B
			// W
			else if(pawn.count(p[i].S - 1) ^ 1 and pawn.count(p[i].S + 1) ^ 1 and pawn.count(p[i].S)){
				eraser.emplace(p[i].S);
			}
		}
		for(auto &i: adder)
			pawn.emplace(i);
		for(auto &i: eraser)if(pawn.count(i))
			pawn.erase(i);
		adder.clear();
		eraser.clear();
		l = r + 1;
	}
	cout << (int)pawn.size();
}
int32_t main(){
	ibs;cti;
	solve(); return 0;
	int t; cin >> t;
	while (t--){
		solve(); cout << "\n";
	}
	return 0;
}