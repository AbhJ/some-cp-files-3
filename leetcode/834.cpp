class Solution {
public:
	vector <int> ans, sub;
	vector<vector<int>>a;
	// calculate the subtree array and ans for root at 0
	void dfs (int u, int p = - 1) {
		for (auto v : a[u]) if (v != p) {
				dfs (v, u);
				sub [u] += sub [v];
				ans [u] += ans [v] + sub[v];
			}
	}
	void shift (int u, int p = - 1) {
		int n = ans.size();
		for (auto v : a[u]) if (v != p) {
				ans [v] = ans [u] + n - 2 * sub[v];
				shift (v, u);
			}
	}
	vector<int> sumOfDistancesInTree (int n, vector<vector<int>>& edges) {
		ans.resize (n);
		sub.resize (n, 1);
		a.resize (n);
		for (auto v : edges) {
			a[v[0]].emplace_back (v[1]);
			a[v[1]].emplace_back (v[0]);
		}
		// set root at 0 and calculate ans for 0
		dfs (0);
		// shift roots and calculate ans for rest of the nodes
		// https://leetcode.com/problems/sum-of-distances-in-tree/solutions/1308366/c-solution-using-dfs-with-explanation-o-n-time-complexity
		shift (0);
		return ans;
	}
};