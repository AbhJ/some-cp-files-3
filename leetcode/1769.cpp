class Solution {
public:
	vector<int> minOperations (string boxes) {
		int n = boxes.length(), lc = 0, rc = 0, lcs = 0, rcs = 0;
		vector <int> ans (n);
		for (int i = 0; i < n; i++) {
			ans[i] += lcs;
			lc += boxes[i] - '0';
			lcs += lc;
		}
		for (int i = n - 1; ~i; i--) {
			ans[i] += rcs;
			rc += boxes[i] - '0';
			rcs += rc;
		}
		return ans;
	}
};