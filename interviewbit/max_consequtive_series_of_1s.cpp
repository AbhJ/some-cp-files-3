#include <bits/stdc++.h>
vector<int> Solution::maxone (vector<int> &nums, int k) {
	int n = nums.size(), l = - 1, r = - 1, cntZeros = 0, ans = 0, L = - 1, R = - 1;
	// the subsequence that we are considering is l + 1 to r both included
	while (++r < n) {
		cntZeros += nums[r] == 0;
		while (cntZeros > k and l < r)
			cntZeros -= nums[++l] == 0;
		if (r - l > ans) {
			L = l, R = r;
			ans = r - l;
		}
	}
	vector<int>v;
	for (int i = L + 1; i <= R; i++)
		v.emplace_back (i);
	return v;
}
