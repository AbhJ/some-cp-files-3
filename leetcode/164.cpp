class Solution {
public:
	int maximumGap (vector<int> &nums) {
		int mi = *min_element (nums.begin(), nums.end());
		int ma = *max_element (nums.begin(), nums.end());
		if (nums.size() < 2)
			return 0;
		int avgGap = (ma - mi + nums.size() - 2) / (nums.size() - 1);
		vector<int> minBuck (nums.size(), 1e9 + 1), maxBuck (nums.size(), - 1);
		if (!avgGap)
			return avgGap;
		for (int num : nums) {
			int i = (num - mi) / avgGap;
			minBuck[i] = min (minBuck[i], num);
			maxBuck[i] = max (maxBuck[i], num);
		}
		/*
		 * As the maximum gap cant be smaller than the average gap
		 * we always expect the maximum gap to occur across buckets
		 * of size equal to the average gap in the array.
		 */
		int ans = 0, last = mi;
		for (int i = 0; i < nums.size(); i++)
			if (minBuck[i] != 1e9 + 1) {
				ans = max (ans, minBuck[i] - last);
				last = maxBuck[i];
			}
		return max (ans, ma - last);
	}
};
