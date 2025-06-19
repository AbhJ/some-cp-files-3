class Solution {
public:
	map <pair <int, int>, int> dp;
	static bool cmp (vector<int> x, vector<int> y) {
		if (x[1] != y[1])
			return x[1] < y[1];
		return x[0] < y[0];
	}
	int f (int cur, int hei, int wid, int &shelfWidth, vector<vector<int>>& books) {
		if (dp.count (make_pair (cur, wid)))
			return dp[make_pair (cur, wid)];
		if (cur == books.size())
			return hei;
		// keep this book in a new shelf
		int curHei = books[cur][1], curWid = books[cur][0];
		int ans = hei + f (cur + 1, curHei, shelfWidth - curWid, shelfWidth, books);
		// keep this book in existing shelf
		if (wid >= curWid)
			ans = min (ans, f (cur + 1, max (hei, curHei), wid - curWid, shelfWidth,
			                   books));
		return dp[make_pair (cur, wid)] = ans;
	}
	int minHeightShelves (vector<vector<int>>& books, int shelfWidth) {
		int n = books.size();
		return f (0, 0, 0, shelfWidth, books);
	}
};