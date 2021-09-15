class Solution {
public:
	vector<int> smallestMissingValueSubtree (vector<int>& parents, vector<int>& nums) {
		int n = nums.size();
		if (count (nums.begin(), nums.end(), 1) == 0)
			return vector<int> (n, 1);
		int pos = find (nums.begin(), nums.end(), 1) - nums.begin();
		vector<vector<int>> a (n);
		for (int i = 0; i < n; i++)
			if (~parents[i])
				a[parents[i]].emplace_back (i);
		set<int>s;
		function <void (int u)> dfs = [&] (int u) -> void {
			s.emplace (nums[u]);
			for (auto i : a[u])
				if (s.count (nums[i]) == 0)
					dfs (i);
		};
		vector<int>ans (n, 1);
		int cnt = 1;
		while (~pos) {
			dfs (pos);
			while (s.count (cnt))
				cnt++;
			ans[pos] = cnt;
			pos = parents[pos];
		}
		return ans;
	}
};
