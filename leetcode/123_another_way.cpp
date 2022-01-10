class Solution {
public:
	int maxProfit (vector<int> &A) {
		if (A.empty())
			return 0;
		long long n = A.size(), buy1 = A[0], buy2 = - 1e18, profit1 = 0, profit2 = 0, answer = 0;
		// we can have two transactions at most
		// we want to have the maximum profit
		// we don't take negative profit
		for (int i = 0; i < n; i++) {
			buy1 = min (buy1, (long long) A[i]);
			profit1 = max (profit1, A[i] - buy1);
			// A[i] - profit1 = buy1
			buy2 = max (profit1 - A[i], buy2);
			profit2 = max (profit2, A[i] + buy2);
			answer = max ({profit1, profit2, answer});
		}
		return answer;
	}
};
