class Solution {
public:
	long long maximumSubarraySum (vector<int>& nums, int k) {
		// focus on {1 1 2 2}, 1
		int n = nums.size();
		long long ans = - 1e18;
		vector <long long> pre (n);
		map <int, int> m;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				pre[i] = nums[i];
			}
			else {
				pre[i] = nums[i] + pre[i - 1];
			}
			bool lef = m.count (nums[i] - k), rig = m.count (nums[i] + k);
			if (lef) {
				int pos = m[nums[i] - k];
				ans = max ((long long) pre[i] - (pos == 0 ? 0 : pre[pos - 1]), ans);
			}
			if (rig) {
				int pos = m[nums[i] + k];
				ans = max ((long long) pre[i] - (pos == 0 ? 0 : pre[pos - 1]), ans);
			}
			// we will discard older value only if we see that current prefix is lesser than older prefix
			if (m.count (nums[i]) == 0 or pre[m[nums[i]]] > pre[i]) {
				m[nums[i]] = i;
			}
		}
		return ans == - 1e18 ? 0 : ans;
	}
};