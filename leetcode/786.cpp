class Solution {
public:
	int n = 0, d = 0;

	int f (double m, vector<int>& v) {
		int cnt = 0;
		double f_max = -1;
		for (int i = 0, j = 1; i < (int)v.size() - 1; i++) {
			while (j < (int)v.size() && v[i] > m * v[j])
				j++;
			if ((int)v.size() == j) break;
			cnt += (v.size() - j);
			double cur_f = (double)v[i] / v[j];
			if (cur_f > f_max) {
				f_max = cur_f;
				n = v[i];
				d = v[j];
			}
		}
		return cnt;
	}

	vector<int> kthSmallestPrimeFraction (vector<int>& v, int k) {
		double l = 0, r = 1.0, m;
		while (l < r) {
			m = (l + r) / 2;
			int total = f (m, v);
			if (total == k)
				return {n, d};
			else if (total > k)
				r = m;
			else
				l = m;
		}
		return {};
	}
};