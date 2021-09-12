#include "bits/stdc++.h"
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
int n, m, x, y; vvi a; vi sour;
struct LCA {
	vector<int> height, euler, first, segtree;
	vector<bool> visited;
	int n;

	LCA(vector<vector<int>> &adj, int root = 0) {
		n = adj.size();
		height.resize(n);
		first.resize(n);
		euler.reserve(n * 2);
		visited.assign(n, false);
		dfs(adj, root);
		int m = euler.size();
		segtree.resize(m * 4);
		build(1, 0, m - 1);
	}

	void dfs(vector<vector<int>> &adj, int node, int h = 0) {
		visited[node] = true;
		height[node] = h;
		first[node] = euler.size();
		euler.push_back(node);
		for (auto to : adj[node]) {
			if (!visited[to]) {
				dfs(adj, to, h + 1);
				euler.push_back(node);
			}
		}
	}

	void build(int node, int b, int e) {
		if (b == e) {
			segtree[node] = euler[b];
		} else {
			int mid = (b + e) / 2;
			build(node << 1, b, mid);
			build(node << 1 | 1, mid + 1, e);
			int l = segtree[node << 1], r = segtree[node << 1 | 1];
			segtree[node] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int node, int b, int e, int L, int R) {
		if (b > R || e < L)
			return -1;
		if (b >= L && e <= R)
			return segtree[node];
		int mid = (b + e) >> 1;

		int left = query(node << 1, b, mid, L, R);
		int right = query(node << 1 | 1, mid + 1, e, L, R);
		if (left == -1) return right;
		if (right == -1) return left;
		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if (left > right)
			swap(left, right);
		return query(1, 0, euler.size() - 1, left, right);
	}

	int dis(int u, int v) {
		return height[u] + height[v] - (height[lca(u, v)] << 1LL);
	}
};
void solve() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 1; i <= n - 1; i++) {
		cin >> x >> y;
		a[x - 1].pb(y - 1);
		a[y - 1].pb(x - 1);
	}
	LCA lca(a);
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		cout << (lca.dis(x - 1, y - 1) & 1 ? "Road" : "Town");
		cout << "\n "[i == m];
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}