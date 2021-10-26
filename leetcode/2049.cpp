class Solution {
public:
	map<long long, vector<int>>m;
	int countHighestScoreNodes (vector<int>& parents) {
		vector<vector<int>>a (parents.size());
		for (int i = 1; i < parents.size(); i++) {
			a[i].emplace_back (parents[i]);
			a[parents[i]].emplace_back (i);
		}
		function <int (int, int)> f = [&] (int u, int p) -> int {
			long long cnt = 1, sub = 1;
			for (auto i : a[u])
				if (i != p) {
					int s = f (i, u);
					cnt *= s;
					sub += s;
				}
			if (u == 0)
				m[ (long long)cnt].emplace_back (u);
			m[ (long long) (parents.size() - sub) * (long long)cnt].emplace_back (u);
			return (int)sub;
		};
		f (0, - 1);
		if (m.empty())
			return 0;
		return m.rbegin() -> second.size();
	}
};
