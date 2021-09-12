class Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		vector<long long>curTaka(points[0].size()), lasTaka(points[0].size()); long long answer;
		// curTaka[j] will store the best money I can make picking jth item in the row
		for (vector<int>&row : points) {
			swap(curTaka, lasTaka); curTaka = lasTaka;
			for (int i = 0; i < row.size(); i++)
				curTaka[i] = max((i == 0 ? 0 : curTaka[i - 1] - 1), curTaka[i]);
			for (int i = row.size() - 1; ~i; i--)
				curTaka[i] = max((i == row.size() - 1 ? 0 : curTaka[i + 1] - 1), curTaka[i]);
			answer = 0;
			for (int i = 0; i < row.size(); i++)
				curTaka[i] += row[i], answer = max(answer, curTaka[i]);
			// one item per row is allowed
		}
		return answer;
	}
};