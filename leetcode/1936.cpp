class Solution {
public:
	int addRungs(vector<int>& rungs, int dist) {
		int cnt = (rungs[0] - 1) / dist;
		for (int i = 0; i < (int)rungs.size() - 1; i++)
			cnt += (rungs[i + 1] - rungs[i] - 1) / dist;
		return cnt;
	}
};