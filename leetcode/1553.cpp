class Solution {
public:
	map <int, int> m;
	int minDays (int n) {
		if (n <= 2)
			return n;
		if (m.count (n))
			return m[n];
		return m[n] = 1 + min ((n % 2) + minDays (n / 2), (n % 3) + minDays (n / 3));
	}
};