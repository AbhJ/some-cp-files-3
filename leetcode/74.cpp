class Solution {
public:
	bool searchMatrix (vector<vector<int>> &A, int B) {
		int n = A.size(), m = A[0].size(), il = 0, ir = n - 1, mm;
		while (il < ir) {
			mm = (il + ir) / 2;
			if (A[mm][m - 1] < B)
				il = mm + 1;
			else
				ir = mm;
		}
		int jl = 0, jr = m - 1;
		while (jl < jr) {
			mm = (jl + jr) / 2;
			if (A[ir][mm] < B)
				jl = mm + 1;
			else
				jr = mm;
		}
		return A[ir][jr] == B;
	}
};
