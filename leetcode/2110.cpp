class Solution {
public:
	long long getDescentPeriods (vector<int> &prices) {
		int num = 0;
		long long ans = prices.size();
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] == prices[i - 1] - 1) {
				num ++;
				ans += num;
			}
			else
				num = 0;
		}
		return ans;
	}
};
