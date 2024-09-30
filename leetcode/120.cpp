class Solution {
public:

	long long mini (vector<vector<long long>>& dp, vector<vector<int>>& triangle,
	                int lastPos = - 1, int ind = 0) {
		if (ind >= triangle.size())
			return 0;
		if (dp[lastPos + 1][ind] != 1e18)
			return dp[lastPos + 1][ind];
		int le = lastPos;
		int ri = lastPos + 1;
		long long leAns = 1e18, riAns = 1e18;
		if (le > - 1 and le < triangle[ind].size()) {
			leAns = triangle[ind][le] + mini (dp, triangle, le, ind + 1);
		}
		if (ri > - 1 and ri < triangle[ind].size()) {
			riAns = triangle[ind][ri] + mini (dp, triangle, ri, ind + 1);
		}
		return dp[lastPos + 1][ind] = min (leAns, riAns);
	}
	int minimumTotal (vector<vector<int>>& triangle) {
		vector<vector<long long>> dp (triangle.size() + 1,
		                              vector<long long> (triangle.size() + 1, 1e18));
		return mini (dp, triangle);
	}
};