#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <vector>
#define int long long int
#define mp make_pair
#define pb emplace_back
#define F first
#define S second
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using namespace std;
int n, q, lastServer;
string ans;
void solve() {
  cin >> n >> q;
  vector<tuple<int, int, string>> queries;
  for (int i = 0; i < q; i++) {
    int type, pc;
    cin >> type >> pc;
    string s;
    if (type == 2) {
      cin >> s;
      reverse(s.begin(), s.end());
    }
    queries.pb(type, pc, s);
  }
  reverse(queries.begin(), queries.end());
  for (auto [type, pc, st] : queries) {
    if (type == 3) {
      // if first time this appears or the last time string was set to server
      if (lastServer == 0)
        lastServer = pc;
    }
    // we only bother if this string actually is added to server later on
    if (lastServer != pc)
      continue;
    if (type == 2) {
      ans += st;
    }
    // we care about the server now since string is coming from there to current
    if (type == 1) {
      lastServer = 0;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
