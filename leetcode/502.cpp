class Solution {
public:
	int findMaximizedCapital (int k, int w, vector<int>& profits,
	                          vector<int>& capital) {
		// we need to sort the projects by capital to find out the best we can afford
		int n = profits.size();
		vector <pair <int, int>> v (n);
		for (int i = 0; i < n; i++) {
			v[i] = make_pair (capital[i], profits[i]);
		}
		sort (v.begin(), v.end());
		int i = 0;
		priority_queue <int> canAfford;
		for (int it = 0; it < k; it++) {
			for (; i < n and v[i].first <= w; i++)
				canAfford.emplace (v[i].second);
			if (canAfford.empty() == 0) {
				w += canAfford.top();
				canAfford.pop();
			}
		}
		return w;
	}
};