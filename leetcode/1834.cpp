class Solution {
public:
	vector<int> getOrder (vector<vector<int>>& tasks) {
		int n = tasks.size(), ind = 0;
		for (int i = 0; i < n; i++)
			tasks[i].emplace_back (i);
		sort (tasks.begin(), tasks.end());
		long long curTime = tasks[0][0];
		priority_queue <pair <int, int>> q;
		// time to complete, ind
		vector <int> v;
		while (! (ind == n && q.empty())) {
			while (ind != n && tasks[ind][0] <= curTime) {
				q.emplace (- tasks[ind][1], - tasks[ind][2]);
				ind++;
			}
			if (q.empty()) {
				curTime = tasks[ind][0];
				continue;
			}
			int posi = - q.top().second, tim = - q.top().first;
			curTime += tim;
			q.pop();
			v.emplace_back (posi);
		}
		return v;
	}
};