class Solution {
public:
	int LIS (vector<int> &a, int l, int r, int mi = 1, int ma = 1e5) {
		vector<int> lis;
		for (int j = l; j <= r; ++j)
			if (mi <= a[j] && a[j] <= ma) {
				auto pos = upper_bound (lis.begin(), lis.end(), a[j]);
				if (pos == lis.end())
					lis.emplace_back (a[j]);
				else *pos = a[j];
			}
		return (lis.size());
	}
	int kIncreasing (vector<int> &a, int k) {
		int n = a.size();
		vector<vector<int>> v (k);
		for (int i = 0; i < n; i++)
			v[i % k].emplace_back (a[i]);
		int ans = 0;
		for (int i = 0; i < k; i ++)
			ans += v[i].size() - LIS (v[i], 0, v[i].size() - 1);
		return ans;
	}
};

