vector<int> Solution::subUnsort (vector<int> &nums) {
	int n = nums.size(), mi = nums[n - 1], ma = nums[0], R = - 1, L = 0;
	for (int i = 0; i < n; i++) {
		if (ma > nums[i])
			R = i;
		else
			ma = nums[i];
	}
	for (int i = n - 1; i > - 1; i--) {
		if (mi < nums[i])
			L = i;
		else
			mi = nums[i];
	}
	if (~R)
		return vector<int> {L, R};
	return vector<int> {R};
}
