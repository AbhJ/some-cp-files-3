class Solution {
public:
	long long maxSum (vector<int>& nums, int m, int k) {
		map <int, int> ma;
		long long cur = 0, ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ma[nums[i]]++;
			cur += nums[i];
			if (i == k - 1 and ma.size() >= m)
				ans = max (cur, ans);
			if (i < k)
				continue;
			if (ma[nums[i - k]] == 1)
				ma.erase (nums[i - k]);
			else
				ma[nums[i - k]]--;
			cur -= nums[i - k];
			if (ma.size() >= m)
				ans = max (cur, ans);
		}
		return ans;
	}
};