#include "bits/stdc++.h"
#include "atcoder/all"
#define int          long long int
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
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int r[N], c[N], A[N], B[N], C[N], D[N], h, w, n, pos[N], cnt;
static bool cmp(int x, int y) {
	return B[x] - A[x] + D[x] - C[x] < B[y] - A[y] + D[y] - C[y];
}
void solve() {
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 1; i <= n; i++) {
		pos[i] = i;
	}
	sort(pos + 1, pos + 1 + n, cmp);
	for (int ind = 1; ind <= n; ind++) {
		int i = pos[ind];
		for (int j = A[i]; j <= C[i]; j++) {
			for (int k = B[i]; k <= D[i]; k++) {
				if (r[j] == 0 and c[k] == 0) {
					r[j] = c[k] = 1;
					cnt++;
					goto done;
				}
			}
		}
done:;
	}
	atcoder::mf_graph<int> adj(2 * n + h + w + 2);
	// n u's 		n v's and 	h r's 		and 		w c's
	// (1, n)  (n + 1, 2n) (2n + 1, 2n + h) (2n + h + 1, 2n + h + w)
	for (int i = 1; i <= n; i++) {
		for (int j = A[i]; j <= C[i]; j++) {
			adj.add_edge(j + 2 * n, i, 1);
		}
		for (int k = B[i]; k <= D[i]; k++) {
			adj.add_edge(n + i, 2 * n + h + k, 1);
		}
		adj.add_edge(i, n + i, 1);
	}
	for (int i = 1; i <= h; i++) {
		adj.add_edge(0, 2 * n + i, 1);
	}
	for (int i = 1; i <= w; i++) {
		adj.add_edge(2 * n + h + i, 2 * n + h + w + 1, 1);
	}
	cout << max(cnt, adj.flow(0, 2 * n + h + w + 1));
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}