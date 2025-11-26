class Solution {
public:
	vector<int> maximumSubarrayXor (vector<int>& nums,
	                                vector<vector<int>>& queries) {
		// ans and length two dps are required
		int n = nums.size();
		vector<vector<int>> xo (n + 2, vector<int> (n + 2)), ans (n + 2,
		        vector<int> (n + 2));
		for (int i = 1; i <= n; i++) {
			xo[i][i] = ans[i][i] = nums[i - 1];
		}
		for (int l = 2; l <= n; l++)
			for (int i = 1; i + l - 2 <= n and i + 1 <= n; i++) {
				xo[i][i + l - 1] = xo[i + 1][i + l - 1] ^ xo[i][i + l - 2];
				ans[i][i + l - 1] = max ({ans[i][i + l - 2], xo[i][i + l - 1], ans[i + 1][i + l - 1]});
			}
		vector <int> V;
		for (auto v : queries) {
			V.emplace_back (ans[v[0] + 1][v[1] + 1]);
		}
		return V;
	}
};