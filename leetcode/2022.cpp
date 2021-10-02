class Solution {
public:
	vector<vector<int>> construct2DArray (vector<int>& original, int m, int n) {
		int N = original.size();
		vector<vector<int>> a (m, vector<int> (n));
		if (N != n * m)
			return vector<vector<int>>();
		for (int i = 0; i < N; i++)
			a[i / n][i % n] = original[i];
		return a;
	}
};
