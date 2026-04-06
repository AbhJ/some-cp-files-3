class Solution {
public:
	int minSizeSubarray (vector<int>& nums, int target) {
		long long sum = accumulate (nums.begin(), nums.end(), 0LL), cnt, tar;
		int n = nums.size(), ans = 1e9;
		cnt = (target / sum) * n;
		tar = target % sum;
		sum = 0;
		map <int, int> m;
		for (int i = 0; i < 2 * n; i++) {
			sum += nums[i % n];
			if (m.count (sum - tar))
				ans = min (i - m[sum - tar], ans);
			m[sum] = i;
		}
		if (ans == 1e9 and tar)
			return - 1;
		return cnt + (ans == 1e9 ? 0 : ans);
	}
};