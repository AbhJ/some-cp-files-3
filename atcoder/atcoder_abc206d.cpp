#include "bits/stdc++.h"
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int N    =     2e6 + 10;
int n, a[N], cnt;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  atcoder::dsu dsu(N);
  for (int i = 0; i < (n >> 1LL); i++) {
    cnt += !dsu.same(a[i], a[n - 1 - i]);
    dsu.merge(a[i], a[n - 1 - i]);
  }
  cout << cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  solve(); return 0;
  return 0;
}