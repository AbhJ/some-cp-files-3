class Solution {
public:
	int fourSumCount (vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
	                  vector<int>& nums4) {
		long long n = nums1.size(), ans = 0;
		map <long long, int> sums;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				long long sumL = - nums1[i] - nums2[j];
				sums[sumL]++;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				long long sumR = nums3[k] + nums4[l];
				ans += sums[sumR];
			}
		}
		return ans;
	}
};