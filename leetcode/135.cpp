class Solution {
public:
	int candy (vector<int>& ratings) {
		int n = ratings.size();
		vector <int> cnt (n, 1);
		for (int i = 1; i < n; i++)
			if (ratings[i] > ratings[i - 1])
				cnt[i] = max (cnt[i], 1 + cnt[i - 1]);
		for (int i = n - 2; ~i; i--)
			if (ratings[i] > ratings[i + 1])
				cnt[i] = max (cnt[i], 1 + cnt[i + 1]);
		return accumulate (cnt.begin(), cnt.end(), 0);
	}
};