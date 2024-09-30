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
const int N = 2e6 + 10;
int a, b, c;
void solve(){
	cin >> a >> b >> c;
	cout << (a != b and a != c and b != c ? 0: a ^ b ^ c);
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