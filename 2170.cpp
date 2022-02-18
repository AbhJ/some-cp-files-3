class Solution {
public:
	vector<int> func (int start, vector<int> &nums) {
		int most = 0, secm = 0, n = nums.size();
		map<int, int> m;
		for (int i = start; i < n; i += 2) {
			m[nums[i]]++;
			if (nums[i] == most)
				continue;
			if (m[nums[i]] > m[most]) {
				secm = most;
				most = nums[i];
				continue;
			}
			if (m[nums[i]] > m[secm])
				secm = nums[i];
		}
		return vector<int> {most, m[most], m[secm]};
	}
	int minimumOperations (vector<int> &nums) {
		auto v1 = func (0, nums), v2 = func (1, nums);
		if (v1[0] != v2[0])
			return nums.size() - v1[1] - v2[1];
		return nums.size() - max (v1[1] + v2[2], v1[2] + v2[1]);
	}
};
