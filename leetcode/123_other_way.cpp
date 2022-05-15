class Solution {
public:
	int maxProfit (vector<int> &prices) {
		int profit1 = - 1e9, buy1 = -1e9, buy2 = -1e9, sell1 = -1e9, sell2 = -1e9;
		for (int i = 0; i < prices.size(); i++) {
			sell2 = max (sell2, buy2 + prices[i]);
			buy2 = max (buy2, sell1 - prices[i]);
			sell1 = max (sell1, buy1 + prices[i]);
			buy1 = max (buy1, - prices[i]);
		}
		return max ({0, sell1, sell2});
	}
};
