class Solution {
public:
	vector<int> par, num;
	vector<int> in;
	vector<int> out;
	vector<int> mex;
	vector<vector<int>>a;
	int Time;
	int zero; // pos of numue 0
	void D (int u, int p) {
		in[u] = ++Time;
		par[u] = p;
		for (auto &v : a[u])
			D (v, u);
		out[u] = ++Time;
	}
	// u is ancestor of v?
	bool isAnc (int u, int v) {
		return in[u] <= in[v] && out[u] >= out[v];
	}

	set< int > s;
	void calc (int u) {
		for (auto &v : a[u] )
			if (v != par[u] && !isAnc (v, zero))
				calc (v);
		s.erase (num[u]);
	}
	vector<int> smallestMissingValueSubtree (vector<int>& parents, vector<int>& nums) {
		// WE NEED TO FIND THE MEX VALUE OF SUBTREE
		int n = parents.size();
		num = nums;
		assert (n == nums.size());
		if (count (nums.begin(), nums.end(), 1) == 0)
			return vector<int> (n, 1);
		zero = find (nums.begin(), nums.end(), 1) - nums.begin();
		a = vector<vector<int>> (n);
		for (int i = 0; i < n; i++)
			if (parents[i] != - 1)
				a[parents[i]].emplace_back (i);
		vector<int>ans (n);
		for (int i = 1; i <= 1e5; ++i)
			s.insert (i);
		Time = 0;
		in.resize (n);
		out.resize (n);
		par.resize (n);
		mex.resize (n, 1e5);
		D (0, - 1);
		for (int i = 0; i < n; ++i) {
			if (isAnc (zero, i))
				s.erase (nums[i]);
			if (!isAnc (i, zero))
				mex[i] = 1;
		}
		mex[zero] = *s.begin();
		int cur = par[zero];
		while (cur != -1) {
			calc (cur);
			mex[cur] = *s.begin();
			cur = par[cur];
		}
		return mex;
		set<int>encountered;
		function <int (vector<vector<int>>&, vector<int>&, int)> dfs = [&] (vector<vector<int>>&a, vector<int>&nums, int u) -> int {
			if (a[u].empty()) {
				if (nums[u] == 1) {
					encountered.emplace (1);
					ans[u] = 2;
					return 1;
				}
				ans[u] = 1;
				return 0;
			}
			int hasOneInSubtree = 0;
			for (auto i : a[u])
				hasOneInSubtree |= dfs (a, nums, i);
			hasOneInSubtree |= (nums[u] == 1);
			if (hasOneInSubtree == 0) {
				ans[u] = 1;
				return 0;
			}
			int cnt = 1;
			encountered.emplace (nums[u]);
			for (auto i : encountered) {
				if (i == cnt)
					cnt++;
				else
					break;
			}
			ans[u] = cnt;
			return 1;
		};
		dfs (a, nums, 0);
		return ans;
	}
};
