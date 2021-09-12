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
int n, m, A[N], B[N]; vvi a;
const int M    =     1e9 + 7;
int add(int a, int b) {
	a += b;
	return (a >= M ? a - M : a);
}
int mul(int a, int b) {
	return (a * b) % M;
}
int sub(int a, int b) {
	return (a - b + M) % M;
}
int powM(int b, int p) {
	int r = 1;
	for (; p; b = mul(b, b), p >>= 1)
		if (p & 1)
			r = mul(r, b);
	return r;
}
int invM(int x) {
	return powM(x, M - 2);
}
int f[N], b[N];
void binomialCoeff() {
	f[0] = 1;
	for (int i = 1; i <= N - 1; i++)
		f[i] = mul(f[i - 1], i);
	b[N - 1] = powM(f[N - 1], M - 2);
	for (int i = N - 2; i >= 0; i--)
		b[i] = mul(b[i + 1], i + 1);
}
int C(int n, int r) {
	return (r > n ? 0LL : mul(f[n], mul(b[r], b[n - r])));
}
struct BFS {
	vi distance;
	vi parent;
	vi koita;

	BFS(const vvi &adj, const vi &sources) {
		const int n = adj.size();
		distance.assign(n, -1);
		parent.assign(n, -1);
		koita.assign(n, 0);
		queue<int> q;
		koita[1] = 1;
		for (int i : sources) {
			q.push(i);
			distance[i] = 0;
		}
		while (!q.empty()) {
			int i = q.front();
			q.pop();
			for (int j : adj[i]) {
				if (distance[j] == 1 + distance[i]) {
					// some other path exists
					koita[j] = add(koita[j], koita[i]);
				}
				if (distance[j] != -1)
					continue;

				q.push(j);
				distance[j] = distance[i] + 1;
				parent[j] = i;
				koita[j] = koita[i];
			}
		}
	}

	vi get_path(int destination) {
		if (distance[destination] == -1)
			return {};
		vi path;
		for (int i = destination; i != -1; i = parent[i])
			path.pb(i);
		reverse(path.begin(), path.end());
		return path;
	}
};
void solve() {
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> A[i] >> B[i];
		a[A[i]].pb(B[i]);
		a[B[i]].pb(A[i]);
	}
	vi sou{1};
	BFS bfs(a, sou);
	cout << bfs.koita[n];
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}