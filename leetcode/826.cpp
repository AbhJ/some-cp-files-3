class Solution {
public:
	int maxProfitAssignment (vector<int>& difficulty, vector<int>& profit,
	                         vector<int>& worker) {
		// for every difficulty what matters is max profit till that difficulty
		// job wise: per diff, we need max profit upto that difficulty
		// for every worker, find the max
		// [4, 10], [2, 20], [1, 30], [8, 40], [10, 50]
		// // sort this array and prefix max
		// [1, 30], [2, 30], [3, 30] [8, 40] [10, 50]
		vector <pair<int, int>> difpro;
		for (int i = 0; i < difficulty.size(); i++) {
			difpro.emplace_back (difficulty[i], profit[i]);
		}
		sort (difpro.begin(), difpro.end());
		vector <int> v (1e5 + 1);
		for (int i = 0; i < difficulty.size(); i++) {
			v[difpro[i].first] = difpro[i].second;
		}
		for (int i = 1; i < v.size(); i++) {
			v[i] = max (v[i], v[i - 1]);
		}
		int ans = 0;
		for (auto i : worker) {
			ans += v[i];
		}
		return ans;
	}
};