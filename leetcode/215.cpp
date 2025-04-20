class Solution {
public:
	int findKthLargest (vector<int>& nums, int k) {
		int numLarger, l = *min_element (nums.begin(), nums.end()),
		               r = *max_element (nums.begin(), nums.end()), m;
		while (l < r) {
			m = l + (r - l) / 2;
			numLarger = 0;
			for (auto i : nums)
				numLarger += i > m;
			if (numLarger == k - 1)
				return m;
			if (numLarger < k - 1)
				r = m;
			else
				l = m + 1;
		}
		return r;
	}
};