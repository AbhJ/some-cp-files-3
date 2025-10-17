class Solution {
public:
	long long maximumTotalSum (vector<int>& maximumHeight) {
		int ma = 1e9 + 1;
		long long ans = 0;
		priority_queue <int> q;
		for (int i : maximumHeight)
			q.emplace (i);
		while (q.empty() == 0) {
			int n = q.size();
			ma = min (ma - 1, q.top());
			q.pop();
			if (ma < n)
				return - 1;
			ans += ma;
		}
		return ans;
	}
};