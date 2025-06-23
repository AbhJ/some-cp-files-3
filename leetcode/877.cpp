class Solution {
public:
	int f (vector <vector <int>> & dp, vector<int>& piles, bool turn, int l,
	       int r) {
		// it calculates Alice - Bob wealth
		if (l > r)
			return 0;
		if (~ dp[l][r])
			return dp[l][r];
		if (turn == true)
			return dp[l][r] = max (piles[l] + f (dp, piles, false, l + 1, r),
			                       piles[r] + f (dp, piles, false, l, r - 1));
		return dp[l][r] = min (- piles[l] + f (dp, piles, false, l + 1, r),
		                       - piles[r] + f (dp, piles, false, l, r - 1));
	}
	bool stoneGame (vector<int>& piles) {
		vector <vector <int>> dp (piles.size(), vector <int> (piles.size(), - 1));
		// left index, turn, right index
		return f (dp, piles, 0, 0, piles.size() - 1);
	}
};