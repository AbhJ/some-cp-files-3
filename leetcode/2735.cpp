class Solution {
public:
	long long minCost (vector<int>& nums, int x) {
		int n = nums.size();
		long long minAns = 1e18;
		nums.resize (2 * n);
		deque <int> inc;
		for (int i = n; i < 2 * n; i++)
			nums [i] = nums [i % n];
		for (int m = 0; m < n; m++) {
			long long ans = 0;
			for (int i = 0; i < 2 * n; i++) {
				while (inc.empty() == 0 and nums[inc.back()] > nums[i])
					inc.pop_back();
				inc.push_back (i);
				if (i < n)
					continue;
				while (inc.front() < i - m)
					inc.pop_front();
				ans += nums[inc.front()];
			}
			inc.clear();
			minAns = min (ans + (long long) m * x, minAns);
		}
		return minAns;
	}
};