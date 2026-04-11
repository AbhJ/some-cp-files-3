class Solution {
public:
	int countSubarrays (vector<int>& nums, int k) {
		int pos = - 1, ans = 0, del = 0;
		unordered_map <int, int> delFre;
		delFre[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == k) {
				pos = i;
				continue;
			}
			if (~pos) {
				if (nums[i] > k)
					del++;
				else
					del--;
				delFre[del]++;
			}
		}
		del = 0;
		for (int i = pos - 1; ~i; i--) {
			if (nums[i] > k)
				del++;
			else
				del--;
			ans += delFre[- del] + delFre[1 - del];
		}
		return ans + delFre[0] + delFre[1];
	}
};