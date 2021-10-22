
/**
 * @author      : abhj
 * @created     : Friday Oct 01, 2021 22:50:26 IST
 * @filename    : f.cpp
 */

#include "bits/stdc++.h"
#define int          long long int
struct dsu {
public:
	dsu() : _n (0) {}
	explicit dsu (int n) : _n (n), parent_or_size (n, -1) {}

	int merge (int a, int b) {
		assert (0 <= a && a < _n);
		assert (0 <= b && b < _n);
		int x = leader (a), y = leader (b);
		if (x == y)
			return x;
		if (-parent_or_size[x] < -parent_or_size[y])
			std::swap (x, y);
		parent_or_size[x] += parent_or_size[y];
		parent_or_size[y] = x;
		return x;
	}

	bool same (int a, int b) {
		assert (0 <= a && a < _n);
		assert (0 <= b && b < _n);
		return leader (a) == leader (b);
	}

	int leader (int a) {
		assert (0 <= a && a < _n);
		if (parent_or_size[a] < 0)
			return a;
		return parent_or_size[a] = leader (parent_or_size[a]);
	}

	int size (int a) {
		assert (0 <= a && a < _n);
		return -parent_or_size[leader (a)];
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> leader_buf (_n), group_size (_n);
		for (int i = 0; i < _n; i++) {
			leader_buf[i] = leader (i);
			group_size[leader_buf[i]]++;
		}
		std::vector<std::vector<int>> result (_n);
		for (int i = 0; i < _n; i++)
			result[i].reserve (group_size[i]);
		for (int i = 0; i < _n; i++)
			result[leader_buf[i]].push_back (i);
		result.erase (
			std::remove_if (result.begin(), result.end(),
		[&] (const std::vector<int>& v) {
			return v.empty();
		}),
		result.end());
		return result;
	}
private:
	int _n;
	// root node: -1 * component size
	// otherwise: parent
	std::vector<int> parent_or_size;
};
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

int n, m, mi, ma, a, b, c;
map<string, pii> MAP;
map<int, string>MA;
map<int, int>dep;

void solve() {
	cin >> n >> m >> mi >> ma >> a >> b >> c;
	dsu d (n);
	for (int i = 1; i <= n; i++) {
		string ch;
		int de;
		cin >> ch >> de;
		MAP[ch] = mp (de, i - 1);
		MA[i - 1] = ch;
		dep[i - 1] = de;
	}
	for (int i = 1; i <= m; i++) {
		string le, ri;
		cin >> le >> ri;
		int l, r;
		l = MAP[le].S;
		r = MAP[ri].S;
		d.merge (l, r);
	}
	vi vis (n);
	map<pii, tuple<vi, vi, vi>>groups;
	for (int i = 0; i < n; i++) {
		int lead = d.leader (i);
		int siz = d.size (i);
		pii ind = mp (siz, lead);
		auto& [A, B, C] = groups[ind];
		if (dep[i] == 1)
			A.pb (i);
		if (dep[i] == 2)
			B.pb (i);
		if (dep[i] == 3)
			C.pb (i);
		/*
		 * if (siz > ma or siz < mi) {
		 *     cout << siz << "\n\n";
		 *     cout << "no groups";
		 *     return;
		 * }
		 * if (A.size() > a or B.size() > b or C.size() > c) {
		 *     cout << "no groups";
		 *     return;
		 * }
		 */
	}
	set<int>done;
	map<int, vvi>fin;
	for (auto it = groups.begin(); it != groups.end(); it = next (it))
		if (done.count (it -> F.S) == 0) {
			auto& [A1, B1, C1] = it -> S;
			for (auto jt = next (it); jt != groups.end(); jt = next (jt))
				if (done.count (jt -> F.S) == 0) {
					auto& [A2, B2, C2] = jt -> S;
					if (A1.size() + A2.size() > a or B1.size() + B2.size() > b or C1.size() + C2.size() > c)
						continue;
					done.emplace (jt -> F.S);
					A1.insert (A1.end(), A2.begin(), A2.end());
					B1.insert (B1.end(), B2.begin(), B2.end());
					C1.insert (C1.end(), C2.begin(), C2.end());
				}
			done.emplace (it -> F.S);
			vi tot_vec;
			tot_vec.insert (tot_vec.end(), A1.begin(), A1.end());
			tot_vec.insert (tot_vec.end(), B1.begin(), B1.end());
			tot_vec.insert (tot_vec.end(), C1.begin(), C1.end());
			fin[A1.size() + B1.size() + C1.size()].pb (tot_vec);
		}
	if (fin.empty() == 1) {
		cout << "no groups -- type -- final";
		return;
	}
	for (auto i : fin.rbegin() -> S) {
		for (auto j : i)
			cout << MA[j] << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
