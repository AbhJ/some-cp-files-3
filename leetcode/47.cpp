class Solution {
public:
	vector<vector<int>> permuteUnique (vector<int> &nums) {
		sort (nums.begin(), nums.end());
		vector<vector<int>> V {nums};
		vector<int>v = nums;
		do {
			if (v == nums)
				continue;
			V.emplace_back (nums);
			v = nums;
		}
		while (next_permutation (nums.begin(), nums.end()));
		return V;
	}
};
