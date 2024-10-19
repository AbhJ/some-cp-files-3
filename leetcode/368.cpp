class Solution {
public:
	vector<int> largestDivisibleSubset (vector<int>& nums) {
		int n = nums.size();
		sort (nums.begin(), nums.end());
		vector <int> dp (n, 1);
		int maxPosi = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[j] % nums[i])
					continue;
				dp[j] = max (dp[i] + 1, dp[j]);
				if (dp[j] > dp[maxPosi])
					maxPosi = j;
			}
		}
		vector <int> ans;
		ans.emplace_back (nums[maxPosi]);
		while (dp[maxPosi] != 1) {
			for (int i = maxPosi - 1; ~i; --i) {
				if (nums[maxPosi] % nums[i])
					continue;
				if (dp[maxPosi] != dp[i] + 1)
					continue;
				maxPosi = i;
				ans.emplace_back (nums[maxPosi]);
				break;
			}
		}
		reverse (ans.begin(), ans.end());
		return ans;
	}
};