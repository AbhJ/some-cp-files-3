class Solution {
public:
	int maximumWhiteTiles (vector<vector<int>> &tiles, int carpetLen) {
		int n = tiles.size(), ans = 0, cntCover = 0, endCover;
		sort (tiles.begin(), tiles.end());
		int l = 0, r = 0;
		while (r < n) {
			if (l == r or tiles[l][0] + carpetLen - 1 >= tiles[r][1]) {
				//                 we need to increase r
				cntCover += min (carpetLen, tiles[r][1] - tiles[r][0] + 1);
				ans = max (ans, min (cntCover, carpetLen));
				r++;
			}
			else {
				//                 we need to increase l
				endCover = max (0, tiles[l][0] + carpetLen - tiles[r][0]);
				ans = max (ans, min (cntCover + endCover, carpetLen));
				cntCover -= (tiles[l][1] - tiles[l][0] + 1);
				l++;
			}
		}
		return ans;
	}
};
