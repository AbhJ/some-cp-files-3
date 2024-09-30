//Coded by Abhijay Mitra (AbJ)
#include "bits/stdc++.h"
#define double long double
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define mp make_pair
#define pb emplace_back
#define F first
#define S second
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int inf = 1e18 + 10;
const int N = 8e2 + 10;
int n, k, a[N][N], b[N][N], dp[N][N];
void solve(){
	cin >> n >> k;
	rep(i, 1, n){
		rep(j, 1, n){
			cin >> a[i][j];
		}
	}
	int l = 0, r = inf, m;
	while(l < r){
		m = l + r + 1 >> 1;
		rep(i, 1, n){
			rep(j, 1, n){
				b[i][j] = (a[i][j] >= m);
			}
		}
		int F = 0;
		rep(i, 1, n){
			rep(j, 1, n){
				dp[i][j] = b[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
				// less poeple are able to beat, m is atleast same as actual
				if(i >= k and j >= k and dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] <= ((k * k) >> 1)){
					F = 1;
				}
			}
		}
		if(F == 0)
			l = m;
		else
			r = m - 1;
	}
	cout << l;
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