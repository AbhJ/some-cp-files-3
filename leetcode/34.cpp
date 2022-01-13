class Solution {
public:
	vector<int> searchRange (vector<int> &a, int b) {
		int n = a.size(), mi, ma, l = 0, r = n - 1, m;
		// Find leftmost
		while (l < r) {
			m = l + r >> 1;
			if (a[m] >= b)
				r = m;
			else
				l = m + 1;
		}
		mi = r;
		l = 0, r = n - 1;
		while (l < r) {
			m = l + r + 1 >> 1;
			if (a[m] <= b)
				l = m;
			else
				r = m - 1;
		}
		ma = l;
		if (mi < 0 or mi > n - 1 or ma < 0 or ma > n - 1 or a[mi] != b or a[ma] != b)
			return vector<int> {-1, -1};
		return vector<int> {mi, ma};
	}
};
