//ulrich_nielsen on Codeforces
//I'll reveal my identity soon
//target CM
/* __ __  _      ____   ____   __  __ __      ____   ____    ___  _     _____   ___  ____       _____  ____   ___   ___ ___      ______  __ __    ___      ___      ___   ____  ___
  |  |  || |    |    \ |    | /  ]|  |  |    |    \ |    |  /  _]| |   / ___/  /  _]|    \     |     ||    \ /   \ |   |   |    |      ||  |  |  /  _]    |   \    /  _] /    ||   \
  |  |  || |    |  D  ) |  | /  / |  |  |    |  _  | |  |  /  [_ | |  (   \_  /  [_ |  _  |    |   __||  D  )     || _   _ |    |      ||  |  | /  [_     |    \  /  [_ |  o  ||    \
  |  |  || |___ |    /  |  |/  /  |  _  |    |  |  | |  | |    _]| |___\__  ||    _]|  |  |    |  |_  |    /|  O  ||  \_/  |    |_|  |_||  _  ||    _]    |  D  ||    _]|     ||  D  |
  |  :  ||     ||    \  |  /   \_ |  |  |    |  |  | |  | |   [_ |     /  \ ||   [_ |  |  |    |   _] |    \|     ||   |   |      |  |  |  |  ||   [_     |     ||   [_ |  _  ||     |
  |     ||     ||  .  \ |  \     ||  |  |    |  |  | |  | |     ||     \    ||     ||  |  |    |  |   |  .  \     ||   |   |      |  |  |  |  ||     |    |     ||     ||  |  ||     |
   \__,_||_____||__|\_||____\____||__|__|    |__|__||____||_____||_____|\___||_____||__|__|    |__|   |__|\_|\___/ |___|___|      |__|  |__|__||_____|    |_____||_____||__|__||_____|
*/
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define per(i,b,a) for (int i = b; i >= a; i--)
#define pb emplace_back
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
using vi = std::vector<int>;
using vvi = std::vector<vi>;
#define all(x)     x.begin(), x.end()
using pii = std::pair<int,int>;
#define S second
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define F first
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
#define ll int
const int inf = 1e18;
// const ll M = 998244353;
// const int M = 1e9+7;
const int N = 4e6+10;
int a, b, A[N], su, x, l;set<int>s;
void solve(){
	cin >> a >> b;
	srand(time(NULL));
	s.insert(0);
	rep(i, 1, a){
		while(s.count(x) == 1)
			x = ((int)(rand()) % min((int)1e9 * b / a, (int)1e9)) + 1;
		cout << x << " ",
		su += x,
		s.insert(x);
	}
	l = (su) / b;
	rep(i, 1, b - 1){
		while(s.count(- l) == 1)
			l--;
		s.insert(- l);
		x = l,
		cout << - x << " ",
		su -= x;
	}
	cout << - su;
}
//suorer bacha
int32_t main()
{
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);
  int t = 1;
//   cin>>t;
  while(t--){
	  solve();
	  cout<<"\n";
  }
  return 0;
}