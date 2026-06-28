class Solution {
public:
	int maxFixedPoints (vector<int>& nums) {
		vector <int> lis;
		vector <pair <int, int>> v;
		for (int i = 0; i < nums.size(); i++) if (i >= nums[i])
				v.emplace_back (i - nums[i], nums[i]);
		sort (v.begin(), v.end());
		for (auto [u, i] : v) {
			auto pos = lower_bound (lis.begin(), lis.end(), i);
			if (pos == lis.end())
				lis.emplace_back (i);
			else
				*pos = i;
		}
		return lis.size();
	}
};