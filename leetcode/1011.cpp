class Solution {
public:
	int shipWithinDays (vector<int> &weights, int days) {
		int l = 1, r = accumulate (weights.begin(), weights.end(), 0), n = weights.size(), m;
		if (weights.empty())
			return 0;
		while (l < r) {
			m = ((l + r) >> 1);
			int cnt = 1, curCnt = 0, F = 0;
			for (int i = 0; i < n; i++) {
				if (curCnt + weights[i] <= m)
					curCnt += weights[i];
				else
					curCnt = weights[i], cnt++;
				if (weights[i] > m)
					F = 1;
			}
			if (F == 1 or cnt > days)
				l = m + 1;
			else
				r = m;
		}
		return r;
	}
};
