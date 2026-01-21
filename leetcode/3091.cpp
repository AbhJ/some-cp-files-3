class Solution {
public:
	int minOperations (int k) {
		int ans = 1e9;
		for (int n = 1; n <= k; n++) {
			ans = min (((k + n - 1) / n) + n - 2, ans);
		}
		return ans;
	}
};