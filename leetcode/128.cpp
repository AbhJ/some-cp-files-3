class Solution {
public:
	int longestConsecutive (vector<int>& nums) {
		unordered_set<int> s;
		int ans = 0;
		for (auto i : nums)
			s.emplace (i);
		for (auto i : nums) {
			int cur = i, cnt = 1;
			if (s.count (cur - 1))
				continue;
			while (s.count (cur)) {
				ans = max (cur - i + 1, ans);
				cur++;
			}
			if (ans * 2 > nums.size())
				return ans;
		}
		return ans;
	}
};