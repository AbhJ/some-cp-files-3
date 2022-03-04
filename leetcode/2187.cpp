class Solution {
public:
	long long minimumTime (vector<int> &time, int totalTrips) {
		long long l = 0, r = 1e14, m;
		while (l < r) {
			m = ((l + r) >> 1);
			long long ans = 0;
			for (int tim : time)
				ans += m / tim;
			if (ans >= totalTrips)
				r = m;
			else
				l = m + 1;
		}
		return r;
	}
};
