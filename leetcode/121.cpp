class Solution {
public:
	int maxProfit (vector<int> &A) {
		int ans = 0, minBuy = 1e9;
		for (int i = 0; i < A.size(); i++) {
			ans = max (ans, A[i] - minBuy);
			minBuy = min (A[i], minBuy);
		}
		return ans;
	}
};
