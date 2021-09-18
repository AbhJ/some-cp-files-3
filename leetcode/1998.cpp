class Solution {
public:
	vector<int> fact (int n) {
		vector<int> v;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				v.emplace_back (i);
				if (i * i != n)
					v.emplace_back (n / i);
			}
		}
		return v;
	}
	vector<int> parent, ra;
	//disjoint set union dsu
	int find_set (int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set (parent[v]);
	}
	void make_set (int v) {
		parent[v] = v;
		ra[v] = 0;
	}
	void union_sets (int a, int b) {
		a = find_set (a);
		b = find_set (b);
		if (a != b) {
			if (ra[a] < ra[b])
				swap (a, b);
			parent[b] = a;
			if (ra[a] == ra[b])
				ra[a]++;
		}
	}
	bool gcdSort (vector<int>& nums) {
		int n = nums.size();
		auto fina = nums;
		int ma = *max_element (nums.begin(), nums.end());
		parent.resize (ma + 1);
		ra.resize (ma + 1);
		for (int i = 1; i <= ma; i++)
			make_set (i);
		for (int i = 0; i < n; i++) {
			vector<int> v = fact (nums[i]);
			for (auto j : v)
				union_sets (j, nums[i]);
		}
		sort (fina.begin(), fina.end());
		for (int i = 0; i < n; i++) {
			if (find_set (fina[i]) != find_set (nums[i]))
				return false;
		}
		return true;
	}
};
