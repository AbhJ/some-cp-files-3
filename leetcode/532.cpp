class Solution {
public:
	int findPairs (vector<int>& nums, int k) {
		int ans = 0;
		if (k == 0) {
			map <int, int> m;
			for (int i = 0; i < nums.size(); i++)
				m[nums[i]]++;
			for (auto [x, y] : m)
				ans += (y > 1);
			return ans;
		}
		set <int> s;
		for (int i = 0; i < nums.size(); i++)
			s.emplace (nums[i]);
		for (auto x : s)
			ans += s.count (x - k);
		return ans;
	}
};