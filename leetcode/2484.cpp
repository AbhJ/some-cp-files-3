class Solution {
public:
	long long countInterestingSubarrays (vector<int>& nums, int modulo, int k) {
		long long n = nums.size(), ans = 0;
		vector <int> v (n + 1);
		map <int, int> ma;
		ma[0] = 1;
		for (int i = 0; i < n; i++) {
			v[i + 1] = v[i] + ((nums[i] % modulo) == k);
			ans += ma[ (v[i + 1] - k + modulo) % modulo];
			ma[v[i + 1] % modulo]++;
		}
		return ans;
	}
};