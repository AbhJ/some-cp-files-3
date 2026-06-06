class Solution {
public:
	int countKthRoots (int l, int r, int k) {
		if (k == 1)
			return r - l + 1;
		int x = pow (l, 1.0 / k), y = pow (r, 1.0 / k) + 2, cnt = 0;
		for (int i = x; i < y; i++) {
			int num = pow (i, k);
			if (num >= l and num <= r)
				cnt++;
		}
		return cnt;
	}
};