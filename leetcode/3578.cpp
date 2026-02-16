class Solution {
public:
	long long M = 1e9 + 7;
	int countPartitions (vector<int>& nums, int k) {
		int n = nums.size();
		vector <long long> dp (n + 1), pre (n + 1);
		dp[0] = pre[0] = 1;
		deque <int> inc, dec;
		for (int i = 0, j = 0; i < n; i++) {
			while (inc.empty() == 0 and nums[inc.back()] > nums[i])
				inc.pop_back();
			inc.push_back (i);
			while (dec.empty() == 0 and nums[dec.back()] < nums[i])
				dec.pop_back();
			dec.push_back (i);
			while (inc.empty() == 0 and dec.empty() == 0
			        and nums[dec.front()] - nums[inc.front()] > k) {
				if (dec.front() == j)
					dec.pop_front();
				if (inc.front() == j)
					inc.pop_front();
				j++;
			}
			dp [i + 1] = (pre[i] - (j != 0 ? pre[j - 1] : 0) + M) % M;
			pre [i + 1] = (pre[i] + dp[i + 1]) % M;
		}
		return dp[n];
	}
};