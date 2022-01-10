class Solution {
public:
	int maxProfit (vector<int> &A) {
		if (A.empty())
			return 0;
		int n = A.size(), buy1 = 1e9, buy2 = - 1e9, profit1 = -1e9, profit2 = -1e9, answer = 0;
		// we can have two transactions at most
		// we want to have the maximum profit
		// we don't take negative profit
		for (int i = 0; i < n; i++) {
			profit2 = max (profit2, A[i] + buy2);
			buy2 = max (profit1 - A[i], buy2);
			profit1 = max (profit1, A[i] - buy1);
			buy1 = min (buy1, A[i]);
			answer = max ({profit1, profit2, answer});
		}
		return answer;
	}
};
