class Solution {
public:
	int countStableSubsequences (vector<int>& nums) {
		int odd1 = 0, odd2 = 0, eve1 = 0, eve2 = 0, M = 1e9 + 7;
		// odd1 are all subsequences till now that end with single odd number
		// odd2 are all subsequences till now that end with two odd numbers
		for (auto i : nums) {
			if (i & 1) {
				odd2 += odd1;
				odd1 += (eve1 + eve2) % M + 1;
				// 1 is for the case of singleton subsequence
				odd1 %= M, odd2 %= M;
			}
			else {
				eve2 += eve1;
				eve1 += (odd1 + odd2) % M + 1;
				eve1 %= M, eve2 %= M;
			}
		}
		return ((odd1 + odd2) % M + (eve1 + eve2) % M) % M;
	}
};