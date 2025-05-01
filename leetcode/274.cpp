class Solution {
public:
	int hIndex (vector<int>& citations) {
		int l = 0, r = citations.size(), m;
		while (l < r) {
			m = (l + r + 1) / 2;
			int cnt = 0;
			for (auto i : citations)
				if (i >= m)
					cnt++;
			if (cnt >= m)
				l = m;
			else
				r = m - 1;
		}
		return l;
	}
};