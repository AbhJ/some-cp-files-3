class Solution {
public:
	int canCompleteCircuit (vector<int>& gas, vector<int>& cost) {
		int n = gas.size(), cnt = 0, cur = 0;
		for (int i = 0; i < n; i++)
			gas[i] -= cost[i];
		for (int i = 0; i < 2 * n; i++) {
			cur += gas[i % n];
			cnt++;
			if (cur >= 0 and cnt == n)
				return (i + 1) % n;
			// ended at i, so started at i - n + 1
			if (cur < 0) {
				cnt = 0;
				cur = 0;
			}
		}
		return - 1;
	}
};