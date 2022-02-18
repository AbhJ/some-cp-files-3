class Solution {
public:
	long long minimumRemoval (vector<int> &beans) {
		sort (beans.begin(), beans.end());
		long long ans = LONG_MAX, sum = accumulate (beans.begin(), beans.end(), 0LL);
		for (int i = 0; i < beans.size(); i++)
			ans = min (ans, sum - beans[i] * ((long long)beans.size() - i));
		return ans;
	}
};
